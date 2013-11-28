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

const int maxn = 8;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

double dp[ maxn ][ 1 << maxn ];
double p[ 1 << maxn ][ 1 << maxn ];

int main(int argc, char *argv[]){
	int n;
	while( scanf( "%d", &n ) && n != -1 ) {
		int m = 1 << n;
		for( int i = 0; i < m; i++ ) {
			for( int j = 0; j < m; j++ ) {
				scanf( "%lf", &p[ i ][ j ] );
			}
		}
		for( int j = 0; j < m; j++ ) {
			dp[ 0 ][ j ] = 1;
		}
		for( int i = 1; i <= n; i++ ) {
			for( int j = 0; j < m; j++ ) {
				dp[ i ][ j ] = 0;
				int tmp = ( j & ( (-1) << (i - 1) ) ) ^ ( 1 << (i - 1) );
//				printf( "l = %d, r = %d\n", tmp, tmp + ( 1 << (i - 1) ));
				for( int k = tmp; k < tmp + ( 1 << (i - 1) ); k++ ) {
					dp[ i ][ j ] += p[ j ][ k ] * dp[ i - 1 ][ k ];
				}
				dp[ i ][ j ] *= dp[ i - 1 ][ j ];
			}
		}
		double ans = 0;
		int k = 0;
		for( int j = 0; j < m; j++ ) {
			if( ans < dp[ n ][ j ] ) {
				ans = dp[ n ][ j ];
				k = j;
			}
		}
		printf( "%d\n", k + 1 );
	}
	return 0;
}
