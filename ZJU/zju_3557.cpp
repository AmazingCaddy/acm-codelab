/*
	author: AmazingCaddy
	time:	2011-11-01 22:12:09 
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

const int maxn = 10004;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

ll pow_mod( ll a, ll b, ll p ) {
	ll ans = 1, d = a % p;
	while( b ) {
		if( b & 1 ) {
			ans = ans * d % p;
		}
		d = d * d % p;
		b >>= 1;
	}
	return ans;
}

ll inverse( ll a, ll p ) {
	return pow_mod( a, p - 2, p );
}

ll cnk( ll n, ll m, ll p ) {
	ll ans = 1, cntp = 0;
	for( ll i = m; i >= 1; i-- ) {
		ll x = i, y = i + n - m;
		while( y % p == 0 ) {
			y /= p;
			cntp++;
		}
		while( x % p == 0 ) {
			x /= p;
			cntp--;
		}
		ans = ans * y % p * inverse( x, p ) % p;
	}
	if( cntp > 0 ) {
		return 0;
	}
	return ans;
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	ll n, m, p;
	while( scanf( "%lld%lld%lld", &n, &m, &p ) != EOF ) {
		if( n - m + 1 < m ) {
			printf( "0\n" );
		}
		else {
			printf( "%lld\n", cnk( n - m + 1, m, p ) );
		}
	}
	return 0;
}