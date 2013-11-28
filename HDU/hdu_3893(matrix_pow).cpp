/*
	author: AmazingCaddy
	time:	2011/8/1  12:56
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

//typedef __int64 ll;
typedef long long ll;

const int maxn = 11;
const int mod = 112233;
const int gen[ ][ maxn ] =	{
								{ 3, 3, 2, 2, 2, 3, 3, 2, 2, 2, 3 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
								{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
								{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
								{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
								{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
								{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
								{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
							};
int vec[ ] = { 4, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 };

void matrix_mul( ll a[ ][ maxn ], ll b[ ][ maxn ] )
{
	ll c[ maxn ][ maxn ];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < maxn; i++ )
		for( int j = 0; j < maxn; j++ )
			for( int k = 0; k < maxn; k++ )
				c[ i ][ j ] = c[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ];
	for( int i = 0; i < maxn; i++ )
		for( int j = 0; j < maxn; j++ )
			a[ i ][ j ] = c[ i ][ j ] % mod;
}

int matrix_pow( ll a[ ][ maxn ], int b )
{
	ll I[ maxn ][ maxn ];
	memset( I, 0, sizeof( I ) );
	for( int i = 0; i < maxn; i++ ) I[ i ][ i ] = 1;
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a );
		matrix_mul( a, a );
		b >>= 1;
	}
	ll ans = 0;
	for( int i = 0; i < maxn; i++ )
		for( int j = 0; j < maxn; j++ )
			ans += I[ i ][ j ] * vec[ j ];
	return ans % mod;
}

int main(int argc, char *argv[])
{
	int n;
	ll a[ maxn ][ maxn ];
	while( scanf( "%d", &n ) != EOF )
	{
		if( n & 1 )
		{
			n >>= 1;
			for( int i = 0; i < maxn; i++ )
				for( int j = 0; j < maxn; j++ )
					a[ i ][ j ] = gen[ i ][ j ];
			int ans = matrix_pow( a, n );
			printf( "%d\n", ans );
		}
		else
		{
			printf( "0\n" );
		}
	}
	return 0;
}
