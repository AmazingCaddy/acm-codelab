/*
	author: AmazingCaddy
	time: 2011/4/10  15:16
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
const double eps = 1e-8;
struct point
{
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

point operator + ( const point &p1, const point &p2 )
{
	return point( p1.x + p2.x, p1.y + p2.y );
}
point operator - ( const point &p1, const point &p2 )
{
	return point( p1.x - p2.x, p1.y - p2.y );
}
point operator *( const point &p, double x )
{
	return point( p.x * x, p.y * x );
}
point operator / ( const point &p, double x )
{
	return point( p.x / x, p.y / x );
}

double operator&( const point &p1, const point &p2 )
{
	return ( p1.x * p2.x + p1.y * p2.y );
}

double operator ^( const point &p1, const point &p2 )
{
	return ( p1.x * p2.y - p1.y * p2.x );
}

point segment_cross( point a, point b, point c, point d )
{
	double s = ( d - a ) ^ ( c - a );
	double t = ( c - b ) ^ ( d - b );
	return a + ( b - a ) * s / ( s + t );
}

int main(int argc, char *argv[])
{
	point a, b, c, d;
	int cas;
	while( scanf( "%d", &cas ) != EOF )
	{
		printf( "INTERSECTING LINES OUTPUT\n" );
		while( cas-- )
		{
			a.input( );
			b.input( );
			c.input( );
			d.input( );
			if( D( ( b - a ) ^ ( d - c ) ) == 0 )
			{
				if( D( ( b - a ) ^ ( c - a ) ) == 0 )
					printf( "LINE\n" );
				else printf( "NONE\n" );
			}
			else
			{
				point ans = segment_cross( a, b, c, d );
				printf( "POINT %.2lf %.2lf\n", ans.x, ans.y );
			}
		}
		printf( "END OF OUTPUT\n" );
	}
	return 0;
}
