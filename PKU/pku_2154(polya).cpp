/*
*	author: wwb
*	time: 2011/2/26  19:55
*	ans = sigma(phi(n/i)*n^i)/n = sigma( phi(n/i)*n^(i-1) ) { i|n }
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 32000;
int vis[ maxn ], p[ maxn ];
int a[ 32 ], b[ 32 ];
int plen, flen;

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

void factor( int n )
{
	flen = 0;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{	
			for( b[ flen ] = 0; n % p[ i ] == 0; ++b[ flen ], n /= p[ i ] );
			a[ flen++ ] = p[ i ];
		}
	}
	if( n > 1 ) b[ flen ] = 1, a[ flen++ ] = n;
}

int elur( int n )
{
	int phi = n;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			while( n % p[ i ] == 0 ) n /= p[ i ];
			phi -= phi / p[ i ];
		}
	}
	if( n > 1 ) phi -= phi / n;
	return phi;
}

int ans, n, P;

int pow_mod( int a, int b, int c )
{
	int ans = 1, d = a % c;
	while( b )
	{
		if( b & 1 ) ans = ans * d % c;
		d = d * d % c;
		b >>= 1;
	}
	return ans;
}

void DFS( int dep, int sum )
{
	if( dep == flen )
	{
		ans = ( ans + elur( n / sum ) % P * pow_mod( n, sum - 1, P ) % P ) % P;
		return;
	}
	for( int i = 0, tmp = 1; i <= b[ dep ]; tmp *= a[ dep ], i++ )
		DFS( dep + 1, sum * tmp );
}

int main(int argc, char *argv[])
{
	int cas;
	prime( );
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d %d", &n, &P );
		factor( n );
		ans = 0;
		DFS( 0, 1 );
		printf( "%d\n", ans );
	}
	return 0;
}
