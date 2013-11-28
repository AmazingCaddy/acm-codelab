/*
	author: AmazingCaddy
	time:	2011/9/5	13:49
	本题是求fibonacci数列mod P的循环节长度 S(P)
	可以知道对于一个素数pi来说
	S(pi^ci) = S(pi) * pi^(ci - 1)
	而 S(P) = LCM( S(pi^ci) ) 
	由于本题中保证了pi很小( <= 10^6),于是可以暴力获得S(pi)
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

const int maxn = 100004;
int vis[ maxn ], p[ maxn / 10 ];
int plen, flen;
int a[ 32 ], b[ 32 ];

void prime( ) {
	memset( vis, 0, sizeof( vis ) );
	plen = 0;
	for( ll i = 2, k = 4; i < maxn; ++i, k += i + i - 1 ) {
		if( !vis[ i ] ) {
			p[ plen++ ] = i;
			if( k < maxn ) {
				for( ll j = k; j < maxn; j += i ) {
					vis[ j ] = 1;
				}
			}
		}
	}
//	printf( "plen = %d\n", plen );
}

ll gcd( ll a, ll b ) {
	return ( b ? gcd( b, a % b ) : a );
}

ll lcm( ll a, ll b ) {
	return a / gcd( a, b ) * b;
}

int pow( int a, int b ) {
	int ans = 1;
	for( int i = 0; i < b; i++ ) {
		ans *= a;
	}
	return ans;
}

int get_circle( int p ) {
	int A = 1, B = 1, C;
	for( int i = 3; ; i++ ) {
		C = ( A + B ) % p;
		A = B;
		B = C;
		if( A == 1 && B == 1 ) {
			return i - 2;
		}
	}
	return -1;
}

void factor( int n ) {
	flen = 0;
	for( int i = 0; i < plen && p[ i ] * p[ i ] <= n; i++ ) {
		if( n % p[ i ] == 0 ) {
			for( b[ flen ] = 0; n % p[ i ] == 0; ++b[ flen ], n /= p[ i ] );
			a[ flen++ ] = p[ i ];
		}
	}
	if( n > 1 ) {
		a[ flen ] = n;
		b[ flen++ ] = 1;
	}
}

void solve( int n ) {
	factor( n );
	ll ans = 1;
	for( int i = 0; i < flen; i++ ) {
		ll circle = (ll)get_circle( a[ i ] ) * pow( a[ i ], b[ i ] - 1 );
		ans = lcm( ans, circle );
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
	prime( );
	int cas, n;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &n );
		printf( "Case #%d: ", t );
		solve( n );
	}
	return 0;
}
