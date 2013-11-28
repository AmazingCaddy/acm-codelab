#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 130100;

struct SplayTree
{
	int val[maxn];
	int pre[maxn];
	int ch[maxn][2];
	int sz[maxn];
	int rev[maxn];
	int root, n, m;

	void Rotate( int x, int f )
	{
		int y = pre[x];
		Push_down( y );
		Push_down( x );
		ch[y][!f] = ch[x][f];
		if( ch[x][f] ) pre[ ch[x][f] ] = y;
		pre[x] = pre[y];
		if( pre[y] ) ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;
		ch[x][f] = y;
		pre[y] = x;
		Push_up( y );
	}

	void Splay( int x, int goal )
	{
		while( pre[x] != goal )
		{
			if( pre[ pre[x] ] == goal ) Rotate( x, ch[ pre[x] ][0] == x );
			else 
			{
				int y = pre[x], z = pre[y];
				int f = ( ch[z][0] == y );
				if( ch[y][f] == x ) Rotate( x, !f ), Rotate( x, f );
				else Rotate( y, f ), Rotate( x, f );
			}
		}
		if( goal == 0 ) root = x;
	}

    // 把第 k 位的数转到 goal下边
	void RotateTo( int k, int goal )
	{   
		int x = root;
		Push_down( x );
		while( sz[ ch[x][0] ] + 1 != k )
		{
			if( k <= sz[ ch[x][0] ] ) x = ch[x][0];
			else
			{
				k -= ( sz[ ch[x][0] ] + 1 );
				x = ch[x][1];
			}
			//Push_up( x );
			Push_down( x );
		}
		Splay( x, goal );
	}

	void Push_down( int x )
	{
		if( !x ) return;
		if( rev[x] )
		{
			if( ch[x][0] ) rev[ ch[x][0] ] ^= 1;
			if( ch[x][1] ) rev[ ch[x][1] ] ^= 1;
			swap( ch[x][0], ch[x][1] );
			rev[x] = 0;
		}
	}

	void Push_up( int x )
	{
		sz[x] = sz[ ch[x][0] ] + sz[ ch[x][1] ] + 1;
	}

	void init( )
	{
		// 加入两个额外的节点
		pre[0] = sz[0] = 0;
		pre[1] = 0, pre[2] = 1;
		ch[1][1] = 2;
		ch[1][0] = ch[2][1] = 0;
		ch[2][0] = 3;
		sz[1] = n + 2, sz[2] = n + 1;

		n += 3;
		for( int i = 3; i < n; i++ )
		{
			val[i] = i - 2;
			pre[i] = i - 1;
			ch[i][0] = 0;
			ch[i][1] = i + 1;
			rev[i] = 0;
			sz[i] = n - i;
		}
		ch[n-1][1] = 0;
		root = 1;
	}

	void solve( )
	{
		int l, r;
		init( );
		for( int i = 0; i < m; i++ )
		{
			scanf("%d%d",&l,&r);
			RotateTo( l, 0 );
			RotateTo( r + 2, root );
			rev[ ch[ ch[root][1] ][0] ] ^= 1;
		}
	}

	void output( )
	{
		n -= 1;
		for( int i = 2; i < n; i++ )
		{
			RotateTo( i, 0 );
			if( i != 2 ) printf(" "); 
			printf("%d",val[root]);
		}
		printf("\n");
	}

}spt;

int main(int argc, char *argv[])
{
	scanf("%d%d",&spt.n,&spt.m);
	spt.solve( );
	spt.output( );
	return 0;
}
