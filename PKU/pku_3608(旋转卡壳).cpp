#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 50100;
const double eps = 1e-8;
const double pi = acos( -1.0 );
const double inf = 1e100;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
struct point {
	double x, y;
	point( double _x = 0, double _y = 0 ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

point operator + ( const point & a, const point & b ) {
	return point( a.x + b.x, a.y + b.y );
}
point operator - ( const point & a, const point & b ) {
	return point( a.x - b.x, a.y - b.y );
}
point operator * ( const point & a, const double scale ) {
	return point( a.x * scale, a.y * scale );
}
point operator / ( const point & a, const double scale ) {
	return point( a.x / scale, a.y / scale );
}
double operator ^ ( const point & a, const point & b ) {
	return ( a.x * b.y - a.y * b.x );
}
double operator & ( const point & a, const point & b ) {
	return ( a.x * b.x + a.y * b.y );
}
double dis2( const point & a, const point & b ) {
	point p = a - b;
	return ( p.x * p.x + p.y * p.y );
}
double dis( const point & a, const point & b ) {
	return sqrt( dis2( a, b ) );
}
double displ( const point & a, const point & b, const point & p ) {
	if( D( b - a & p - a ) > 0 && D( a - b & p - b ) > 0 ) {
		return fabs( a - p ^ b - p ) / dis( a, b );
	}
	return min( dis( p, a ), dis( p, b ) );
}
double disll( const point & a, const point &b, const point &c, const point &d ) {
	return min( min( displ( a, b, c ), displ( a, b, d ) ),
	 			min( displ( c, d, a ), displ( c, d, b ) ) );
}

struct poly {
	int n;
	point p[ maxn ];
	void in( ) {
		for( int i = 0; i < n; i++ ) {
			p[ i ].input( );
		}
		if( get_area( ) < 0 ) {
			reverse( p, p + n );
		}
	}
	double get_area( ) const {
		double area = 0;
		for( int i = 0; i < n; i++ ) {
			area += ( p[ i ] ^ p[ ( i + 1 ) % n ] );
		}
		return area;
	}
};

void solve( const poly & g1, const poly & g2 ) {
	int f[ 2 ] = { 0, 0 };
	point p0, p1, p2, p3;
	for( int i = 0; i < g1.n; i++ ) {
		if( g1.p[ i ].y < g1.p[ f[ 0 ] ].y ) {
			f[ 0 ] = i;
		}
	}
	for( int i = 0; i < g2.n; i++ ) {
		if( g2.p[ i ].y > g2.p[ f[ 1 ] ].y ) {
			f[ 1 ] = i;
		}
	}
	int cnt = 0;
	double best = inf;
	while( cnt < g1.n ) {
		p0 = g1.p[ f[ 0 ] ], p1 = g1.p[ ( f[ 0 ] + 1 ) % g1.n ];
		p2 = g2.p[ f[ 1 ] ], p3 = g2.p[ ( f[ 1 ] + 1 ) % g2.n ];
		int tmp = D( p1 - p0 ^ p3 - p2 );
		if( tmp == 0 ) {
			cnt++;
			f[ 0 ] = ( f[ 0 ] + 1 ) % g1.n;
			f[ 1 ] = ( f[ 1 ] + 1 ) % g2.n;
			best = min( best, disll( p0, p1, p2, p3 ) );
		}
		else if( tmp < 0 ) {
			cnt++;
			f[ 0 ] = ( f[ 0 ] + 1 ) % g1.n;
			best = min( best, displ( p0, p1, p2 ) );
		}
		else {
			f[ 1 ] = ( f[ 1 ] + 1 ) % g2.n;
			best = min( best, displ( p2, p3, p0 ) );	
		}
	}
	printf( "%.8lf\n", best );
}

poly g1, g2;
int main( ) {
	while( scanf( "%d%d", &g1.n, &g2.n ) && ( g1.n + g2.n ) ) {
		g1.in( );
		g2.in( );
		solve( g1, g2 );
	}	
	return 0;
}