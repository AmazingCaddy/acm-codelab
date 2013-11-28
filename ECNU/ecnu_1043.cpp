/*
ID: ecnuwbw1
PROG: ecnu 1043
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 303;
const int maxm = 1000030;

int a[ maxn ], b[ maxm ], vis[ maxm ];

int main(int argc, char *argv[])
{
	int cas, n, tmp;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
			scanf( "%d", &a[ i ] );
		sort( a, a + n );
		memset( vis, 0, sizeof( vis ) );
		for( int i = n - 1; i >= 0; i -- )
		{
			for( int j = 0; j < i; j++ )
			{
				if( ( tmp = a[ i ] - a[ j ] ) < n ) break;
				else vis[ tmp ] = 1;
			}
		}
		for( int i = n; ; i++ )
		{
			if( vis[ i ] ) continue;
			memset( b, 0, i * 4 );
			int flag = 1;
			for( int j = 0; j < n; j++ )
			{
				if( ++b[ a[ j ] % i ] > 1 )
				{
					flag = 0;
					break;
				}
			}
			if( flag ) { printf( "%d\n", i ); break; }
		}
	}
	return 0;
}
