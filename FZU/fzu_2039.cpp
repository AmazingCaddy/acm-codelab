/*
    author: AmazingCaddy
    time: 28/05/2011 13:17:39 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 104;
int g[ maxn ][ maxn ];
int vis[ maxn ], cx[ maxn ], cy[ maxn ], sy[ maxn ];
int n, m;

int DFS( int u )
{
	for( int v = 1; v <= m; v++ )
	{
		if( g[ u ][ v ] && !sy[ v ] )
		{
			sy[ v ] = 1;
			if( !cy[ v ] || DFS( cy[ v ] ) )
			{
				cx[ u ] = v;
				cy[ v ] = u;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch( )
{
	int ret = 0;
	memset( cx, 0, sizeof( cx ) );
	memset( cy, 0, sizeof( cy ) );
	for( int i = 1; i <= n; i++ )
	{
		if( !cx[ i ] )
		{
			memset( sy, 0, sizeof( sy ) );
			ret += DFS( i );
		}
	}
	return ret;
}

int main( int ac, char * av[ ] )
{
	int cas, q;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		for( int i = 0; i < maxn; i++ )
			for( int j = 0; j < maxn; j++ )
				g[ i ][ j ] = 1;
		scanf( "%d%d%d", &n, &m, &q );
		int a, b;
		for( int i = 0; i < q; i++ )
		{
			scanf( "%d%d", &a, &b );
			g[ a ][ b ] = 0;
		}
		int ans = MaxMatch( );
		printf( "Case %d: %d\n", t, ans );
	}
	return 0;
}
