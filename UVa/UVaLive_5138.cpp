/*
	author: AmazingCaddy
	time: 
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

const int maxn = 204;
const double pi = acos( -1.0 );
const double inf = 1e50;
const double eps = 1e-8;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point
{
	double x, y;
	point( ){ }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
};

point operator - ( const point &a, const point &b )
{
	return point( a.x - b.x, a.y - b.y );
}

double operator ^ ( const point &a, const point &b )
{
	return a.x * b.y - a.y * b.x;
}

bool cmp( const point &a, const point &b )
{
	return D( a.y - b.y ) < 0 || D( a.y - b.y ) == 0 && D( a.x - b.x ) < 0;
}

double dis( const point &a, const point &b )
{
	point p = a - b;
	return sqrt( p.x * p.x + p.y * p.y );
	//return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

point p[ maxn ], np[ maxn ];

int convex_hull( int n )
{
	sort( p, p + n, cmp );
	int sz = 0;
	for( int i = 0; i < n; i++ )
	{
		while( sz >= 2 && D( np[ sz - 1 ] - np[ sz - 2 ] ^ p[ i ] - np[ sz - 2 ] ) <= 0 )
			sz--;
		np[ sz++ ] = p[ i ];
	}
	int k = sz;
	for( int i = n - 2; i >= 0; i-- )
	{
		while( sz > k && D( np[ sz - 1 ] - np[ sz - 2 ] ^ p[ i ] - np[ sz - 2 ] ) <= 0 )
			sz--;
		np[ sz++ ] = p[ i ];
	}
	sz--;
	return sz;
}

double point_seg( const point &p, const point &a, const point &b )
{
	return fabs( ( p - a ) ^ ( b - a ) ) / dis( a, b );
}

void solve( int k )
{
	int n = convex_hull( k );
	//cout << n << endl;
	//	np[ n ] = np[ 0 ];
	double ans = inf;
	for( int i = 0; i < n; i++ )
	{
		double Max = 0;
		for( int j = 0; j < n; j++ )
		{
			double tmp = point_seg( np[ j ], np[ i ], np[ ( i + 1 ) % n ] );
			if( tmp > Max ) Max = tmp;
		}
		if( Max < ans ) ans = Max;
	}
	printf( "%lf\n", ans );
}

int main(int argc, char *argv[])
{
	int n, cas = 1;
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%lf%lf", &p[ i ].x, &p[ i ].y );
		
		n = convex_hull( n );
		double ans = inf;
		for( int i = 0; i < n; i++ )
		{
			double Max = 0;
			for( int j = 0; j < n; j++ )
			{
				double tmp = point_seg( np[ j ], np[ i ], np[ ( i + 1 ) % n ] );
				if( tmp > Max ) Max = tmp;
			}
			if( Max < ans ) ans = Max;
		}
		
		//printf( "Case %d: %lf\n", cas++, ans );
		printf( "Case %d: ", cas++ );
		solve( n );
	}
	return 0;
}

