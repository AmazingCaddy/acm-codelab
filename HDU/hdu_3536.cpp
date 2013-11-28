#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 300010
#define NONE 0 
using namespace std;

struct node
{
	int l,r,mark;
}tree[4*MAXN];
bool c[1005];

void make_tree( int l, int r, int v )
{
	int mid;
	tree[v].l = l;
	tree[v].r = r;
	tree[v].mark = NONE;
	mid=( l + r ) >> 1;
	if ( l != r )
	{
		make_tree( l, mid, v<<1 );
		make_tree( mid + 1, r, (v<<1)+1 );
	}
}

void change( int l, int r, int color, int v )
{  
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	//if( r<tree[v].l || l>tree[v].r ) return ;
	if( l == tree[v].l && r == tree[v].r )
	{
		tree[v].mark = color;
		return ;
	}
	if( tree[v].mark != NONE && tree[v].l != tree[v].r )
	{
		tree[v<<1].mark = tree[v].mark;
		tree[(v<<1)+1].mark = tree[v].mark;
		tree[v].mark = NONE;
	}
	if( r <= mid ) change( l, r, color, v<<1 );
	else if( l > mid ) change( l, r, color, (v<<1)+1 );
	else 
	{
		change( l, mid, color, v<<1 );
		change( mid + 1, r, color, (v<<1)+1 );
	}
}

void check( int l, int r, int v )
{
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	if( tree[v].mark > 0 )
	{
		c[tree[v].mark] = true;
		return ;
	}
	if( tree[v].l != tree[v].r )
	{
		if( r <= mid ) check( l, r, v<<1 );
		else if( l > mid ) check( l, r, (v<<1)+1 );
		else
		{  
			check( l, mid, v<<1 );
			check( mid + 1, r, (v<<1)+1 );
		}
	}
}

int cnt( )
{
	int i;
	int s = 0;
	for( i = 1; i <= 1000; i++ )
		if( c[i] )s++;
	return s;
}

int main( )
{   
	int R, C, M, n, x1, y1, x2, y2;
	while( scanf("%d%d%d",&R,&C,&M) != EOF )
	{  
		n = R * C;
		make_tree( 1, n, 1 );
		for( int j = 1; j <= M; j++ )
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int off = ( x1 - 1 ) * C; 
			int s = off + y1, e = off + y2;
			for( int i = x1; i <= x2; i++ )
			{
				change( s, e, j, 1 );
				s += C, e += C;
			}
			//check( 1, n, 1 );
		}
		memset( c, false, sizeof( c ) );
		check( 1, n, 1 );
		int ans = M - cnt( );
		printf("%d\n",ans);
	}
	return 0;
}
