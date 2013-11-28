/*
	author: AmazingCaddy
	time:	2011/7/30  15:08
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

//typedef __int64 ll;
typedef long long ll;

const int maxn = 100004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point
{
	double x, y;
	double angle;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { angle = atan2( y, x ); }
	bool operator < ( const point &b ) const { return angle < b.angle; }
	void input( ) { scanf( "%lf%lf", &x, &y ); angle = atan2( y, x ); }
};

point operator + ( const point &a, const point &b ) { return point( a.x + b.x, a.y + b.y ); }
point operator - ( const point &a, const point &b ) { return point( a.x - b.x, a.y - b.y ); }
point operator * ( const point &a, const double &scale ) { return point( a.x * scale, a.y * scale ); }
point operator / ( const point &a, const double &scale ) { return point( a.x / scale, a.y / scale ); }
double operator ^ ( const point &a, const point &b ) { return ( a.x * b.y - a.y * b.x ); }
double operator & ( const point &a, const point &b ) { return ( a.x * b.x + a.y * b.y ); }

// ÄæÊ±ÕëÐý×ª
point rotate( const point &p, const double &angle )
{
	double sinx = sin( angle ), cosx = cos( angle );
	return point( p.x * cosx - p.y * sinx, p.y * cosx + p.x * sinx );
}

point p[ maxn ];

int main(int argc, char *argv[])
{
//	freopen( "data.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int cas, n;
	scanf( "%d", &cas );
	while( cas -- )
	{
		double angle;
		scanf( "%d", &n );
		p[ 0 ] = point( 1, 0 );
		for( int i = 1; i <= n; i++ )
		{
			scanf( "%lf", &angle );
			angle = -angle / 180 * pi;
			p[ i ] = rotate( p[ i - 1 ], angle );
		}
		n++;
		if( n == 2 )
		{
			if( D( angle - pi ) == 0 || D( angle + pi ) == 0 )
				printf( "Yes\n" );
			else printf( "No\n" );
			continue;
		}
		sort( p, p + n );
		int flag = 0;
		for( int i = 1; i < n; i++ )
		{
			if( D( p[ i ].angle - p[ i - 1 ].angle - pi ) >= 0 )
			{
				flag = 1;
				break;
			}
		}
		if( D( p[ 0 ].angle + 2 * pi - p[ n - 1 ].angle - pi ) >= 0 ) flag = 1;
		if( flag ) printf( "No\n" );
		else printf( "Yes\n" );
	}
	return 0;
}
