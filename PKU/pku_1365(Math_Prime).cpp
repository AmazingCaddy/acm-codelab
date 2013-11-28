/*
	author: AmazingCaddy
	time: 2011/2/28  19:50
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef __int64 ll;

const int maxn = 33000;
int vis[ maxn ], p[ maxn ];
int a[ 32 ], b[ 32 ];
int plen, flen;

void prime( )
{
	int i, j, k;
	memset( vis, 0, sizeof( vis ) );
	for( plen = 0, i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			p[ plen++ ] = i;
			if( k < maxn ) 
				for( j = k; j < maxn; j += i ) vis[ j ] = 1;
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

int pow( int a, int b )
{
	int sum = 1;
	for( int i = 0; i < b; i++ )
		sum *= a;
	return sum;
}

int num[ 100 ], cnt[ 100 ];
char buf[ 50000 ];

int main(int argc, char *argv[])
{
	prime( );
	while( gets( buf ) && buf[ 0 ] != '0' )
	{
		int len = strlen( buf );
		int i = 0, j, k = 0;
		while( i < len )
		{
			j = i;
			num[ k ] = 0;
			while( buf[ j ] != ' ' )
			{
				num[ k ] = num[ k ] * 10 + buf[ j ] - '0';
				j++;
			}
			j++;
			cnt[ k ] = 0;
			while( buf[ j ] != ' ' && j < len )
			{
				cnt[ k ] = cnt[ k ] * 10 + buf[ j ] - '0';
				j++;
			}
			k++;
			i = j + 1;
		}
		int sum = 1;
		for( i = 0; i < k; i++ )
			sum = sum * pow( num[ i ], cnt[ i ] );
		//printf( "sum - 1 = %d\n", sum - 1 );
		factor( sum - 1 );
		for( i = flen - 1; i >= 0; i-- )
		{
			if( i != flen - 1 ) printf( " " );
			printf( "%d %d", a[ i ], b[ i ] );
		}
		printf( "\n" );
	}
	return 0;
}
