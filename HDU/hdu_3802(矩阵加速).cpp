/*
	author: AmazingCaddy
	time: 2011/3/29  19:17
	X1 + Y1 = 2*(a + b)
	X1 * Y1 = (a - b)^2
	X1 Y1 是方程 Z^2 - 2*(a + b)*Z + (a - b)^2 = 0 的两根
	Zn+1 = 2*(a + b)Zn - (a - b)^2*Zn-1
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
typedef __int64 ll;

ll pow_mod( ll a, ll b, ll p )
{
	ll ans = 1, d = a % p;
	while( b )
	{
		if( b & 1 ) ans = ans * d % p;
		d = d * d % p;
		b >>= 1;
	}
	return ans;
}

void matrix_mul( ll a[ ][ 2 ], ll b[ ][ 2 ], ll p )
{
	ll c[ 2 ][ 2 ];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			for( int k = 0; k < 2; k++ )
				c[ i ][ j ] = ( c[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ] ) % p;
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			a[ i ][ j ] = c[ i ][ j ];
}

void matrix_mod( ll a[ ][ 2 ], ll b, ll p )
{
	ll I[ 2 ][ 2 ] = { { 1, 0 }, { 0, 1 } };
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a, p );
		matrix_mul( a, a, p );
		b >>= 1;
	}
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			a[ i ][ j ] = I[ i ][ j ];
}

int main(int argc, char *argv[])
{
	int cas;
	ll A, B, N, P, ans;
	ll a[ 2 ][ 2 ];
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%I64d %I64d %I64d %I64d", &A, &B, &N, &P );
		if( pow_mod( A, ( P - 1 ) / 2, P ) != 1 || pow_mod( B, ( P - 1 ) / 2, P ) != 1 )
			ans = 0;
		else
		{
			a[ 0 ][ 0 ] = a[ 0 ][ 1 ] = a[ 1 ][ 0 ] = 1; a[ 1 ][ 1 ] = 0;
			matrix_mod( a, N - 1, P - 1 );
			ll len = ( a[ 0 ][ 0 ] + a[ 0 ][ 1 ] ) % ( P - 1 );
			a[ 0 ][ 0 ] = 2 * ( A + B ) % P;
			a[ 0 ][ 1 ] = ( ( B - A ) * ( A - B ) % P + P ) % P;
			a[ 1 ][ 0 ] = 1, a[ 1 ][ 1 ] = 0;
			matrix_mod( a, len - 1, P );
			ans = 4 * ( 2 * ( A + B ) % P * a[ 0 ][ 0 ] % P + a[ 0 ][ 1 ] * 2 ) % P;
		}
		printf( "%I64d\n", ans );
	}
	return 0;
}
