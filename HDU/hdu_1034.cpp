/*
    author: AmazingCaddy
    time: 16/05/2011 18:53:43 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10004;
const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

int b[ 2 ][ maxn ];

int check( int n, int k )
{
	for( int i = 1; i < n; i++ )
		if( b[ k ][ i ] != b[ k ][ i - 1 ] )
			return 0;
	return 1;
}

int main( int ac, char * av[ ] )
{
	int n;
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%d", &b[ 0 ][ i ] );
		b[ 0 ][ n ] = b[ 0 ][ 0 ];
		int k = 1, cnt = 0;
		while( 1 )
		{
			for( int i = 0; i < n; i++ )
				b[ k ][ i + 1 ] = b[ 1 - k ][ i ] / 2 + b[ 1 - k ][ i + 1 ] / 2;
			b[ k ][ 0 ] = b[ k ][ n ];
			
			for( int i = 0; i <= n; i++ )
				if( b[ k ][ i ] & 1 ) 
					b[ k ][ i ]++;
			cnt++;
			if( check( n, k ) ) break;
			k = 1 - k;
		}
		printf( "%d %d\n", cnt, b[ k ][ 0 ] );
	}
	return 0;
}
