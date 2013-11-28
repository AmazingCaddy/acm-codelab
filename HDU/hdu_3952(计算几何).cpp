/*
	author: AmazingCaddy
	time:	2011-08-18 12:04:40 
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

const int maxn = 104;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int D( double x ){ return ( x < -eps ? -1 : x > eps ); }

struct point {
	double x, y;
	point( ){ }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
	bool operator < ( const point & a ) const {
		if( D( y - a.y ) == 0 ) return D( x - a.x ) < 0;
		return D( y - a.y ) < 0;
	}
	bool operator == ( const point & a ) const {
		return D( x - a.x ) == 0 && D( y - a.y ) == 0;
	}
};

point operator + ( const point &a, const point &b ) {
	return point( a.x + b.x, a.y + b.y );
}
point operator - ( const point &a, const point &b ) {
	return point( a.x - b.x, a.y - b.y );
}
point operator * ( const point &a, const double scale ) {
	return point( a.x * scale, a.y * scale );
}
point operator / ( const point &a, const double scale ) {
	return point( a.x / scale, a.y / scale );
}
double operator ^ ( const point &a, const point &b ) {
	return a.x * b.y - a.y * b.x;
}
double operator & ( const point &a, const point &b ) {
	return a.x * b.x + a.y * b.y;
}

bool line_cross_seg( const point &a, const point &b, const point &c, const point &d ) {
	int t1 = D( b - a ^ d - a );
	int t2 = D( b - a ^ c - a );
	if( t1 == 0 || t2 == 0 ) return true;
	return t1 * t2 < 0;
}

vector<point> poly[ 12 ];
vector<point> pnt;

bool check1( const point &a, const point &b, const vector<point> & ply ) {
	int sz = ply.size( );
	for( int i = 0; i < sz; i++ ) {
		if( line_cross_seg( a, b, ply[ i ], ply[ ( i + 1 ) % sz ] ) ) {
			return true;
		}
	}
	return false;
}

int check( const point &a, const point &b, int n ) {
	int cnt = 0;
	for( int i = 0; i < n; i++ ) {
		if( check1( a, b, poly[ i ] ) ) {
			cnt++;
		}
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	int cas, n, k;
	double x, y;
	point tmp;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &n );
		pnt.clear( );
		for( int i = 0; i < n; i++ ) {
			poly[ i ].clear( );
			scanf( "%d", &k );
			for( int j = 0; j < k ; j++ ) {
				tmp.input( );
				pnt.push_back( tmp );
				poly[ i ].push_back( tmp );
			}
		}
		int sz = pnt.size( );
		int ans = 0;
		for( int i = 0; i < sz; i++ ) {
			for( int j = i + 1; j < sz; j++ ) {
				int tmp = check( pnt[ i ], pnt[ j ], n );
				if( tmp > ans ) {
					ans = tmp;
				}
			}
		}
		printf( "Case %d: %d\n", t, ans );
	}
	return 0;
}
