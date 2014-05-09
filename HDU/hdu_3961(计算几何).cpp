/*
	author: AmazingCaddy
	time:	2011-08-24 12:41:52 
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

const int maxn = 10004;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int D( double x ){ return ( x < -eps ? -1 : x > eps ); }

struct point {
	double x, y;
	point( ){ }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
	bool operator < ( const point & a ) const {
		if( D( x - a.x ) == 0 ) return D( y - a.y ) < 0;
		return D( x - a.x ) < 0;
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

double Distance( const point &a, const point &b ) {
	point p = a - b;
	return sqrt( p.x * p.x + p.y * p.y );
}

// 逆时针旋转 angle
point rotate( const point &o, const point &p, const double & angle, const double &scale ) {
	point pp = p - o;
	double cosx = cos( angle ), sinx = sin( angle );
	return o + point( pp.x * cosx - pp.y * sinx, pp.y * cosx + pp.x * sinx ) * scale;
}

point gravity( const vector<point> &poly ) {
	point o( 0.0, 0.0 );
	double area = 0;
	int n = poly.size( );
	for( int i = 0; i < n; i++ ) {
		double tmp = poly[ i ] ^ poly[ ( i + 1 ) % n ];
		area = area + tmp;
		o = o + ( poly[ i ] + poly[ ( i + 1 ) % n ] ) * tmp;
	}
	return o / 3 / area;
}

double get_angle( double angle, double d, double r ) {
	double flag = 1;
	if( angle < 0 ) {
		flag = -1;
		angle = -angle;
	}
	double sina = d / r * sin( angle );
	if( sina > 1 ) { 
		sina = 1;
	}
	return flag * ( asin( sina ) - angle );
}

vector<point> block;

void read( int n ) {
	point tmp;
	block.clear( );
	for( int i = 0; i < n; i++ ) {
		tmp.input( );
		block.push_back( tmp );
	}
	double area = 0;
	for( int i = 0; i < n; i++ ) {
		area = area + ( block[ i ] ^ block[ ( i + 1 ) % n ] );
	}
	if( area < 0 ) {
		reverse( block.begin( ), block.end( ) );
	}
}

point init( int n ) {
	vector<point> np;
	read( n );
	point block_g = gravity( block );
	return block_g;
}

int main(int argc, char *argv[])
{
//	freopen( "in", "r", stdin );
//	freopen( "4017.in.0", "r", stdin );
//	freopen( "out", "w", stdout );
	point sun, earth;
	double r;
	int t1, t2, t, n;	// t1公转 t2自转
	while( sun.input( ), earth.input( ), scanf( "%lf", &r ) != EOF ) {
		scanf( "%d%d%d%d", &n, &t1, &t2, &t );
		point block_g = init( n );
		double angle1 = ( t % t1 ) * 1.0 / t1 * pi * 2;
		double angle2 = ( t % t2 ) * 1.0 / t2 * pi * 2;
		
		// 自转和公转之后的block
		point new_block_g = rotate( earth, block_g, angle1, 1 );
		n = block.size( );
		for( int i = 0; i < n; i++ ) {
			block[ i ] = rotate( block_g, block[ i ], angle2, 1 ) - block_g + new_block_g;
		}
		double sedis = Distance( sun, earth );
		double angle = acos( r / sedis );
		double angle_re = pi / 2 - angle;
		double ans;
		// block 在地球的背面
		if( D( new_block_g - earth & sun - earth ) <= 0 ) {
			ans = 2 * angle * r;
			printf( "%lf\n", ans );
			continue;
		}
		point up = block[ 0 ], down = block[ 0 ];
		for( int i = 1; i < block.size( ); i++ ) {
			if( D( block[ i ] - sun ^ up - sun ) < 0 ) { 
				up = block[ i ];
			}
			if( D( block[ i ] - sun ^ down - sun ) > 0 ) { 
				down = block[ i ];
			}
		}
		double upangle = acos( ( up - sun & earth - sun ) / sedis / Distance( up, sun ) );
		double downangle = acos( ( down - sun & earth - sun ) / sedis / Distance( down, sun ) );
		if( D( up - sun ^ earth - sun ) > 0 ) upangle = -upangle;
		if( D( down - sun ^ earth - sun ) > 0 ) downangle = -downangle;
		double upa = min( angle_re, upangle );
		double downa = max( -angle_re, downangle );
		if( upa < downa ) {
			ans = 2 * angle * r;
			printf( "%lf\n", ans );
			continue;
		}
		ans = ( 2 * angle - get_angle( upa, sedis, r ) + get_angle( downa, sedis, r ) ) * r;
		printf( "%lf\n", ans );
	}
	return 0;
}
