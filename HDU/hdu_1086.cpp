/*
	author: AmazingCaddy
	time:	2011-07-07 16:31:35 
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
#define lowbit(x) ((x)&(-(x)))

const int maxn = 104;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int D( double x ){ return ( x < -eps ? -1 : x > eps ); }

struct point
{
	double x, y;
	point( ){ }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
	bool operator < ( const point & a ) const
	{
		if( D( y - a.y ) == 0 ) return D( x - a.x ) < 0;
		return D( y - a.y ) < 0;
	}
	bool operator == ( const point & a ) const
	{
		return D( x - a.x ) == 0 && D( y - a.y ) == 0;
	}
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

struct line
{
	point a, b;
};
line l[ maxn ];

int between( point p, point a, point b )
{
	return D( a - p & b - p );
}

int cross( point a, point b, point c, point d )
{
	double s1, s2, s3, s4;
	int d1, d2, d3, d4;
	d1 = D( s1 = ( b - a ^ c - a ) );
	d2 = D( s2 = ( b - a ^ d - a ) );
	d3 = D( s3 = ( d - c ^ a - c ) );
	d4 = D( s4 = ( d - c ^ b - c ) );
	
	if( ( d1 ^ d2 ) == -2 && ( d3 ^ d4 ) == -2 ) return 1;
	
	if( d1 == 0 && between( c, a, b ) <= 0 ||
		d2 == 0 && between( d, a, b ) <= 0 ||
		d3 == 0 && between( a, c, d ) <= 0 ||
		d4 == 0 && between( b, c, d ) <= 0 ) return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0 ; i < n; i++ )
		{
			l[ i ].a.input( );
			l[ i ].b.input( );
		}
		int ans = 0;
		for( int i = 0; i < n; i++ )
		{
			for( int j = i + 1; j < n; j++ )
			{
				if( cross( l[ i ].a, l[ i ].b, l[ j ].a, l[ j ].b ) )
					ans++;
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}
