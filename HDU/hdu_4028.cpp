/*
author: AmazingCaddy
time:    2011-09-23 13:35:14 
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

const int maxn = 41;
map< ll, ll > dp[ maxn ];

ll gcd( ll a, ll b ) {
	return ( b ? gcd( b, a % b ) : a ); 
}

ll lcm( ll a, ll b ) {
	return a / gcd( a, b ) * b;
}

void init( ) {
	ll sum = 1;
	for( int i = 1; i <= 40; i++ ) {
		sum = lcm( sum, (ll)i );
		cout << i << " " << sum << endl;
	}
}

int main(int argc, char *argv[]) {
	//    init( );
	dp[ 0 ][ 1 ] = 1;
	for( int i = 1; i <= 40; i++ ) {
		dp[ i ] = dp[ i - 1 ];
		for( map< ll, ll >::iterator iter = dp[ i - 1 ].begin(); iter != dp[ i - 1 ].end(); iter++ ) {
			dp[ i ][ lcm( iter -> first, (ll)i ) ] += iter -> second;
		}
	}
	int cas, n;
	ll m;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%I64d", &n, &m );
		printf( "Case #%d: ", t );
		if( m == 1 ) {
			printf( "%I64d\n", (1LL << n ) - 1 );
			continue;
		}
		ll sum = 0;
		for( map< ll, ll >::iterator it = dp[ n ].begin(); it != dp[ n ].end(); it++ ) {
			if( it -> first >= m ) {
				sum += it -> second;
			}
		}
		printf( "%I64d\n", sum );
	}
	return 0;
}
