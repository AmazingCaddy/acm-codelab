/*
	author: AmazingCaddy
	time:	
	solve:	
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 105;
const int inf = 0x3fffffff;
const double eps = 1e-6;
const double pi = acos( -1.0 );
int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
struct point {
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};
point operator + ( const point &a, const point &b ) {
	return point( a.x + b.x, a.y + b.y );
}
point operator - ( const point &a, const point &b ) {
	return point( a.x - b.x, a.y - b.y );
}
double operator ^ ( const point &a, const point &b ){
	return a.x * b.y - a.y * b.x;
}
double operator & ( const point &a, const point &b ) {
	return a.x * b.x + a.y * b.y;
}
point operator *( const point &a, const double scale ) {
	return point( a.x * scale, a.y * scale );
}
point operator /( const point &a, const double scale ) {
	return point( a.x / scale, a.y / scale );
}
bool cmp( const point &a, const point &b ) {
	if( D( a.y - b.y ) == 0 ) {
		return a.x < b.x;
	}
	return a.y < b.y;
}
double det( const point &o, const point &a, const point &b ) {
	return ( a - o ^ b - o );
}
point p[ maxn ], np1[ maxn ], np2[ maxn ];
int convex_hull( int n, point np[ ] ) {
	if( n <= 2 ) {
		for( int i = 0; i < n; i++ ) {
			np[ i ] = p[ i ];
		}
		return n;
	}
	sort( p, p + n, cmp );
	int top = 0;
	for( int i = 0; i < n; i++ ) {
		while( top >= 2 && D( det( np[ top - 2 ], np[ top - 1 ], p[ i ] ) ) <= 0 ) {
			top--;
		}
		np[ top++ ] = p[ i ];
	}
	int k = top;
	for( int i = n - 2; i >= 0; i-- ) {
		while( top > k && D( det( np[ top - 2 ], np[ top - 1 ], p[ i ] ) ) <= 0 ) {
			top--;
		}
		np[ top++ ] = p[ i ];
	}
	top--;
	return top;
}

bool point_on_seg( const point &p, const point &a, const point &b ) {
	return D( a - p ^ b - p ) == 0 && D( a - p & b - p ) <= 0;
}

bool point_on_poly( int m, const point & p ) {
	for( int i = 0; i < m; i++ ) {
		if( point_on_seg( p, np2[ i ], np2[ ( i + 1 ) % m ] ) ) {
			return true;
		}
	}
	return false;
}

bool point_in_poly( point np[ ], int m, const point &p ) {
	double sum1 = 0, sum2 = 0;
	for( int i = 0; i < m; i++ ) {
		sum1 += fabs( np[ i ] - p ^ np[ ( i + 1 ) % m ] - p );
		sum2 += np[ i ] ^ np[ ( i + 1 ) % m ];
	}
	return D( sum1 - fabs(sum2) ) == 0;
}

bool seg_cross( const point &a, const point &b, const point &c, const point &d ) {
	if( point_on_seg( a, c, d ) || point_on_seg( b, c, d ) 
	 || point_on_seg( c, a, b ) || point_on_seg( d, a, b ) ) {
		return true;
	}
	int t1 = D( det( a, b, c ) ), t2 = D( det( a, b, d ) );
	int t3 = D( det( c, d, a ) ), t4 = D( det( c, d, b ) );
	return ( t1 * t2 < 0 && t3 * t4 < 0 );
}

bool check( int n, int m ) {
	if( n == 1 && m == 1 ) {
		return true;
	}
	if( n == 1 ) {
		return !point_in_poly( np2, m, np1[ 0 ] );
	}
	if( m == 1 ) {
		return !point_in_poly( np1, n, np2[ 0 ] );
	}
	if( n == 2 ) {
		for( int i = 0; i < m; i++ ) {
			if( seg_cross( np1[ 0 ], np1[ 1 ], np2[ i ], np2[ ( i + 1 ) % m ] ) ) {
				return false;
			}
		}
		return true;
	}
	if( m == 2 ) {
		for( int i = 0; i < n; i++ ) {
			if( seg_cross( np2[ 0 ], np2[ 1 ], np1[ i ], np1[ ( i + 1 ) % n ] ) ) {
				return false;
			}
		}
		return true;
	}
	for( int i = 0; i < n; i++ ) {
		if( point_in_poly( np2, m, np1[ i ] ) ) {
			return false;
		}
	}
	for( int i = 0; i < m; i++ ) {
		if( point_in_poly( np1, n, np2[ i ] ) ) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]){
//	freopen( "in.txt", "r", stdin );
	int n, m;
	while( 1 ) {
		scanf( "%d%d", &n, &m );
		if( n == 0 && m == 0 ) {
			break;
		}
		for( int i = 0; i < n; i++ ) {
			p[ i ].input( );
		}
		n = convex_hull( n, np1 );
		for( int i = 0; i < m; i++ ) {
			p[ i ].input( );
		}
		m = convex_hull( m, np2 );
		if( check( n, m ) ){
			printf( "YES\n" ); 
		}
		else {
			printf( "NO\n" );
		}
	}
	return 0;
}
