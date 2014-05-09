/*
	author: AmazingCaddy
	time:	2011/9/5	15:41
	c + N 一定是在 c < a || ( a - c ) % b != 0 的时候出现
	将所有查询按照 b来分类  令 P = sqrt( N )
	b <= P 刷表 
	b > P 暴力计算 最多计算 2 * P 次
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

typedef long long ll;

const int maxn = 50004;
const int MOD = 1000000007;

int A[ maxn << 1 ], PI[ maxn << 1 ];
int ans[ maxn ];

ll mod( ll a, ll n ) {
	return ( a % n + n ) % n;
}

void ex_gcd( ll a, ll b, ll & d, ll & x, ll & y ) {
	if( !b ) {
		d = a, x = 1, y = 0;
	}
	else {
		ex_gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

ll Inverse( ll a, ll n ) {
	ll d, x, y;
	ex_gcd( a, n, d, x, y );
	return d == 1 ? mod( x, n ) : -1;
}

int step;
struct Query{
	int id, a, c;
	Query( ) { }
	Query( int _id, int _a, int _c ) : id( _id ), a( _a ), c( _c ) { }
	void cal( ) {
		ans[ id ] = (ll)PI[ c ] * Inverse( a >= step ? PI[ a - step ] : 1, MOD ) % MOD;
	}
};
vector< Query > query[ 800 ];

void init( int step, int n ) {
	for( int i = 0; i < step; i++ ) {
		PI[ i ] = A[ i ];
	}
	for( int i = step; i < n; i++ ) {
		PI[ i ] = (ll)PI[ i - step ] * A[ i ] % MOD;
	}
}

int main(int argc, char *argv[]) {
	int N, Q, P;
	int a, b, c;
	while( scanf( "%d%d", &N, &Q ) != EOF ) {
		for( int i = 0; i < N; i++ ) {
			scanf( "%d", &A[ i ] );
			A[ i + N ] = A[ i ];
		}
		P = sqrt( N * 1.0 );
		for( int i = 1; i <= P; i++ ) {
			query[ i ].clear( );
		}
		for( int i = 0; i < Q; i++ ) {
			scanf( "%d%d%d", &a, &b, &c );
			a--;
			c--;
			if( c < a || ( c - a ) % b != 0 ) {
				c += N;
			}
			if( a == c ) {
				ans[ i ] = A[ a ];
				continue;
			}
			if( b <= P ) {
				query[ b ].push_back( Query( i, a, c ) );
			}
			else {
				ans[ i ] = 1;
				for( int t = a; t <= c; t += b ) {
					ans[ i ] = (ll)ans[ i ] * A[ t ] % MOD;
				}
			}
		}
		for( int i = 1; i <= P; i++ ) {
			if( query[ i ].size( ) ) {
				init( i, 2 * N );
				step = i;
				for( int j = 0; j < query[ i ].size( ); j++ ) {
					query[ i ][ j ].cal( );
				}
			}
		}
		for( int i = 0; i < Q; i++ ) {
			printf( "%d\n", ans[ i ] );
		}
	}
	return 0;
}
