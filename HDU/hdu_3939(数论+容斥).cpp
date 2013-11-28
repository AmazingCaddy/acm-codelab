/*
	author: AmazingCaddy
	time:	2011-08-14 16:38:10 
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

const int maxn = 1000004;
const int maxm = 1 << 11;
bool vis[ maxn ];
int p[ maxn ], phi[ maxn ];
int plen, flen;
int a[ 32 ], b[ 32 ];

void prime( ) {
	plen = 0;
	memset( vis, 0, sizeof( vis ) );
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
}

void PHI( ) {
	phi[ 1 ] = 1;
	for( int i = 2; i < maxn; i++ ) {
		if( !phi[ i ] ) {
			for( int j = i; j < maxn; j += i ) {
				if( !phi[ j ] ) {
					phi[ j ] = j;
				}
				phi[ j ] = phi[ j ] / i * ( i - 1 );
			}
		}
	}
}

void factor( int n ) {
	flen = 0;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ ) {
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

void init( ) {
	prime( );
	PHI( );
}

int L[ maxm ], M[ maxm ];
int rongchi( int len, int n ) {
	int ans = n;
	L[ 0 ] = 1;
	M[ 0 ] = 1;
	for( int i = 0; i < len; i++ ) {
		int m = 1 << i;
		for( int j = 0; j < m; j++ ) {
			L[ m | j ] = L[ j ] * a[ i ];
			M[ m | j ] = -M[ j ];
			ans -= M[ j ] * n / L[ m | j ];
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
//	freopen( "in.in", "r", stdin );
	int cas;
	ll L;
	init( );
	scanf( "%d", &cas );
	while( cas-- ) {
		cin >> L;
		ll ans = 0;
		for( int A = 2; (ll)A * A <= L; A++ ) {
			int B = (int)floor( sqrt( 1.0 * ( L - (ll)A * A ) ) );
			if( A & 1 ) {
				factor( A );
				if( A <= B ) {
					ans += rongchi( flen, A >> 1 );
				}
				else {
					ans += rongchi( flen, B >> 1 );
				}
			}
			else {
				if( A <= B ) {
					ans += phi[ A ];
				}
				else {
					factor( A );
					ans += rongchi( flen, B );
				}
			}
		}
		cout << ans << endl;
	}
//	cout << clock( ) << endl;
	return 0;
}
