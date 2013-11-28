/*
	author: AmazingCaddy
	time:	2011-08-23 14:06:24 
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

ll num[ 20 ], Pow[ 20 ];

void init( ) {
	num[ 0 ] = 0, Pow[ 0 ] = 1;
	for( int i = 1; i < 18; i++ ) {
		num[ i ] = num[ i - 1 ] * 10 + 9;
		Pow[ i ] = Pow[ i - 1 ] * 10;
	}
}

ll f( ll n, int k, int i ) {
	n++;
	ll ret = n / k;
	ll tmp = n % k;
	if( tmp == 0 ) return ret;
	return ret + ( i < tmp );
}

ll cal( ll n, int k ) {
	int len = 0;
	int a[ 20 ], b[ 20 ], c[ 20 ];
	ll x = n;
	while( x ) {
		a[ len++ ] = x % 10;
		x /= 10;
	}
	ll ans = 0;
	for( int i = 2; i < len; i++ ) {
		for( int j = 1; j < i; j++ ) {
			for( int p = 0; p < k; p++ ) {
				ll t1 = f( num[ j ], k, p );
				ll t2 = f( num[ i - j ], k, ( k - p ) % k ) - f( num[ i - j - 1 ], k, ( k - p ) % k );
				ans = ans + t1 * t2;
			}
		}
	}
	for( int i = 0; i < len; i++ ) {
		b[ i ] = a[ i ];
		c[ i ] = a[ i ];
	}
	for( int i = 0; i < len; i++ ) {
		if( i == len - 1 ) b[ i ] = 1;
		else b[ i ] = 0;
		if( c[ i ] ) {
			c[ i ] --;
			ll cl = 0, cr = c[ 0 ], bl = 0, br = b[ 0 ];
			for( int j = len - 1; j >= 1; j-- ) {
				bl = bl * 10 + b[ j ];
				cl = cl * 10 + c[ j ];
			}
			for( int j = 1; j < len; j++ ) {
				for( int p = 0; p < k; p++ ) {
					ll t1 = f( cr, k, p ) - f( br - 1, k, p );
					ll t2 = f( cl, k, ( k - p ) % k ) - f( bl - 1, k, ( k - p ) % k );
					ans = ans + t1 * t2;
				}
				bl /= 10;
				cl /= 10;
				br = br + Pow[ j ] * b[ j ];
				cr = cr + Pow[ j ] * c[ j ];
			}
		}
		c[ i ] = 9;
	}
	ll left = 0, right = a[ 0 ];
	for( int j = len - 1; j >= 1; j-- ) {
		left = left * 10 + a[ j ];
	}
	for( int i = 1; i < len; i++ ) {
		if( ( left + right ) % k == 0 ) {
			ans ++;
		}
		left /= 10;
		right = right + Pow[ i ] * a[ i ];
	}
	return ans;
}

int main(int argc, char *argv[]) {
	ll A, B;
	int K;
	init( );
	while( scanf( "%I64d%I64d%d", &A, &B, &K ) != EOF )	{
	//while( scanf( "%lld%lld%d", &A, &B, &K ) != EOF ) {
		ll ans1 = cal( B, K );
		ll ans2 = cal( A - 1, K );
		printf( "%I64d\n", ans1 - ans2 );
	//	printf( "%lld\n", ans1 - ans2 );
	}
	return 0;
}
