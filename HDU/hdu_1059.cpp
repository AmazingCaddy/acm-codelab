/*
	author: AmazingCaddy
	time: 
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

typedef __int64 ll;

const int maxn = 120004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int dp[ maxn ];
int cnt[ 10 ];
int bag[ 1000 ];
int len;
int check( )
{
	for( int i = 1; i <= 6; i++ )
		if( cnt[ i ] ) return 0;
	return 1;
}

void factor( int n, int k )
{
	int tmp = 1;
	while( 1 )
	{
		if( n >= tmp ) bag[ len++ ] = tmp * k;
		else break;
		n -= tmp;
		tmp <<= 1;
	}
	if( n ) bag[ len++ ] = n * k;
}

int main(int argc, char *argv[])
{
	int t = 1;
	while( 1 )
	{
		for( int i = 1; i <= 6; i++ )
			scanf( "%d", &cnt[ i ] );
		if( check( ) ) break;
		int sum = 0;
		for( int i = 1; i <= 6; i++ )
			sum += cnt[ i ] * i;
		printf( "Collection #%d:\n", t++ );
		if( sum % 2 == 1 )
		{
			printf( "Can't be divided.\n\n");
			continue;
		}

		len = 0;
		for( int i = 1; i <= 6; i++ )
			factor( cnt[ i ], i );
		
		memset( dp, 0, sizeof( dp ) );
		dp[ 0 ] = 1;
		sum /= 2;
		
		for( int i = 0; i < len; i++ )
		{
			for( int j = sum; j >= bag[ i ]; j-- )
			{
				if( dp[ j - bag[ i ] ] ) dp[ j ] = 1;
			}
		}
		if( dp[ sum ] ) printf( "Can be divided.\n" );
		else printf( "Can't be divided.\n" );
		printf( "\n" );
	}
	return 0;
}
