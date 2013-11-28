/*
	author: AmazingCaddy
	time:	2011/7/30   17:59
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

const int maxn = 50100;
const int maxm = maxn << 1;

int head[ maxn ], next[ maxm ], ev[ maxm ], wv[ maxm ];
int headt[ maxn ], nextt[ maxm ], evt[ maxm ];
int len, lent;

int n, num, color, list[ maxn ], col[ maxn ], mk[ maxn ];
int cx[ maxn ], cy[ maxn ], sy[ maxn ];

void addedge( int u, int v, int head[ ], int next[ ], int ev[ ], int &len )
{
	next[ ++len ] = head[ u ];
	head[ u ] = len;
	ev[ len ] = v;
}

void Back( int v )
{
	mk[ v ] = 1;
	col[ v ] = color;
	for( int j = headt[ v ]; j; j = nextt[ j ] )
	{
		int u = evt[ j ];
		if( !mk[ u ] )
			Back( u );
	}
}

void DFS( int u )
{
	mk[ u ] = 1;
	for( int i = head[ u ]; i; i = next[ i ] )
	{
		int v = ev[ i ];
		if( !mk[ v ] )
			DFS( v );
	}
	list[ num-- ] = u;
}

void SCC( )
{
	num = n;
	memset( mk, 0, sizeof( mk ) );
	for( int i = 1; i <= n; i++ )
		if( !mk[ i ] ) DFS( i );
	memset( mk, 0, sizeof( mk ) );
	color = 0;
	for( int i = 1; i <= n; i++ )
	{
		if( !mk[ list[ i ] ] )
		{
			color++;
			Back( list[ i ] );
		}
	}
}

int path( int u )
{
	for( int i = headt[ u ]; i; i = nextt[ i ] )
	{
		int v = evt[ i ];
		if( ! sy[ v ] )
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
	for( int i = 1; i <= color; i++ )
	{
		if( !cx[ i ] )
		{
			memset( sy, 0, sizeof( sy ) );
			ret += path( i );
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
//	freopen( "kingdom.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int cas, m, a, b;
	scanf( "%d", &cas );
	//int k = 1;
	while( cas-- )
	{
		//printf( "case %d:\n", k++ );
		scanf( "%d%d", &n, &m );
		len = lent = 0;
		memset( head, 0, sizeof( head ) );
		memset( headt, 0, sizeof( headt ) );
		for( int i = 0; i < m; i++ )
		{
			scanf( "%d%d", &a, &b );
			addedge( a, b, head, next, ev, len );
			addedge( b, a, headt, nextt, evt, lent );
		}
		SCC( );
		//continue;
		lent = 0;
		memset( headt, 0, sizeof( headt ) );
		for( int u = 1; u <= n; u++ )
		{
			for( int j = head[ u ]; j; j = next[ j ] )
			{
				int v = ev[ j ];
				if( col[ u ] != col[ v ] )
				{
					addedge( col[ u ], col[ v ], headt, nextt, evt, lent );
				}
			}
		}
		int ans = color - max_match( );
		printf( "%d\n", ans );
	}
	return 0;
}
