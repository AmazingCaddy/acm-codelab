/*
author: AmazingCaddy
time:    2011-09-29 14:00:25 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 4004;
double p[ maxn ][ 4 ], dp[ maxn ][ 4 ];

int main(int argc, char *argv[]) {
	//    freopen( "in.txt", "r", stdin );
	int cas, n, a, b;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d%d", &n, &a, &b );
		memset( p, 0, sizeof( p ) );
		memset( dp, 0, sizeof( dp ) );
		for( int i = 1; i <= n; i++ ) {
			for( int j = 0; j < 4; j++ ) {
				scanf( "%lf", &p[ i ][ j ] );
			}
		}
		for( int i = n + 1; i < maxn; i++ ) {
			p[ i ][ 3 ] = 1.0;
		}
		p[ 0 ][ 3 ] = 1.0;
		dp[ 0 ][ 3 ] = 1.0;
		for( int i = 0; i <= n; i++ ) {
			for( int j = 0; j < 4; j++ ) {
				double P = 1;
				for( int x = a; x <= b; x++ ) {
					if( j == 1 ) {
						dp[ i + x ][ 2 ] += dp[ i ][ 1 ] * P * p[ i + x ][ 2 ];
						dp[ i + x ][ 3 ] += dp[ i ][ 1 ] * P * p[ i + x ][ 3 ];
						P *= ( p[ i + x ][ 1 ] + p[ i + x ][ 0 ] );
					}
					if( j == 2 ) {
						dp[ i + x ][ 1 ] += dp[ i ][ 2 ] * P * p[ i + x ][ 1 ];
						dp[ i + x ][ 3 ] += dp[ i ][ 2 ] * P * p[ i + x ][ 3 ];
						P *= ( p[ i + x ][ 2 ] + p[ i + x ][ 0 ] );
					}
					if( j == 3 ) {
						dp[ i + x ][ 1 ] += dp[ i ][ 3 ] * P * p[ i + x ][ 1 ];                        
						dp[ i + x ][ 2 ] += dp[ i ][ 3 ] * P * p[ i + x ][ 2 ];
						dp[ i + x ][ 3 ] += dp[ i ][ 3 ] * P * p[ i + x ][ 3 ];
						P *= p[ i + x ][ 0 ];
					}
				}
			}
		}
		double sum = 0;
		for( int i = 1; i <= n + a; i++ ) {
			for( int j = 1; j < 4; j++ ) {
				sum += dp[ i ][ j ];
			}
		}
		printf( "%.8lf\n", sum );
	}
	return 0;
}
