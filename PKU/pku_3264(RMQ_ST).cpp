/*
	author: AmazingCaddy
	time:	2011/9/2	18:08
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

const int maxn = 50020;
int stMax[ maxn ][ 16 ], stMin[ maxn ][ 16 ];
int D[ maxn ];
int base[ maxn ];

int Max( int a, int b ) {
	return D[ a ] > D[ b ] ? a : b;
//	return a > b ? a : b;
}

int Min( int a, int b ) {
	return D[ a ] < D[ b ] ? a : b;
}

void ST( int n ) {
	for( int i = 0; i < n; i++ ) {
		stMax[ i ][ 0 ] = i;
		stMin[ i ][ 0 ] = i;
//		st[ i ][ 0 ] = D[ i ];
	}
	for( int i = 0, now = 0; i < n; i++ ) {
		if( ( 1 << ( now + 1 ) ) <= i ) {
			now++;
		}
		base[ i ] = now;
	}
	for( int j = 1, k = 2; k < n; j++, k <<= 1 ) {
		for( int i = 0, sk = ( k >> 1 ); i + k - 1 < n; i++ ) {
			stMax[ i ][ j ] = Max( stMax[ i ][ j - 1 ], stMax[ i + sk ][ j - 1 ] );
			stMin[ i ][ j ] = Min( stMin[ i ][ j - 1 ], stMin[ i + sk ][ j - 1 ] );
		}
	}
}

int MaxRMQ( int l, int r ) {
	if( l > r ) {
		swap( l, r );
	}
	int k = base[ r - l + 1 ];
	int t = Max( stMax[ l ][ k ], stMax[ r - ( 1 << k ) + 1 ][ k ] );
	return D[ t ];
}

int MinRMQ( int l, int r ) {
	if( l > r ) {
		swap( l, r );
	}
	int k = base[ r - l + 1 ];
	int t = Min( stMin[ l ][ k ], stMin[ r - ( 1 << k ) + 1 ][ k ] );
	return D[ t ];
}

int main( ) {
	int n, q, l, r;
	while( scanf( "%d%d", &n, &q ) != EOF ) {
		for( int i = 0; i < n; i++ ) {
			scanf( "%d", &D[ i ] );
		}
		ST( n );
		for( int i = 0; i < q; i++ ) {
			scanf( "%d%d", &l, &r );
			l--;
			r--;
			printf( "%d\n", MaxRMQ( l, r ) - MinRMQ( l, r ) );
		}
	}
	return 0;
}