/*
	author: AmazingCaddy
	time: 2011/4/21  16:13 ~ 16:31
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

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

struct point
{
	double x, y;
	point( double _x, double _y ): x( _x ), y( _y ) { }
	point( ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

point operator + ( const point & a, const point & b ) 
{
	return point( a.x + b.x, a.y + b.y );
}

point operator - ( const point & a, const point & b )
{
	return point( a.x - b.x, a.y - b.y );
}

point operator * ( const point & a, const double scale )
{
	return point( a.x * scale, a.y * scale );
}

point operator / ( const point & a, const double scale )
{
	return point( a.x / scale, a.y / scale );
}

double operator ^ ( const point & a, const point & b )
{
	return a.x * b.y - a.y * b.x;
}

double operator & ( const point & a, const point & b )
{
	return a.x * b.x + a.y * b.y;
}

point segcross( const point &a, const point &b, const point &c, const point &d )
{
	double s = ( d - a ) ^ ( c - a );
	double t = ( c - b ) ^ ( d - b );
	return a + ( b - a ) * s / ( t + s );
}

int main(int argc, char *argv[])
{
	point mir1, mir2, st, ed;
	int cas;
	scanf( "%d", &cas );
	while( cas-- )
	{
		mir1.input( );
		mir2.input( );
		st.input( );
		ed.input( );
		point p = st;
		p.x += mir2.y - mir1.y;
		p.y += mir1.x - mir2.x;
		point tmp = segcross( mir1, mir2, st, p );
		tmp = tmp + ( tmp - st );
		point ans = segcross( mir1, mir2, tmp, ed );
		printf( "%.3lf %.3lf\n", ans.x, ans.y );
	}
	return 0;
}
