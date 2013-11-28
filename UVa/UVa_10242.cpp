/*
	author: AmazingCaddy
	time: 2011/5/22  15:05
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
#include <queue>
using namespace std;

const int maxn = 10;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

struct point
{
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	int input( ) { return scanf( "%lf%lf", &x, &y ); }
};

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

bool operator == ( const point & a, const point & b )
{
	return D( a.x - b.x ) == 0 && D( a.y - b.y ) == 0;
}

point operator + ( const point & a, const point & b )
{
	return point( a.x + b.x, a.y + b.y );
}

point operator - ( const point & a, const point & b )
{
	return point( a.x - b.x, a.y - b.y );
}

point p[ maxn ];

int main(int argc, char *argv[])
{
	point ans;
	while( p[ 0 ].input( ) != EOF )
	{
		for( int i = 1; i < 4; i++ )
			p[ i ].input( );
		if( p[ 0 ] == p[ 2 ] )
		{
			ans = p[ 1 ] + p[ 3 ] - p[ 2 ];
		}
		else if( p[ 0 ] == p[ 3 ] )
		{
			ans = p[ 1 ] + p[ 2 ] - p[ 3 ];
		}
		else if ( p[ 1 ] == p[ 2 ] )
		{
			ans = p[ 0 ] + p[ 3 ] - p[ 2 ];
		}
		else if( p[ 1 ] == p[ 3 ] )
		{
			ans = p[ 0 ] + p[ 2 ] - p[ 3 ];
		}
		printf( "%.3lf %.3lf\n", ans.x, ans.y );
	}
	return 0;
}
