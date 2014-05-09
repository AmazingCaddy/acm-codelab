/*
	author: AmazingCaddy
	time: 2011/4/7  20:19
	d[ i ][ v ] 记录 使用了i个 jump 到v的最短距离
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
using namespace std;

const int maxn = 104;
const int inf = 100000000;
int g[ maxn ][ maxn ];
int d[ 12 ][ maxn ];
int vis[ 12 ][ maxn ];
int n;

int dij( int st, int de, int m, int L )
{
	memset( vis, 0, sizeof( vis ) );
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= m; j++ )
			d[ j ][ i ] = inf;

	for( int i = 1; i <= n; i++ )
		d[ 0 ][ i ] = g[ st ][ i ];

	for( int i = 0; i <= m; i++ )
	{
		vis[ i ][ st ] = 1;
		d[ i ][ st ] = 0;

		for( int k = 1; k <= n; k++ )
		{
			if( d[ i ][ k ] > g[ st ][ k ] ) d[ i ][ k ] = g[ st ][ k ];
			if( g[ st ][ k ] <= L ) d[ i + 1 ][ k ] = d[ i ][ st ];
		}	

		for( int j = 1; j < n; j++ )
		{
			int min = inf, p = 0;
			for( int k = 1; k <= n; k++ )
				if( !vis[ i ][ k ] && min > d[ i ][ k ] )
					min = d[ i ][ k ], p = k;
			if( p == 0 ) continue;
			vis[ i ][ p ] = 1;
			for( int k = 1; k <= n; k++ )
			{
				if( !vis[ i ][ k ] && d[ i ][ p ] + g[ p ][ k ] < d[ i ][ k ] )
					d[ i ][ k ] = d[ i ][ p ] + g[ p ][ k ];
				if( g[ p ][ k ] <= L && i + 1 <= m )
					if( d[ i + 1 ][ k ] > d[ i ][ p ] )
						d[ i + 1 ][ k ] = d[ i ][ p ];
			}
		}
	}
	return d[ m ][ de ];
}

int main(int argc, char *argv[])
{
	int cas, A, B, M, L, K;
	int u, v, val;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d %d %d %d %d", &A, &B, &M, &L, &K );
		n = A + B;
		for( int i = 1; i <= n; i++ )
		{
			g[ i ][ i ] = 0;
			for( int j = i + 1; j <= n; j++ )
				g[ i ][ j ] = g[ j ][ i ] = inf;
		}
		for( int i = 0; i < M; i++ )
		{
			scanf( "%d %d %d", &u, &v, &val );
			g[ u ][ v ] = val;
			g[ v ][ u ] = val;
		}

		for( int k = 1; k <= A; k++ )
			for( int i = 1; i <= n; i++ )
				for( int j = 1; j <= n; j++ )
					if( g[ i ][ k ] + g[ k ][ j ] < g[ i ][ j ] )
						g[ i ][ j ] = g[ i ][ k ] + g[ k ][ j ];
		
		int ans = dij( A + B, 1, K, L );

		printf( "%d\n", ans );
	}
	return 0;
}
