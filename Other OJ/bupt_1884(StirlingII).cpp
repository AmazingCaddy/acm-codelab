/*
	author: AmazingCaddy
	time: 2011/2/28  17:48
	ans = S( n, m ) * m!
	    = sigma( (-1)^k * C(m,k) * (m-k)^n ) { 0 <= k <= m-1 }
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

const int maxn = 1005;
const ll P = 99991;
ll C[ maxn ][ maxn ];

void init( )
{
	C[ 1 ][ 0 ] = C[ 1 ][ 1 ] = 1;
	for( int i = 2; i < maxn; i++ )
	{
		C[ i ][ 0 ] = C[ i ][ i ] = 1;
		for( int j = 1; j < i; j++ )
		{
			C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
			C[ i ][ j ] %= P;
		}
	}
}

ll pow_mod( ll a, ll b )
{
	ll ans = 1, d = a % P;
	while( b )
	{
		if( b & 1 ) ans = ans * d % P;
		d = d * d % P;
		b >>= 1;
	}
	return ans;
}

ll MOD( ll a, ll p )
{
	return ( ( a % p + p ) % p );
}

ll cal( int n, int m )
{
	ll sum = 0;
	for( int i = 0; i < m; i++ )
	{
		sum = MOD( sum + ( i % 2 ? -1 : 1 ) * C[ m ][ i ] * pow_mod( m - i, n ), P );
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int n, m;
	init( );
	while( scanf( "%d%d", &n, &m ) != EOF )
	{
		if( m > n ) { printf( "0\n" ); continue; }
		printf( "%lld\n", cal( n, m ) );
	}
	return 0;
}
