/*
	author: AmazingCaddy
	time:	2011/8/10   15:17
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

typedef long long ll;

const int maxn = 1 << 15;

ll L[ maxn ], M[ maxn ];

int func( ll x )
{
	x = ( ( x & 0x5555555555555555LL ) + ( ( x >> 1 ) & 0x5555555555555555LL ) );
	x = ( ( x & 0x3333333333333333LL ) + ( ( x >> 2 ) & 0x3333333333333333LL ) );
	x = ( ( x & 0x0f0f0f0f0f0f0f0fLL ) + ( ( x >> 4 ) & 0x0f0f0f0f0f0f0f0fLL ) );
	x = ( ( x & 0x00ff00ff00ff00ffLL ) + ( ( x >> 8 ) & 0x00ff00ff00ff00ffLL ) );
	x = ( ( x & 0x0000ffff0000ffffLL ) + ( ( x >> 16 ) & 0x0000ffff0000ffffLL ) );
	x = ( ( x & 0x00000000ffffffffLL ) + ( ( x >> 32 ) & 0x00000000ffffffffLL ) );
	return x;
}

ll a[ 16 ];

int main(int argc, char *argv[])
{
	int cas, n;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		printf( "Case #%d: ", t );
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
			scanf( "%I64d", &a[ i ] );
		L[ 0 ] = ( 1LL << 60 ) - 1;
		M[ 0 ] = -1;
		ll ans = 0;
		for( int i = 0; i < n; i++ )
		{
			int m = 1 << i;
			for( int j = 0; j < m; j++ )
			{
				L[ m | j ] = ( L[ j ] & a[ i ] );
				M[ m | j ] = -M[ j ] * 2;
				ans -= M[ j ] * ( 1LL << func( L[ m | j ] ) );
			}
		}
		printf( "%I64d\n", ans );
	}
	return 0;
}
