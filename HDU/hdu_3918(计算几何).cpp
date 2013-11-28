/*
	author: AmazingCaddy
	time:	2011-08-04 15:25:53 
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

const int maxn = 204;
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
};

point p[ maxn ], q[ maxn ];
double Y[ maxn << 1 ];

double mass, ypre, ynow;
double x1, x2, x3, x4, Gx, LGx;
int pid, qid;

int myUnique( int n )
{
	int len = 1;
	for( int i = 1; i < n; i++ )
		if( D( Y[ i ] - Y[ i - 1 ] ) != 0 )
			Y[ len++ ] = Y[ i ];
	return len;
}

double insection( double y, const point &a, const point &b )
{
	return ( b.x - a.x ) * ( y - a.y ) / ( b.y - a.y ) + a.x;
}

double get_Gx( double y )
{
	x3 = insection( y, p[ pid - 1 ], p[ pid ] );
	x4 = insection( y, q[ qid - 1 ], q[ qid ] );
	double tmp = ( ( x1 + x2 + x3 ) * ( x2 - x1 ) + ( x2 + x4 + x3 ) * ( x4 - x3 ) ) * ( y - ypre ) / 6;
	tmp = ( tmp + LGx * mass );
	return tmp / ( mass + ( x2 - x1 + x4 - x3 ) * ( y - ypre ) / 2 );
}


int main(int argc, char *argv[])
{
//	freopen( "data.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int cas, n, m;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d%d", &m, &n );
		for( int i = 0; i < m; i++ )
		{
			p[ i ].input( );
			Y[ i ] = p[ i ].y;
		}
		for( int j = 0; j < n; j++ )
		{
			q[ j ].input( );
			Y[ j + m ] = q[ j ].y;
		}
		double ans = min( p[ m - 1 ].y, q[ n - 1 ].y );

		sort( Y, Y + m + n );
		int len = myUnique( m + n );

		pid = 1, qid = 1;

		x1 = p[ 0 ].x, x2 = q[ 0 ].x;
		mass = 0, LGx = 0, ypre = 0;

		for( int i = 1; i < len && D( Y[ i ] - ans ) <= 0; i++ )
		{
			ynow = Y[ i ];
			while( D( p[ pid ].y - ynow ) < 0 ) pid++;
			while( D( q[ qid ].y - ynow ) < 0 ) qid++;

			Gx = get_Gx( ynow );
//			printf( "Gx = %.3lf\n" );
			if( D( Gx - p[ 0 ].x ) < 0 || D( Gx - q[ 0 ].x ) > 0 )
			{
				double l = ypre, r = ynow, mid;
				while( r - l > eps )
				{
					mid = ( l + r ) * 0.5;
					double gx = get_Gx( mid );
					if( D( gx - p[ 0 ].x ) < 0 || D( gx - q[ 0 ].x ) > 0 ) r = mid;
					else l = mid;
				}
				ans = mid;
				break;
			}

			mass = mass + ( x2 - x1 + x4 - x3 ) * ( ynow - ypre ) / 2;
			x1 = x3;
			x2 = x4;
			LGx = Gx;
			ypre = ynow;
		}
		printf( "%.3lf\n", ans );
	}
	return 0;
}