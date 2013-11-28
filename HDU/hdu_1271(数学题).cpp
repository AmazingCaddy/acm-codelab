/*
	author: AmazingCaddy
	time: 2011/5/21  18:12
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
const int maxn = 1004;

int pow10[ 11 ];

void init( )
{
	pow10[ 0 ] = 1;
	for( int i = 1; i < 10; i++ )
		pow10[ i ] = pow10[ i - 1 ] * 10;
}

int res[ maxn ];

int main(int argc, char *argv[])
{
	int n, a, b, c;
	init( );
	while( scanf( "%d", &n ) && n )
	{
		int len = 0, nn = n;
		while( nn )
		{
			len++;
			nn /= 10;
		}
		int k = 0;
		for( int i = 0; i < len; i++ )
		{
			a = n / ( pow10[ i ] * 11 );
			for( b = ( i == len - 1 ); b < 10; b++ )
			{
				c = n - ( 11 * a + b ) * pow10[ i ];
				if( c >= 0 && c % 2 == 0 && c / 2 < pow10[ i ] )
				{
					c /= 2;
					res[ k++ ] = a * pow10[ i + 1 ] + b * pow10[ i ] + c;
				}
			}
		}
		sort( res, res + k );
		k = unique( res, res + k ) - res;
		if( k == 0 ) { printf( "No solution.\n" ); continue; }
		for( int i = 0; i < k; i++ )
		{
			if( i ) printf( " " );
			printf( "%d", res[ i ] );
		}
		printf( "\n" );
	}
	return 0;
}
