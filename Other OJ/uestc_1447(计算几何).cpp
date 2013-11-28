/*
	author: AmazingCaddy
	time: 2011/5/9  15:37

	显然这个简单多边形一定在凸包上, 而且要么为四边形要么为三角形.
	那就先求凸包,接下来枚举起点,和它组成底边的顶点从这个下一出发,
	沿着逆时针旋转 第三个点总保持和底边最大的高度,
	第二点旋转同时,它也旋转,在此过程中用dp[ i ][ j ]记录以节点i,j连线为底边,
	第三个点在(i, j) 左边的最大三角形面积
	就是 max( dp[ i ][ j ] + dp[ j ][ i ] )
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

struct point
{
	int x, y;
	point( ) { }
	point( int _x, int _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%d%d", &x, &y ); }
};

point operator + ( const point &a, const point &b )
{
	return point( a.x + b.x, a.y + b.y );
}

point operator - ( const point &a, const point &b )
{
	return point( a.x - b.x, a.y - b.y );
}

int operator ^ ( const point &a, const point &b )
{
	return a.x * b.y - a.y * b.x;
}

int operator & ( const point &a, const point &b )
{
	return a.x * b.x + a.y * b.y;
}

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

int dp[ maxn ][ maxn ];

int main(int argc, char *argv[])
{
	int cas, n;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
			p[ i ].input( );
		n = convex_hull( n );

		for( int i = n; i < 2 * n; i++ )
			np[ i ] = np[ i - n ];

		for( int i = 0; i < n; i++ )
		{
			int k = i + 1;
			for( int j = i + 1; j < i + n; j++ )
			{
				while( k < i + n && cal( i, j, k + 1 ) > cal( i, j, k ) )k++;
				dp[ i ][ j % n ] = cal( i, j, k );
			}
		}
		int ans = 0;
		for( int i = 0; i < n; i++ )
			for( int j = i + 1; j < n; j++ )
				ans = Max( ans, dp[ i ][ j ] + dp[ j ][ i ] );
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
