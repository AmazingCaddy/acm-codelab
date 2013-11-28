/*
	author: AmazingCaddy
	time: 2011/5/9  15:37
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
typedef long long ll;

const int maxn = 50004;

struct point
{
	ll x, y;
	point( ) { }
	point( ll _x, ll _y ) : x( _x ), y( _y ) { }
	//void input( ) { scanf( "%lld%lld", &x, &y ); }
	void input( ) { scanf( "%I64d%I64d", &x, &y ); }
};
 
point operator + ( const point &a, const point &b ) { return point( a.x + b.x, a.y + b.y ); }
point operator - ( const point &a, const point &b ) { return point( a.x - b.x, a.y - b.y ); }
ll operator ^ ( const point &a, const point &b ) { return a.x * b.y - a.y * b.x; }
ll operator & ( const point &a, const point &b ) { return a.x * b.x + a.y * b.y; }

int Max( int a, int b ) { return ( a > b ? a : b ); }

point p[ maxn ], np[ maxn << 1 ];

bool cmp( const point &a, const point &b )
{
	if( a.y == b.y ) return a.x < b.x;
	return a.y < b.y;
}

int convex_hull( int n )
{
	sort( p, p + n, cmp );
	int top = 0;
	for( int i = 0; i < n; i++ )
	{
		while( top >= 2 && ( np[ top - 1 ] - np[ top - 2 ] ^ p[ i ] - np[ top - 2 ] ) <= 0 ) top--;
		np[ top++ ] = p[ i ];
	}
	int k = top;
	for( int i = n - 2; i >= 0; i-- )
	{
		while( top > k && ( np[ top - 1 ] - np[ top - 2 ] ^ p[ i ] - np[ top -2 ] ) <= 0 ) top--;
		np[ top++ ] = p[ i ];
	}
	top--;
	return top;
}

int cal( int i, int j, int k )
{
	return np[ j ] - np[ i ] ^ np[ k ] - np[ i ];
}

//int dp[ maxn ][ maxn ];

int main(int argc, char *argv[])
{
	int cas, n;
	//scanf( "%d", &cas );
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 0; i < n; i++ )
			p[ i ].input( );
		n = convex_hull( n );

		for( int i = n; i < 2 * n; i++ )
			np[ i ] = np[ i - n ];

    	ll ans = 0, tmp;
		for( int i = 0; i < n; i++ )
		{
			int k = i + 1;
			for( int j = i + 1; j < i + n; j++ )
			{
				while( k < i + n - 1 && cal( i, j, k + 1 ) > ( tmp = cal( i, j, k ) ) )k++;
				if( ans < tmp ) ans = tmp;
			}
		}

		if( ans % 2 == 0 ) printf( "%I64d.00\n", ans / 2 );
		else printf( "%I64d.50\n", ans / 2 );
//		if( ans % 2 == 0 ) printf( "%lld.00\n", ans / 2 );
//		else printf( "%lld.50\n", ans / 2 );
	}
	return 0;
}
