/*
	author: AmazingCaddy
	time: 2011/3/28  21:05
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
const int maxn = 45000;
int vis[ maxn ], p[ maxn ];
int plen, flen;
ll a[ 32 ], b[ 32 ];
void prime( )
{
	int i, j, k;
	plen = 0;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			p[ plen++ ] = i;
			if( k < maxn ) for( j = k; j < maxn; j += i ) vis[ j ] = 1;
		}
	}
}

void factor( ll n )
{
	flen = 0;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( !( n % p[ i ] ) )
		{
			for( b[ flen ] = 0; n % p[ i ] == 0; n /= p[ i ], b[ flen ]++ );
			a[ flen ++ ] = p[ i ];
		}
	}
	if( n > 1 ) a[ flen ] = n, b[ flen ++ ] = 1;
}

ll mod( ll x, ll n ) { return ( x % n + n ) % n; }

void matrix_mul( ll a[ ][ 2 ], ll b[ ][ 2 ], ll p )
{
	ll c[ 2 ][ 2 ] = { 0, 0, 0, 0 };
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			for( int k = 0; k < 2; k++ )
				c[ i ][ j ] = c[ i ][ j ] + ( a[ i ][ k ] * b[ k ][ j ] ) % p;
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			a[ i ][ j ] = c[ i ][ j ] % p;
}

ll F( ll b, ll p )
{
	ll I[ 2 ][ 2 ] = { { 1, 0 }, { 0, 1 } };
	ll a[ 2 ][ 2 ] = { { 1, 1 }, { 1, 0 } };
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a, p );
		matrix_mul( a, a, p );
		b >>= 1;
	}
	return ( I[ 0 ][ 0 ] + I[ 0 ][ 1 ] ) % p;
}

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

ll Inv( ll a, ll n )
{
	return pow_mod( a, n - 2, n );
}

// a^x=b(mod n) n is a prime
ll log_mod( ll a, ll b, ll n )
{
	ll m, v, e, i;
	map< ll, ll > x;

	m = ( ll )ceil( sqrt( n * 1.0 ) );
	v = Inv( pow_mod( a, m, n ), n );

	e = 1; x[ 1 ] = 0;
	for( i = 1; i < m; i++ ) 
	{
		e = e * a % n;
		if( !x.count( e ) ) x[ e ] = i;
	}
	for( i = 0; i < m; i++ )
	{
		if( x.count( b ) ) return i * m + x[ b ];
		b = b * v % n;
	}
}

ll fac[ 100000 ];
int cnt;

void DFS( int dep, ll tem )
{
	if( dep == flen ) 
	{
		fac[ cnt++ ] = tem;
		return;
	}
	ll tmp = 1;
	for( int i = 0; i <= b[ dep ]; i++ )
	{
		DFS( dep + 1, tem * tmp );
		tmp *= a[ dep ];
	}
}

ll find_g( ll p )   // ±©Á¦ÕÒÔ­¸ù
{
	ll phi = p - 1;
	cnt = 0;
	factor( phi );
	DFS( 0, 1 );
	int k;
	for( int i = 2; ; i++ )
	{
		for( k = 0; k < cnt; k++ )
			if( fac[ k ] != phi && pow_mod( i, fac[ k ], p ) == 1 )
				break;
		if( k == cnt ) return i;
	}
	return -1;
}
map< ll, ll > dict;

int main(int argc, char *argv[])
{
	prime( );
	int cas;
	ll ans, A, B, N, P;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%I64d%I64d%I64d%I64d", &A, &B, &N, &P );
		if( pow_mod( A, ( P - 1 ) / 2, P ) != 1 || pow_mod( B, ( P - 1 ) / 2, P ) != 1 )
			ans = 0;
		else
		{
			ll g = find_g( P );
			ll x = log_mod( g, A, P ) / 2;
			ll y = log_mod( g, B, P ) / 2;
			A = pow_mod( g, x, P );
			B = pow_mod( g, y, P );
			ll len = 2 * F( N - 1, P - 1 ) % ( P - 1 );
			ans = 4 * ( pow_mod( A + B, len, P ) + pow_mod( mod( A - B, P ), len, P ) ) % P;
		}
		printf( "%I64d\n", ans );
	}
	return 0;
}
