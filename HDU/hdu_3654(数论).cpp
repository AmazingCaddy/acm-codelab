#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 10004;

// const ll as = 9973LL*9967LL*9949LL*9941LL*9931LL;
// const ll inf = ( 1LL << 63 ) - 1;
// const ll inf = 9223372036854775807LL;
const ll inf = 10000000000000000LL;
//const ll inf = 9831047217181019LL + 10;	// 9973LL * 9967LL * 9949LL * 9941LL
int p[ maxn ], num[ maxn ];

int gcd( int a, int b ) { return b ? gcd( b, a % b ) : a; }
int max( int a, int b ) { return ( a > b ? a : b ); }

ll ans[ 20 ];
int l;

void insert( ll k ) {
	int j = 0;
	for( int i = l; i >= 0; i-- ) {
		if( ans[ i ] == k ) {
			return;
		}
		if( ans[ i ] < k ) { 
			j = i + 1; 
			break; 
		}
	}
	l++;
	for( int i = l; i > j; i-- ) {
		ans[ i ] = ans[ i - 1 ];
	}
	ans[ j ] = k;
	if( l > 16 ) {
		l = 16;
	}
}

void DFS( int dep, ll tmp, int len ) {
	//if( l == 16 && tmp > ans[ l ] ) return;
	if( dep == len ) {
		if( tmp > 2 ) {
			insert( tmp );
		}
		return;
	}
	ll temp = 1;
	for( int i = 0; i <= num[ dep ]; i++ ) {
		if( tmp * 1.0 * temp > inf ) {
			return;						// 减枝
		}
		if( l == 16 && tmp * temp > ans[ l ] ) {
			return;						// 减枝
		}
		DFS( dep + 1, tmp * temp, len );
		temp *= p[ dep ];
	}
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int r, K, N;
	while( scanf( "%d", &r ) != EOF ) {
		memset( num, 0, sizeof( num ) );
		for( int i = 0; i < r; i++ ) {
			scanf( "%d%d", &N, &K );
			N /= gcd( N, K );
			for( int i = 2; i * i <= N; i++ ) {
				if( N % i == 0 ) {
					int cnt = 0;
					while( N % i == 0 ) {
						cnt++;
						N /= i;
					}
					num[ i ] = max( num[ i ], cnt );
				}
			}
			num[ N ] = max( num[ N ], 1 );
		}
		int len = 0;
		for( int i = 2; i < maxn; i++ ) {
			if( num[ i ] ) {
				p[ len ] = i;
				num[ len++ ] = num[ i ];
			}
		}
		memset( ans, 0, sizeof( ans ) );
		ll da = 1;
		for( int i = 0; i < len; i++ ) {
			da = da * ( num[ i ] + 1 );
		}
		da -= 1;
		if( p[ 0 ] == 2 ) {
			da -= 1;
		}
		l = 0;
		DFS( 0, 1, len );
		printf( "%I64d\n", da );
		for( int i = 1; i <= l; i++ ) {
			if( i != 1 )printf( " " );
			printf( "%I64d", ans[ i ] );
		}
		if( l ) {
			printf( "\n" );
		}
	}
	return 0;
}
/*
8
9973 1
9967 1
9949 1
9941 1
9931 1
9929 1
9923 1
9907 1
*/
