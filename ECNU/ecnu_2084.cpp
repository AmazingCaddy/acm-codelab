/*
	author: AmazingCaddy
	time: 2011/4/29  20:38
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

int dp1[ maxn ], dp2[ maxn ];
int a[ maxn ];
int Max( int a, int b ) { return ( a > b ? a : b ); }
int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 1; i <= n; i++ )
			scanf( "%d", &a[ i ] );
		memset( dp1, 0, sizeof( dp1 ) );
		memset( dp2, 0, sizeof( dp2 ) );

		dp1[ 1 ] = 0; dp1[ 2 ] = a[ 2 ];
		for( int i = 3; i <= n; i++ )
			dp1[ i ] = Max( dp1[ i - 2 ], dp1[ i - 3 ] ) + a[ i ];

		dp2[ 1 ] = a[ 1 ];
		for( int i = 3; i < n; i++ )
			dp2[ i ] = Max( dp2[ i - 2 ], dp2[ i - 3 ] ) + a[ i ];

		int ans = 0;
		for( int i = 1; i <= n; i++ )
			ans = Max( ans, Max( dp1[ i ], dp2[ i ] ) );

		printf( "%d\n", ans );
	}
	return 0;
}
