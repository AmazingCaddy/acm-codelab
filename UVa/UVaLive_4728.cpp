/*
	author: AmazingCaddy
	time:	2011-10-04 18:40:37 
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

const int maxn = 400004;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct point {
	double x, y;
	point( ){ }
	point( ll _x, ll _y ) : x( _x ), y( _y ) { }
//	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

point p[ maxn ], np[ maxn ];
int plen;

bool cmp( const point & a, const point & b ) {
	if( a.y == b.y ) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

point operator + ( const point & a, const point & b ) {
	return point( a.x + b.x, a.y + b.y );
}

point operator - ( const point & a, const point & b ) {
	return point( a.x - b.x, a.y - b.y );
}

ll operator ^ ( const point & a, const point & b ) {
	return a.x * b.y - a.y * b.x;
}

ll operator & ( const point & a, const point & b ) {
	return a.x * b.x + a.y * b.y;
}

int convex_hull( int n ) {
	sort( p, p + n, cmp );
	int top = 0;
	for( int i = 0; i < n; i++ ) {
		while( top >= 2 && ( np[ top - 1 ] - np[ top - 2 ] ^ p[ i ] - np[ top - 2 ] ) <= 0 ) {
			top--;
		}
		np[ top++ ] = p[ i ];
	}
	int k = top;
	for( int i = n - 2; i >= 0; i-- ) {
		while( top > k && ( np[ top - 1 ] - np[ top - 2 ] ^ p[ i ] - np[ top -2 ] ) <= 0 ) {
			top--;
		}
		np[ top++ ] = p[ i ];
	}
	top--;
	return top;
}

ll cross( const point &o, const point &a, const point & b ) {
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

ll dist2( const point & a, const point & b ) {
	point p = a - b;
	return p.x * p.x + p.y * p.y;
}

ll rotating_calipers( int n ) {
	int q = 1;
	ll ans = 0;
	np[ n ] = np[ 0 ];
	for( int p = 0; p < n; p++ ) {
		while( cross( np[ p ], np[ p + 1 ], np[ q + 1 ] ) > cross( np[ p ], np[ p + 1 ], np[ q ] ) ) {
			q = ( q + 1 ) % n;
		}
		ans = max( ans, max( dist2( np[ p ], np[ q ] ), dist2( np[ p + 1 ], np[ q + 1 ] ) ) );            
	}
	return ans; 
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int cas, n;
	ll x, y, w;
	scanf( "%d", &cas );
	while( cas -- ) {
		scanf( "%d", &n );
		n *= 4;
		for( int i = 0; i < n; i += 4 ) {
			scanf( "%lld%lld%lld", &x, &y, &w );
			p[ i ] = point( x, y );
			p[ i + 1 ] = point( x, y + w );
			p[ i + 2 ] = point( x + w, y );
			p[ i + 3 ] = point( x + w, y + w );
		}
		ll ans = rotating_calipers( convex_hull( n ) );
		printf( "%lld\n", ans );
	}
	return 0;
}
