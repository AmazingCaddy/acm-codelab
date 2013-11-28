/*
	author: AmazingCaddy
	time: 2011/5/21  18:19
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
const int maxn = 10004;

int f[ maxn ], g[ maxn ];

int check( int n )
{
	if( n == 1 ) return 1;
	for( int i = 0; i < n - 1; i++ )
		if( f[ i + 1 ] - f[ i ] < 2 ) return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	int cas, n, m1, m2;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d", &m1 );
		for( int i = 0; i < m1; i++ )
			scanf( "%d", &f[ i ] );
		scanf( "%d", &m2 );
		n = m1 + m2;
		for( int i = m1; i < n; i++ )
			scanf( "%d", &f[ i ] );
		sort( f, f + n );
		while( 1 )
		{
			if( n > 1 )
			{
				if( f[ 0 ] == 2 && f[ 1 ] == 2 )
					f[ 0 ] = 1;
				else if( f[ 0 ] == 1 && f[ 1 ] == 1 )
					f[ 1 ] = 2;
			}
			int len = 0, flag = 0;
			for( int i = 0; i < n; i++ )
			{
				if( flag ) { g[ len++ ] = f[ i ]; continue; }
				if( f[ i ] == 1 ) g[ len++ ] = f[ i ];
				if( f[ i ] > 1 )
				{
					if( i < n - 1 && f[ i ] == f[ i + 1 ] )
					{
						g[ len++ ] = f[ i ] - 2;
						g[ len++ ] = f[ i ] - 1;
						flag = 1;
					}
					else g[ len++ ] = f[ i ];
				}
			}
			n = len;
			if( n > 1 )
			{
				if( g[ 0 ] == 2 && g[ 1 ] == 2 )
					g[ 0 ] = 1;
				else if( g[ 0 ] == 1 && g[ 1 ] == 1 )
					g[ 1 ] = 2;
			}
			sort( g, g + n );
			len = 0, flag = 0;
			for( int i = n - 1; i >= 0; i-- )
			{
				if( flag ) { f[ len++ ] = g[ i ]; continue; }
				if( i > 0 && g[ i ] == g[ i - 1 ] + 1 )
				{
					f[ len++ ] = g[ i ] + 1;
					flag = 1;
					i--;
				}
				else f[ len++ ] = g[ i ];
			}
			n = len;
			sort( f, f + n );
			if( check( n ) ) break;
		}
		printf( "Case %d:\n", t );
		printf( "%d", n );
		for( int i = 0; i < n; i++ )
			printf( " %d", f[ i ] );
		printf( "\n" );
	}
	return 0;
}
