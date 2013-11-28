/*
	author: AmazingCaddy
	time:	2011/8/13   13:41
	x^k = b mod p, p is prime
	1)	先暴力求p的原根g
	2)	大步小步求g^t1 = b mod p
	3)	则g^(t1+n*t2) = b mod p, t2 = p - 1
	4)	设x = g^y mod p, x^k = (g^y)^k = g^(yk) = g^(t1+n*t2)
		那么就是求同余方程 yk = t1( mod t2 )
		求出y之后带到x = g^y mod p,解出x
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

//typedef __int64 ll;
typedef long long ll;

const int maxn = 1000004;
int vis[ maxn ], p[ maxn ];
int plen, flen;
ll a[ 64 ], b[ 64 ];
ll k, m, newx, g;

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
}

ll mul_mod( ll a, ll b, ll mod ) {
	ll ans = 0, d = a % mod;
	while( b ) {
		if( b & 1 ) {
			ans += d;
			if( ans > mod ) {
				ans -= mod;
			}
		}
		d += d;
		if( d > mod ) {
			d -= mod;
		}
		b >>= 1;
	}
	return ans;
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

void factor( ll n ) {
	flen = 0;
	for( int i = 0;(ll) p[ i ] * p[ i ] <= n; i++ ) {
		if( n % p[ i ] == 0 ) {
			for( b[ flen ] = 0; n % p[ i ] == 0; ++b[ flen ], n /= p[ i ] );
			a[ flen++ ] = p[ i ];
		}
	}
	if( n > 1 ) a[ flen ] = n, b[ flen++ ] = 1;
}

void ex_gcd( ll a, ll b, ll & d, ll &x, ll &y ) {
	if( !b ) {
		x = 1, y = 0, d = a;
	}
	else {
		ex_gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

ll Inv( ll n, ll p ) {
	return pow_mod( n, p - 2, p );
}

bool dfs( int dep, ll t ) {
	if( dep == flen ) {
		ll ans = pow_mod( g, t, m );
		if( ans == 1 && t != m - 1 ) return false;
		return true;
	}
	ll tmp = 1;
	for( int i = 0; i <= b[ dep ]; i++ ) {
		if( !dfs( dep + 1, t * tmp ) ) return false;
		tmp *= a[ dep ];
	}
	return true;
}

void find_g( ) {
	factor( m - 1 );	
	for( g = 2; ; g++ ) {
		if( dfs( 0, 1 ) ) break;
	}
}

// a^x = b ( mod p ) find x, p is prime
ll log_x( ll a, ll b, ll p ) {
	map< ll, int > x;
	ll z = (ll)ceil( sqrt( p * 1.0 ) );
	ll v = Inv( pow_mod( a, z, p ), p );
	ll e = 1;
	x[ 1 ] = 0;
	for( int i = 1; i < z; i++ ) {
		e = mul_mod( e, a, p );
		if( !x.count( e ) ) {
			x[ e ] = i;
		}
	}
	for( int i = 0; i < z; i++ ) {
		if( x.count( b ) ) { 
			return i * z + x[ b ];
		}
		b = mul_mod( b, v, p );
	}
	return -1;
}

ll sol[ 1000 ];
void solve( ll a, ll b, ll n ) {
	ll d, x, y;
	ex_gcd( a, n, d, x, y );
	if( b % d ) {
		printf( "-1\n" );
	}
	else {
		//ax+ny=d, so a'x+n'y=1, x is the inverse of a' mod n'
		n /= d, b /= d;
		sol[ 0 ] = ( x * b % n + n ) % n;	// first soltion
		for( int i = 1; i < d; i++ ) {
			sol[ i ] = sol[ i - 1 ] + n;
		}
		for( int i = 0; i < d; i++ ) {
			sol[ i ] = pow_mod( g, sol[ i ], m );
		}
		sort( sol, sol + d );
		for( int i = 0; i < d; i++ ) {
			printf( "%I64d\n", sol[ i ] );
		}
	}
}

int main(int argc, char *argv[])
{
//	freopen( "in.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int cas = 1;
	prime( );
	while( scanf( "%I64d%I64d%I64d", &k, &m, &newx ) != EOF ) {
		find_g( );
		ll t1 = log_x( g, newx, m );
		ll t2 = m - 1;
		printf( "case%d:\n", cas++ );
		solve( k, t1, t2 );
	}
	return 0;
}
