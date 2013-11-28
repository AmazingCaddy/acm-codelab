/*
	author: AmazingCaddy
	time:	2011/9/22	19:46
	solve:	DP
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

const int maxn = 100005;

ll dp[ maxn ], event[ maxn ];

int main(int argc, char *argv[]){
	int cas, n, a, b;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d%d", &n, &a, &b );
		for( int i = 0; i < n; i++ ) {
			scanf( "%I64d", &event[ i ] );
		}
		dp[ 0 ] = a + b;
		for( int i = 1; i < n; i++ ) {
			if( b * ( event[ i ] - event[ i - 1 ] ) < a + a + b ) {
				dp[ i ] = dp[ i - 1 ] + b * ( event[ i ] - event[ i - 1 ] );
			}
			else {
				dp[ i ] = dp[ i - 1 ] + a + a + b;
			}
		}
		printf( "Case #%d: %I64d\n", t, dp[ n - 1 ] + a );
	}
	return 0;
}
