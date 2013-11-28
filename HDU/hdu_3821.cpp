/*
    author: AmazingCaddy
    time: 2011/5/21  18:09
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

const int maxn = 1004;
const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

int g[ maxn ][ maxn ];
int num[ maxn ];
int ans[ maxn * maxn ];

int main( int ac, char * av[ ] )
{
	int cas, n;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				scanf( "%d", &g[ i ][ j ] );
				if( g[ i ][ j ] == 1 ) 
					num[ i ] = j;
			}
		}
		int len = 0;
		for( int i = 0; i < n; i++ )
		{
			int tmp = -1;
			for( int j = 0; j < n; j++ )
			{
				if( num[ j ] == i )
				{
					tmp = j;
					break;
				}
			}
			for( int j = tmp - 1; j >= i; j-- )
			{
				ans[ len++ ] = j;
				swap( num[ j ], num[ j + 1 ] );
			}
		}
		printf( "Case %d: %d\n", t, len );
		for( int i = 0; i < len; i++ )
		{
			if( i ) printf( " " );
			printf( "%d", ans[ i ] );
		}
		printf( "\n" );
	}
	return 0;
}
