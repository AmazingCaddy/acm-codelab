/*
	author: AmazingCaddy
	time:	2011-09-25 17:41:57 
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

const int maxn = 1004;
const double eps = 1e-10;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct node {
	double a, b;
	bool operator < ( const node &seg ) const {
		if( a == seg.a ) {
			return b < seg.b;
		}
		return a < seg.a;
	}
};

node nx[ maxn ], ny[ maxn ];

bool check( int n, int m ) {
	sort( nx, nx + n );
	double l = nx[ 0 ].a, r = nx[ 0 ].b;
	for( int i = 1; i < n; i++ ) {
		if( D( nx[ i ].a - r ) > 0 ) {
			return false;
		}
		if( D( nx[ i ].b - r ) > 0 ) {
			r = nx[ i ].b;
		}
	}
	if( D( l - 0 ) > 0 || D( r - 75 ) < 0 ) {
		return false;
	}
	sort( ny, ny + m );
	l = ny[ 0 ].a, r = ny[ 0 ].b;
	for( int i = 1; i < m; i++ ) {
		if( D( ny[ i ].a - r ) > 0 ) {
			return false;
		}
		if( D( ny[ i ].b - r ) > 0 ) {
			r = ny[ i ].b;
		}
	}
	if( D( l - 0 ) > 0 || D( r - 100 ) < 0 ) {
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int Nx, Ny;
	double width, x, y;
	while( 1 ) {
		scanf( "%d%d%lf", &Nx, &Ny, & width );
		if( Nx == 0 && Ny == 0 && width == 0.0 ) {
			break;
		}
		width /= 2;
		for( int i = 0; i < Nx; i++ ) {
			scanf( "%lf", &x );
			nx[ i ].a = x - width;
			nx[ i ].b = x + width;
		}
		for( int i = 0; i < Ny; i++ ) {
			scanf( "%lf", &y );
			ny[ i ].a = y - width;
			ny[ i ].b = y + width;
		}
		if( check( Nx, Ny ) ) {
			printf( "YES\n" );
		}
		else {
			printf( "NO\n" );
		}
	}
	return 0;
}
