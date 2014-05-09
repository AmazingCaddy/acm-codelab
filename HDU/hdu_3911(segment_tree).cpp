/*
	author: AmazingCaddy
	time:	2011/8/13  16:10
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int maxn = 100100;

struct node
{
	int l, r;					
	int bmax, bl, br;	//	最长的连续黑色
	int wmax, wl, wr;	//	最长的连续白色
	bool flag;			//	标记是否取反
};

node tree[ maxn << 2 ];
int f[ maxn ];

void Swap( int v )
{
	swap( tree[ v ].bmax, tree[ v ].wmax );
	swap( tree[ v ].bl, tree[ v ].wl );
	swap( tree[ v ].br, tree[ v ].wr );
}

void push_down( int sonv )
{
	tree[ sonv ].flag = !tree[ sonv ].flag;
	Swap( sonv );
}

void push_up( int v )
{
	//	黑色部分
	//	总长度
	tree[ v ].bmax = max( tree[ v << 1 ].bmax, tree[ v << 1 | 1 ].bmax );
	tree[ v ].bmax = max( tree[ v ].bmax, tree[ v << 1 ].br + tree[ v << 1 | 1 ].bl );
	//	左端
	if( tree[ v << 1 ].bl == tree[ v << 1 ].r - tree[ v << 1 ].l )
		tree[ v ].bl = tree[ v << 1 ].bl + tree[ v << 1 | 1 ].bl;
	else tree[ v ].bl = tree[ v << 1 ].bl;
	//	右端
	if( tree[ v << 1 | 1 ].br == tree[ v << 1 | 1 ].r - tree[ v << 1 | 1 ].l ) 
		tree[ v ].br = tree[ v << 1 ].br + tree[ v << 1 | 1 ].br;
	else tree[ v ].br = tree[ v << 1 | 1 ].br;

	//	白色部分
	//	总长度
	tree[ v ].wmax = max( tree[ v << 1 ].wmax, tree[ v << 1 | 1 ].wmax );
	tree[ v ].wmax = max( tree[ v ].wmax, tree[ v << 1 ].wr + tree[ v << 1 | 1 ].wl );
	//	左端
	if( tree[ v << 1 ].wl == tree[ v << 1 ].r - tree[ v << 1 ].l ) 
		tree[ v ].wl = tree[ v << 1 ].wl + tree[ v << 1 | 1 ].wl;
	else tree[ v ].wl = tree[ v << 1 ].wl;
	//	右端
	if( tree[ v << 1 | 1 ].wr == tree[ v << 1 | 1 ].r - tree[ v << 1 | 1 ].l ) 
		tree[ v ].wr = tree[ v << 1 ].wr + tree[ v << 1 | 1 ].wr;
	else tree[ v ].wr = tree[ v << 1 | 1 ].wr;
}

void make_tree( int v, int l, int r )
{
	tree[ v ].l = l;
	tree[ v ].r = r;
	tree[ v ].flag = false;
	if( l + 1 != r )
	{
		int mid = ( l + r ) >> 1;
		make_tree( v << 1, l, mid );
		make_tree( v << 1 | 1, mid, r );
		push_up( v );
	}
	else
	{
		if( f[ l ] )//	黑色
		{
			tree[ v ].bmax = tree[ v ].bl = tree[ v ].br = 1;
			tree[ v ].wmax = tree[ v ].wl = tree[ v ].wr = 0;
		}
		else		//	白色
		{
			tree[ v ].wmax = tree[ v ].wl = tree[ v ].wr = 1;
			tree[ v ].bmax = tree[ v ].bl = tree[ v ].br = 0;
		}
	}
}

void update( int v, int l, int r )
{
	if( tree[ v ].l == l && tree[ v ].r == r )
	{
		tree[ v ].flag = !tree[ v ].flag;
		Swap( v );
		return;
	}
	
	if( tree[ v ].flag )
	{
		tree[ v ].flag = false;
		push_down( v << 1 );
		push_down( v << 1 | 1 );
	}

	int mid = ( tree[ v ].l + tree[ v ].r ) >> 1;
	if( r <= mid ) update( v << 1, l, r );
	else if( l >= mid ) update( v << 1 | 1, l, r );
	else
	{
		update( v << 1, l, mid );
		update( v << 1 | 1, mid, r );
	}
	push_up( v );
}

int query( int v, int l, int r )
{
	if( tree[ v ].l == l && tree[ v ].r == r )
	{
		return tree[ v ].bmax;
	}
	
	if( tree[ v ].flag )
	{
		tree[ v ].flag = false;
		push_down( v << 1 );
		push_down( v << 1 | 1 );
	}

	int mid = ( tree[ v ].l + tree[ v ].r ) >> 1;
	if( r <= mid ) return query( v << 1, l, r );
	if( l >= mid ) return query( v << 1 | 1, l, r );
	int t1 = max( query( v << 1, l, mid ), query( v << 1 | 1, mid, r ) );
	int t2 = min( tree[ v << 1 ].br, mid - l ) + min( tree[ v << 1 | 1 ].bl, r - mid );
	return max( t1, t2 );
}

int main(int argc, char *argv[])
{
//	freopen( "BAW.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int n, m;
	int op, a, b;
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%d", &f[ i ] );
		make_tree( 1, 0, n );
		scanf( "%d", &m );
		for( int i = 0; i < m; i++ )
		{
			scanf( "%d%d%d", &op, &a, &b );
			if( op ) update( 1, a - 1, b );
			else printf( "%d\n", query( 1, a - 1, b ) );
		}
	}
	return 0;
}
