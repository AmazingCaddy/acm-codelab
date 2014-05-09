/*
	author: AmazingCaddy
	time:	2011-07-07 13:16:30 
	学生和课程进行二分图匹配，匹配数等于课程数，那么YES，否则NO
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

const int maxn = 304;
const int inf = 0x3fffffff;

int nx, ny, g[ maxn ][ maxn ], sy[ maxn ], cx[ maxn ], cy[ maxn ];

int path( int u )
{
	for( int v = 1; v <= ny; v++ )
	{
		if( g[ u ][ v ] && !sy[ v ] )
		{
			sy[ v ] = 1;
			if( !cy[ v ] || path( cy[ v ] ) )
			{
				cx[ u ] = v;
				cy[ v ] = u;
				return 1;
			}
		}
	}
	return 0;
}

int max_match( )
{
	int ret = 0;
	memset( cx, 0, sizeof( cx ) );
	memset( cy, 0, sizeof( cy ) );
	for( int i = 1; i <= nx; i++ )
	{
		memset( sy, 0, sizeof( sy ) );
		ret += path( i );
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int cas, len, x;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d %d", &ny, &nx );
		memset( g, 0, sizeof( g ) );
		for( int i = 1; i <= ny; i++ )
		{
			scanf( "%d", &len );
			for( int j = 0; j < len; j++ )
			{
				scanf( "%d", &x );
				g[ x ][ i ] = 1;
			}
		}
		int ans = max_match( );
		if( ans == ny ) printf( "YES\n" );
		else printf( "NO\n" );
	}
	return 0;
}
