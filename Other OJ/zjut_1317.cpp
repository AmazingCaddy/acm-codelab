/*
	author: AmazingCaddy
	time:	2011/10/28	0:03
	solve:	
		if m is odd or m is even and n is even
		En = 0.25 * E(n-2) + 0.25 * E(n+2) + 0.5 * En + 1
		E0 = 0
		else INF
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 105;
const int inf = 0x3fffffff;
const double eps = 1e-10;
const double pi = acos( -1.0 );

double a[ maxn ][ maxn ], b[ maxn ];

int gauss_cpivot( int n ) {
	int i, j, k, row;
	double maxp, t;
	for ( k = 0; k < n; k++ ) {
		for( maxp = 0, i = k; i < n; i++ ) {
			if( fabs( a[ i ][ k ] ) > fabs( maxp ) ) {
				maxp = a[ row = i ][ k ];
			}
		}
		if( fabs( maxp ) < eps ) {
			return 0;
		}
		if( row != k ) {
			for( j = k; j < n; j++ ) {
				t = a[ k ][ j ], a[ k ][ j ] = a[ row ][ j ], a[ row ][ j ] = t;
			}
			t = b[ k ], b[ k ] = b[ row ], b[ row ] = t;
		}
		for( j = k + 1; j < n; j++ ) {
			a[ k ][ j ] /= maxp;
			for( i = k + 1; i < n; i++ ) {
				a[ i ][ j ] -= a[ i ][ k ] * a[ k ][ j ];
			}
		}
		b[ k ] /= maxp;
		for( i = k + 1; i < n; i++ ) {
			b[ i ] -= b[ k ] * a[ i ][ k ];
		}
	}
	for( i = n - 1; i >= 0; i-- ) {
		for( j = i + 1; j < n; j++ ) {
			b[ i ] -= a[ i ][ j ] * b[ j ];
		}
	}
	return 1;
}

int main(int argc, char *argv[]){
	int m, n;
	while( scanf( "%d%d", &m, &n ) != EOF ) {
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		if( m & 1 ) {
			a[ 0 ][ 0 ] = 1;
			b[ 0 ] = 0;
			for( int i = 1; i < m; i++ ) {
				a[ i ][ i ] = 0.5;
				a[ i ][ ( i + 2 ) % m ] -= 0.25;
				a[ i ][ ( ( i - 2 ) % m + m ) % m ] -= 0.25;
				b[ i ] = 1;
			}
			if( gauss_cpivot( m ) ) {
				printf( "%.2lf\n", b[ n ] );
			}
			else {
				printf( "INF\n" );
			}
		}
		else {
			if( n & 1 ) {
				printf( "INF\n" );
			}
			else {
				m >>= 1;
				n >>= 1;
				a[ 0 ][ 0 ] = 1; 
				b[ 0 ] = 0;
				for( int i = 1; i < m; i++ ) {
					a[ i ][ i ] = 0.5;
					a[ i ][ ( i + 1 ) % m ] -= 0.25;
					a[ i ][ ( ( i - 1 ) % m + m ) % m ] -= 0.25;
					b[ i ] = 1;
				}
				if( gauss_cpivot( m ) ) {
					printf( "%.2lf\n", b[ n ] );
				}
				else {
					printf( "INF\n" );
				}
			}
		}
	}
	return 0;
}
