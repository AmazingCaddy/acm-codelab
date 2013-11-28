/*
	author: AmazingCaddy
	time: 2011/4/19  21:14
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

const int maxn = 704;

struct point
{
	int x, y;
	point( ) { }
	point( int _x, int _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%d%d", &x, &y ); }
};

point operator + ( const point & a, const point & b )
{
	return point( a.x + b.x, a.y + b.y );
}

point operator - ( const point & a, const point & b )
{
	return point( a.x - b.x, a.y - b.y );
}

int operator ^ ( const point & a, const point & b )
{
	return a.x * b.y - a.y * b.x;
}

int operator & ( const point & a, const point & b )
{
	return a.x * b.x + a.y * b.y;
}

bool operator == ( const point & a, const point & b )
{
	return a.x == b.x && a.y == b.y;
}

bool cmp( const point & p1, const point & p2 )
{
	return ( p1 ^ p2 ) > 0;
}

int Max( int a, int b ) { return ( a > b ? a : b ); }
point pp1[ maxn ], pp2[ maxn ];

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0; i < n; i++ )
			pp1[ i ].input( );
		int ans = 0;
		for( int i = 0; i < n; i++ )
		{
			int k = 0;
			for( int j = 0; j < n; j++ )
			{
				if( j != i )
				{
					point tmp = pp1[ j ] - pp1[ i ];
					if( tmp.y < 0 ) tmp.x = -tmp.x, tmp.y = -tmp.y;
					pp2[ k++ ] = tmp;
				}
			}
			sort( pp2, pp2 + k, cmp );
			for( int j = 0; j < k; j++ )
				printf( "%d %d\n", pp2[ j ].x, pp2[ j ].y );
			int cnt1 = 1, cnt2 = 0;
			for( int j = 1; j < k; j++ )
			{
				if( ( pp2[ j ] ^ pp2[ j - 1 ] ) == 0 )
				{
					cnt1++;
				}
				else 
				{
					cnt2 = Max( cnt1, cnt2 );
					cnt1 = 1;
				}
			}
			cnt2 = Max( cnt1, cnt2 );
			ans = Max( ans, cnt2 );
		}
		printf( "%d\n", ans + 1 );
	}
	return 0;
}
