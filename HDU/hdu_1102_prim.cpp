/*
	author: AmazingCaddy
	time:	2011/7/11  17:35
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
const int maxn = 104;
const int inf = 0x3fffffff;

int dis[ maxn ], vis[ maxn ];
int g[ maxn ][ maxn ];

int prim( int n )
{
	for( int i = 1; i <= n; i++ )
		dis[ i ] = g[ 1 ][ i ], vis[ i ] = 0;
	dis[ 1 ] = 0, vis[ 1 ] = 1;
	int sum = 0;
	for( int i = 1; i < n; i++ )
	{
		int k = -1, minv = inf;
		for( int j = 1; j <= n; j++ )
			if( !vis[ j ] && dis[ j ] < minv )
				minv = dis[ j ], k = j;
		//printf( "minv = %d, k = %d\n", minv, k );
		sum += minv;
		dis[ k ] = 0;
		vis[ k ] = 1;
		for( int j = 1; j <= n; j++ )
			if( !vis[ j ] && g[ k ][ j ] < dis[ j ] )
				dis[ j ] = g[ k ][ j ];
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 1; i <= n; i++ )
			for( int j = 1; j <= n; j++ )
				scanf( "%d", &g[ i ][ j ] );
		int q, a, b;
		scanf( "%d", &q );
		for( int i = 0; i < q; i++ )
		{
			scanf( "%d%d", &a, &b );
			g[ a ][ b ] = g[ b ][ a ] = 0;
		}
		int ans = prim( n );
		printf( "%d\n", ans );
	}
	return 0;
}
