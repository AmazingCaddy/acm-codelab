/*
	author: AmazingCaddy
	time: 2011/7/10  20:44
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

const int maxn = 1000004;
const double eps = 1e-8;

struct point
{
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};
point operator + ( const point &a, const point &b )
{
	return point( a.x + b.x, a.y + b.y );
}

point operator - ( const point &a, const point &b )
{
	return point( a.x - b.x, a.y - b.y );
}

point operator * ( const point &a, const double scale )
{
	return point( a.x * scale, a.y * scale );
}

point operator / ( const point &a, const double scale )
{
	return point( a.x / scale, a.y / scale );
}

double operator ^ ( const point &a, const point &b )
{
	return a.x * b.y - a.y * b.x;
}

double operator & ( const point &a, const point &b )
{
	return a.x * b.x + a.y * b.y;
}

int main(int argc, char *argv[])
{
	int n, cas;
	point now, pre, last;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		pre.input( );
		last = pre;
		point sum = point( 0, 0 );
		double area = 0, sumX = 0, sumY = 0;
		for( int i = 1; i < n; i++ )
		{
			now.input( );
			sum = sum + ( pre + now ) * ( pre ^ now );
			area = area + ( pre ^ now );
			pre = now;
		}
		sum = sum + ( now + last ) * ( now ^ last );
		area = area + ( now ^ last );
		sum = sum / ( area * 3 );
		printf( "%.2lf %.2lf\n", sum.x, sum.y );
	}
	return 0;
}
