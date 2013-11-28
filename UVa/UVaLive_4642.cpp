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

const int maxn = 10005;
const int inf = 0x3fffffff;
const double eps = 1e-9;
const double pi = acos( -1.0 );

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
struct point {
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	double getlen( ) {
		return sqrt( x * x + y * y );
	}
	void input( ) { scanf( "%lf%lf", &x, &y ); }
	void output( ) { printf( "(%lf,%lf)\n", x, y ); }
};
bool operator == ( const point &a, const point &b ) {
	return D( a.x - b.x ) == 0 && D( a.y - b.y ) == 0;
}
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

double dis2( const point &a, const point &b ) {
	point p = a - b;
	return p.x * p.x + p.y * p.y;
}
double dis( const point &a, const point & b ) {
	return sqrt( dis2( a, b ) );
}

double fix( double x ) { return ( x < 0 ? 0 : x ); }
double R[ 3 ];
point p[ 3 ], zero( 0, 0 ), o;
double a2, a3, b2, b3, c2, c3;
int check( double r, double angleB, double angleC, double bc ) {
	double delta2 = b2 * b2 - 4 * a2 * c2;
	double delta3 = b3 * b3 - 4 * a3 * c3;
	if( delta2 < -eps || delta3 < -eps ) {
		return 1;
	}
	double x2 = ( -b2 + sqrt( fix( delta2 ) ) ) / 2 / a2;
	double x3 = ( -b3 + sqrt( fix( delta3 ) ) ) / 2 / a3;
	if( x2 < -eps || x3 < -eps ) {
		return 1;
	}
	double r2 = x2 * x2, r3 = x3 * x3;
	R[ 1 ] = r2, R[ 2 ] = r3;
	double tmp = r2 / tan(angleB) + r3 / tan(angleC) + 2 * x2 * x3;
	if( tmp < bc ) {
		return 1;
	}
	return 0;
}

void solve( ) {
	double ab = dis( p[ 0 ], p[ 1 ] );
	double bc = dis( p[ 1 ], p[ 2 ] );
	double ca = dis( p[ 2 ], p[ 0 ] );
	double angleA = acos( ( ab * ab + ca * ca - bc * bc ) / ( 2 * ab * ca ) );
	double angleB = acos( ( ab * ab + bc * bc - ca * ca ) / ( 2 * ab * bc ) );
	double angleC = acos( ( bc * bc + ca * ca - ab * ab ) / ( 2 * bc * ca ) );
	angleA /= 2, angleB /= 2, angleC /= 2;
	double l = 0.1, r = max( max( ab, bc ), ca );
	while( r - l > eps ) {
		double mid = (r + l) / 2;
		R[ 0 ] = mid;
		a2 = 1 / tan(angleB), a3 = 1 / tan(angleC);
		b2 = 2 * sqrt(mid), b3 = 2 * sqrt(mid);
		c2 = mid / tan(angleA) - ab, c3 = mid / tan(angleA) - ca;
		if( check( mid, angleB, angleC, bc ) ) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	printf( "%.6lf %.6lf %.6lf\n", R[ 0 ], R[ 1 ], R[ 2 ] );
}

int main(int argc, char *argv[]){
//	freopen( "in.txt", "r", stdin );
//	freopen( "out.txt", "w", stdout );
	while( 1 ) {
		for( int i = 0; i < 3; i++ ) {
			p[ i ].input( );
		}
		if( p[ 0 ] == zero && p[ 1 ] == zero && p[ 2 ] == zero ) {
			break;
		}
		solve( );
	}
	return 0;
}
