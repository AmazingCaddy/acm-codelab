/*
	author: AmazingCaddy
	time:	
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
#define lowbit(x) ((x)&(-(x)))
typedef long long ll;

const int maxn = 10004;
const ll mod = 1000000000000LL;
ll ten[ 16 ];

ll mul_mod( ll a, ll b, ll mod ) {
	ll la = a / 1000000, ra = a % 1000000;
	ll lb = b / 1000000, rb = b % 1000000;
	ll res = la * rb * 1000000 % mod + lb * ra * 1000000 % mod + ra * rb;
	return res % mod;
}

ll pow_mod( ll a, ll b, ll mod ) {
	ll ans = 1, d = a % mod;
	while( b ) {
		if( b & 1 ) {
			ans = mul_mod( ans, d, mod );
		}
		d = mul_mod( d, d, mod );
		b >>= 1;
	}
	return ans;
}

ll K, best;
int dfs( int dep, ll res ) {
//	printf( "dep = %d\n", dep );
	if( dep == 12 ) {
		if( pow_mod( K, res, ten[ dep ] ) == res % ten[ dep ] ) {
			best = res;
			return 1;
		}
		return 0;
	}
	int st = ( dep == 11 ? 1 : 0 );
	ll delta = ten[ dep ] * st;
	ll multy = pow_mod( K, ten[ dep ], ten[ dep ] );
	ll start = pow_mod( K, res, ten[ dep ] );
	for( int i = st; i <= 9; i++ ) {
		ll val = res + delta;
//		printf( "val = %lld\n", val );
		if( start == val % ten[ dep ] && dfs( dep + 1, val ) ) {
			return 1;
		}
		start = mul_mod( start, multy, ten[ dep ] );
		delta += ten[ dep ];
	}
	return 0;
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	ten[ 0 ] = 1;
	for( int i = 1; i < 16; i++ ) {
		ten[ i ] = ten[ i - 1 ] * 10;
	}
	int t = 1;
	while( scanf( "%lld", &K ) && K ) {
		dfs( 0, 0 );
		printf( "Case %d: Public Key = %lld Private Key = %lld\n", t++, K, best );
	}
	return 0;
}
