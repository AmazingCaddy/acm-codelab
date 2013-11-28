/*
	author: AmazingCaddy
	time:	
	solve:	
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
const double eps = 1e-10;

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
	int n, m;
	while( scanf( "%d%d", &n, &m ) != EOF ) {
		n = n * 2 - 2; // 0 ~ n-2 - n-1 - n ~ 2n-3
		m--;
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		for( int i = 0; i < n; i++ ) {
			if( i == m || i == n - m ) {
				a[ i ][ i ] = 1;
				b[ i ] = 0;
			}
			else {
				a[ i ][ i ] = 6;
				b[ i ] = 6;
				for( int j = 1; j <= 6; j++ ) {
					a[ i ][ ( i + j ) % n ] -= 1;
				}
			}
		}
		gauss_cpivot( n );
		printf( "%.2lf\n", b[ 0 ] );
	}
	return 0;
}
