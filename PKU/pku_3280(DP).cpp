/*
	author: AmazingCaddy
	time: 2011/5/9  17:28
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

const int maxn = 2004;
int dp[ maxn ][ maxn ];
int cost[ maxn ];
char buf[ maxn ];

int Min( int a, int b ) { return ( a < b ? a : b ); }

int main(int argc, char *argv[])
{
	int m, n, a, b;
	char ch[ 3 ];
	scanf( "%d%d", &m, &n );
	scanf( "%s", buf );
	for( int i = 0; i < m; i++ )
	{
		scanf( "%s%d%d", ch, &a, &b );
		cost[ ch[ 0 ] - 'a' ] = Min( a, b );
	}
	for( int i = 0; i < n; i++ ) dp[ i ][ i ] = 0;
	for( int i = 2; i <= n; i++ )
	{
		for( int j = 0; j + i <= n; j++ )
		{
			int t = j + i - 1;
			if( buf[ j ] == buf[ t ] )
				dp[ j ][ t ] = dp[ j + 1 ][ t - 1 ];
			else
			{
				dp[ j ][ t ] = Min( dp[ j + 1 ][ t ] + cost[ buf[ j ] - 'a' ], 
					dp[ j ][ t - 1 ] + cost[ buf[ t ] - 'a' ] );
			}
		}
	}
	printf( "%d\n", dp[ 0 ][ n - 1 ] );
	return 0;
}
