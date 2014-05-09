/*
	author: AmazingCaddy
	time: 2011/5/5  18:06
	旋转卡壳，求凸多边形的最小面积外接矩形
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

const int maxn = 1004;

const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;
const double dx[ ] = { 100, 0, -100, 0 };
const double dy[ ] = { 0, 100, 0, -100 };

struct point
{
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

double operator ^ ( const point &p1, const point &p2 )
{
	return p1.x * p2.y - p1.y * p2.x;
}

double operator & ( const point &p1, const point &p2 )
{
	return p1.x * p2.x + p1.y * p2.y;
}

point operator + ( const point &p1, const point &p2 )
{
	return point( p1.x + p2.x, p1.y + p2.y );
}

point operator - ( const point &p1, const point &p2 )
{
	return point( p1.x - p2.x, p1.y - p2.y );
}

point operator * ( const point &p, const double &scale )
{
	return point( p.x * scale, p.y * scale );
}

point operator / ( const point &p, const double &scale )
{
	return point( p.x / scale, p.y / scale );
}

point segcross ( const point &a, const point &b, const point &c, const point &d )
{
	double t = ( d - a ) ^ ( c - a );
	double s = ( c - b ) ^ ( d - b );
	return a + ( b - a ) * t / ( t + s );
}

double dis( const point &p1, const point &p2 )
{
	point p = p2 - p1;
	return sqrt( p.x * p.x + p.y * p.y );
}

point rotate( const point &p1, const point &p2, double angle )
{
	point tmp = p2 - p1;
	return point( tmp.x * cos( angle ) - tmp.y * sin( angle ),
		tmp.y * cos( angle ) + tmp.x * sin( angle ) );
}

point np[ maxn ];
point p[ maxn ];

bool cmp( const point &a, const point &b )
{
	if( D( a.y - b.y ) == 0 ) return D( a.x - b.x ) < 0;
	return D( a.y - b.y ) < 0;
}

void convex_hull( int &n )
{
	int sz = n, top;
	sort( np, np + sz, cmp );
	top = 0;
	for( int i = 0; i < sz; i++ )
	{
		while( top >= 2 && D( p[ top - 1 ] - p[ top - 2 ] ^ np[ i ] - p[ top - 2 ] ) <= 0 )
			top--;
		p[ top++ ] = np[ i ];
	}

	int k = top;
	for( int i = sz - 2; i >= 0; i-- )
	{
		while( top > k && D( p[ top - 1 ] - p[ top - 2 ] ^ np[ i ] - p[ top - 2 ] ) <= 0 )
			top--;
		p[ top++ ] = np[ i ];
	}
	top--;
	n = top;
}

double RC( int n )
{
	double xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
	int f[ 4 ] = { 0 };
	for( int i = 0; i < n; i++ )
	{
		if( p[ i ].y < p[ f[ 0 ] ].y ) f[ 0 ] = i, ymin = p[ i ].y;
		if( p[ i ].x > p[ f[ 1 ] ].x ) f[ 1 ] = i, xmax = p[ i ].x;
		if( p[ i ].y > p[ f[ 2 ] ].y ) f[ 2 ] = i, ymax = p[ i ].y;	
		if( p[ i ].x < p[ f[ 3 ] ].x ) f[ 3 ] = i, xmin = p[ i ].x;
	}

	p[ n ] = p[ 0 ];
	point p0[ 4 ], p1[ 4 ], tmp1, tmp2;
	double angle[ 4 ], sum = 0, MinAngle;
	int k;

	for( int i = 0; i < 4; i++ )
	{
		p0[ i ] = p[ f[ i ] ];
		p1[ i ] = p0[ i ] + point( dx[ i ], dy[ i ] );
	}

	double ans = inf;
	while( sum <= 2 * pi )
	{
		MinAngle = 2 * pi;
		k = 0;
		for( int i = 0; i < 4; i++ )
		{
			tmp1 = p1[ i ] - p0[ i ];
			tmp2 = p[ f[ i ] + 1 ] - p[ f[ i ] ];
			angle[ i ] = atan2( tmp1 ^ tmp2, tmp1 & tmp2 );
			if( angle[ i ] < MinAngle ) k = i, MinAngle = angle[ i ];
		}
		sum += MinAngle;
		for( int i = 0; i < 4; i++ )
		{
			if( i == k )
			{
				point a = p[ f[ k ] + 1 ] - p[ f[ k ] ];
				f[ k ] = ( f[ k ] + 1 ) % n;
				p0[ k ] = p[ f[ k ] ];
				p1[ k ] = p[ f[ k ] ] + a;
			}
			else
			{
				p1[ i ] = p0[ i ] + rotate( p0[ i ], p1[ i ], MinAngle );
			}
		}
		point pp[ 3 ];
		for( int i = 0; i < 3; i++ )
		{
			pp[ i ] = segcross( p0[ i ], p1[ i ], p0[ i + 1 ], p1[ i + 1 ] );
		}
		double area = dis( pp[ 0 ], pp[ 1 ] ) * dis( pp[ 1 ], pp[ 2 ] );

		if( area < ans ) ans = area;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0; i < n; i++ )
			np[ i ].input( );
		convex_hull( n );
		printf( "%.4lf\n", RC( n ) );
	}
	return 0;
}
