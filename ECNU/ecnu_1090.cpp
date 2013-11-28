/*
	author: AmazingCaddy
	time: 2011/4/20  0:17
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

typedef __int64 ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-2;
const double EPS = 1e-6;

const char * s1[ ] = { "Scalene", "Isosceles", "Equilateral" };
const char * s2[ ] = { "Obtuse", "Right", "Acute" };

struct point
{
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
int dblcmp( double x ) { return x < -EPS ? -1 : x > EPS; }

double dis( point a, point b )
{
	return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

int main(int argc, char *argv[])
{
	double x1, y1, x2, y2, x3, y3;
	point a, b, c;
	//freopen( "1090#1.in", "r", stdin );
	//freopen( "1090#1.out", "w", stdout );
	while( scanf( "%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3 ) == 6 )
	{
		a = point( x1, y1 );
		b = point( x2, y2 );
		c = point( x3, y3 );
		double d[ 5 ];
		d[ 0 ] = dis( a, b );
		d[ 1 ] = dis( b, c );
		d[ 2 ] = dis( a, c );
		sort( d, d + 3 );
		if( d[ 0 ] + d[ 1 ] <= d[ 2 ] )
		{
			printf( "Not a Triangle\n" );
			continue;
		}
		int flag = 0;
		if( D( d[ 0 ] - d[ 1 ] ) == 0 || D( d[ 0 ] - d[ 2 ] ) == 0 
			|| D( d[ 1 ] - d[ 2 ] ) == 0 )
		{
			flag = 1;
		}
		if( D( d[ 0 ] - d[ 1 ] ) == 0 && D( d[ 0 ] - d[ 2 ] ) == 0  )
		{
			flag = 2;
		}
		double angle = acos( ( d[ 0 ] * d[ 0 ] + d[ 1 ] * d[ 1 ] - d[ 2 ] * d[ 2 ] ) / ( 2 * d[ 0 ] * d[ 1 ] ) );
		int tmp = D( pi / 2 - angle ) + 1;
		printf( "%s %s\n", s1[ flag ], s2[ tmp ] );
	}
	printf( "End of Output\n" );
	return 0;
}
