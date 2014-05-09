/*
	author: AmazingCaddy
	time:	2011/8/1  20:53
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 10004;
const double eps = 1e-8;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point
{
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	double len2( ) { return sqrt( x * x + y * y ); }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

point operator + ( const point &a, const point &b ) { return point( a.x + b.x, a.y + b.y ); }
point operator - ( const point &a, const point &b ) { return point( a.x - b.x, a.y - b.y ); }
point operator * ( const point &a, const double &scale ) { return point( a.x * scale, a.y * scale ); }
point operator / ( const point &a, const double &scale ) { return point( a.x / scale, a.y / scale ); }
double operator ^ ( const point &a, const point &b ) { return ( a.x * b.y - a.y * b.x ); }
double operator & ( const point &a, const point &b ) { return ( a.x * b.x + a.y * b.y ); }

bool operator == ( const point &a, const point &b )
{
	return ( D( a.x - b.x ) == 0 && D( a.y - b.y ) == 0 );
}

point seg_cross( const point &a, const point &b, const point &c, const point &d )
{
	double t = d - a ^ c - a;
	double s = c - b ^ d - b;
	return a + ( b - a ) * t / ( s + t );
}

point base;

struct INFO
{
	point st, ed;
	int flag;	// 0起点，1终点
	int sgid;	// 线段ID
	INFO( ) { }
	INFO( point _st, point _ed, int _flag, int _sgid ) : 
		st( _st ), ed( _ed ), flag( _flag ), sgid( _sgid ) { }
	bool operator < ( const INFO & b ) const
	{
		point p1 = seg_cross( st, ed, point( 0.0, 0.0 ), base );
		point p2 = seg_cross( b.st, b.ed, point( 0.0, 0.0 ), base );
		return p1.len2( ) < p2.len2( );
	}
	bool operator == ( const INFO &b ) const
	{
		return st == b.st && ed == b.ed;
	}
};

bool cmp( const INFO &a, const INFO &b )
{
	return atan2( a.st.y, a.st.x ) < atan2( b.st.y, b.st.x );
}

INFO idx[ maxn << 1 ];
set<INFO> seg;
bool vis[ maxn ];

int main(int argc, char *argv[])
{
//	freopen( "data.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int n;
	point a, b, origin;
	while( scanf( "%d", &n ) != EOF )
	{
		origin.input( );
		n <<= 1;
		for( int i = 0; i < n; i += 2 )
		{
			a.input( );
			b.input( );
			a = a - origin;
			b = b - origin;
			if( D( a ^ b ) < 0 ) swap( a, b );
			idx[ i ] = INFO( a, b, 0, i >> 1 );
			idx[ i + 1 ] = INFO( b, a, 1, i >> 1 );
		}
		sort( idx, idx + n, cmp );

		seg.clear( );
		for( int i = 0; i < n; i++ )
		{
			base = idx[ i ].st;
			if( idx[ i ].flag == 0 &&
				atan2( idx[ i ].st.y, idx[ i ].st.x ) > atan2( idx[ i ].ed.y, idx[ i ].ed.x ) )
				seg.insert( idx[ i ] );
		}
		memset( vis, false, sizeof( vis ) );
		for( int i = 0; i < n; i++ )
		{
			base = idx[ i ].st;
			if( idx[ i ].flag == 0 ) seg.insert( idx[ i ] );
			else seg.erase( INFO( idx[ i ].ed, idx[ i ].st, 0, idx[ i ].sgid ) );
			if( !seg.empty( ) ) vis[ seg.begin( ) -> sgid ] = true;
		}
		n >>= 1;
		int ans = 0;
		for( int i = 0; i < n; i++ )
			ans += vis[ i ];
		printf( "%d\n", ans );
	}
	return 0;
}
