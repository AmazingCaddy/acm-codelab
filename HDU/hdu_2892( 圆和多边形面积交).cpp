/*
	author: AmazingCaddy
	time: 2011/4/23  16:17
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
using namespace std;
typedef complex<double> point;

const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;
const double G = 10;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

double operator ^ ( const point &a, const point &b ) { return imag( conj( a ) * b ); }
double operator & ( const point &a, const point &b ) { return real( conj( a ) * b ); }

point prev( const point & a ) { return a * point( 0.0, 1.0 ) / abs( a ); }

point in( )
{
	double x, y;
	scanf( "%lf%lf", &x, &y );
	return point( x, y );
}

point segcross( const point &a, const point &b, const point &c, const point &d )
{
	double s = ( d - a ) ^ ( c - a );
	double t = ( c - b ) ^ ( d - b );
	return a + ( b - a ) * s / ( s + t );
}

// 计算角aob
double angle( const point &a, const point &b, const point &o )
{
	return atan2( ( a - o ) ^ ( b - o ), ( a - o ) & ( b - o ) );
}

void line_cir_inter( point &l1, point &l2, point &c, double r, vector< point > &p )
{
	point q = segcross( c + prev( l1 - l2 ), c, l1, l2 );
	if( D( r - abs( q - c ) ) == 0 ) p.push_back( q );
	else if( D( r - abs( q - c ) ) > 0 )
	{
		double t = sqrt( r * r - norm( q - c ) ) / abs( l1 - l2 ); // norm is abs 的平方
		p.push_back( q + ( l2 - l1 ) * t );
		p.push_back( q - ( l2 - l1 ) * t );
	}
}

// 判断点a是否在线段bc上，不包括端点
bool point_on_seg( const point &a, const point &b, const point &c )
{
	return D( a - b ^ a - c ) == 0 && D( b - a & c - a ) < 0; 
}

void seg_cir_inter( point &l1, point &l2, point &c, double r, vector<point> &p )
{
	line_cir_inter( l1, l2, c, r, p );
	for( int i = 0; i < p.size( ); i++ )
	{
		if( !point_on_seg( p[ i ], l1, l2 ) )
		{
			int sz = p.size( ) - 1;
			for( int j = i; j < sz; j++ )
				p[ j ] = p[ j + 1 ];
			p.pop_back( );
			i -= 1;
		}
	}
	if( D( abs( l1 - c ) - r ) <= 0 ) p.push_back( l1 );
	if( D( abs( l2 - c ) - r ) <= 0 ) p.push_back( l2 );
}

double tri_cir_area( point &a, point &b, point &c, double r )
{
	vector<point> p;
	seg_cir_inter( a, b, c, r, p );
	double t = fabs( angle( a, b, c ) );
	if( p.size( ) != 2 ) return 0.5 * r * r * t;
	double s = fabs( angle( p[ 0 ], p[ 1 ], c ) );
	return 0.5 * fabs( p[ 0 ] - c ^ p[ 1 ] - c ) + 0.5 * r * r * ( t - s );
}

double poly_cir_area( vector<point>& poly, point c, double r )
{
	double area = 0;
	int sz = poly.size( );
	for( int i = 0; i < sz; i++ )
	{
		double pos = tri_cir_area( poly[ i ], poly[ ( i + 1 ) % sz ], c, r );
		if( D( poly[ ( i + 1 ) % sz ] - c ^ poly[ i ] - c ) > 0 )
			area += pos;
		else area -= pos;
	}
	return fabs( area );
}

int main(int argc, char *argv[])
{
	double x, y, h, R;
	double vx, vy;
	int n;
	vector<point> poly;
	while( scanf( "%lf%lf%lf", &x, &y, &h ) != EOF )
	{
		scanf( "%lf%lf", &vx, &vy );
		scanf( "%lf", &R );
		scanf( "%d", &n );
		poly.clear( );
		double t = sqrt( 2 * h / G );
		point o( x + t * vx, y + t * vy );
		//printf( "%lf %lf\n", real( o ), imag( o ) );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%lf%lf", &x, &y );
			poly.push_back( point( x, y ) );
		}
		double ans = poly_cir_area( poly, o, R );
		printf( "%.2lf\n", ans );
	}
	return 0;
}
