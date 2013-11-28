/*
    author: AmazingCaddy
    time: 28/05/2011 14:40:01 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 504;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point
{
	double x, y;
	point( ){ }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
	bool operator == ( const point & a ) const
	{
		return D( x - a.x ) == 0 && D( y - a.y ) == 0;
	}
	bool operator < ( const point & a ) const
	{
		if( D( x - a.x ) == 0 ) return D( y - a.y ) < 0;
		return D( x - a.x ) < 0;
	}
};

map< point, int > mm;

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
	return point ( a.x * scale, a.y * scale );
}

point operator / ( const point & a, const double scale )
{
	return point ( a.x / scale, a.y / scale );
}

double operator ^ ( const point & a, const point & b )
{
	return a.x * b.y - a.y * b.x;
}

double operator & ( const point & a, const point & b )
{
	return a.x * b.x + a.y * b.y;
}

bool same_point( const point &a, const point & b )
{
	return D( a.x - b.x ) == 0 && D( a.y - b.y ) == 0;
}

point p[ maxn ];
// ok
point seg_cross( const point &a, const point &b, const point &c, const point &d )
{
	double s = ( c - a ) ^ ( d - a );
	double t = ( d - b ) ^ ( c - b );
	return a + ( b - a ) * s / ( s + t );
}
// ok
point opp_point( const point & a, const point & b, const point & p )
{
	point r = b - a;
	point q = point( -r.y, r.x ) + p;
	r = seg_cross( a, b, p, q );
	return r - p + r;
}

void getline( const point & a, const point & b, point & p1, point &p2 )
{
	p1 = ( a + b ) / 2.0;
	p2 = p1 + point( a.y - b.y, b.x - a.x );
}

int check( const point & a, const point & b, int n )
{
	point q;
	map< point, int >::iterator it;
	for( int i = 0; i < n; i++ )
	{
		q = opp_point( a, b, p[ i ] );
		it = mm.find( q );
		if( it != mm.end( ) )continue;
		else return 0;
	}
	return 1;
}

int solve( int n )
{
	point a, b;
	mm.clear( );
	for( int i = 0; i < n; i++ )
		mm[ p[ i ] ] = 1;
	/*
	for( int i = 0; i < n; i++ )
	{
		getline( p[ i ], p[ i + 1 ], a, b );
		if( check( a, b, n ) ) return 1;
	}
	*/
	point st = p[ 0 ];
	for( int i = 1; i < n; i++ )
	{
		getline( st, p[ i ], a, b );
		if( check( a, b, n ) ) return 1;
	}
	st = p[ n - 1 ];
	for( int i = 0; i < n - 1; i++ )
	{
		getline( st, p[ i ], a, b );
		if( check( a, b, n ) ) return 1;
	}
	return 0;
}

const char * answer[ ] = { "NO", "YES" };

int main( int ac, char * av[ ] )
{
	int cas, n;
	//freopen( "B_in", "r", stdin );
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
			p[ i ].input( );
		p[ n ] = p[ 0 ];
		int ans = solve( n );
		printf( "Case %d: %s\n", t, answer[ ans ] );
	}
	return 0;
}

