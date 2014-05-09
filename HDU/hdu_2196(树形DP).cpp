/*
	author: AmazingCaddy
	time: 2011/5/11  0:44
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
const int maxn = 10004;

int head[ maxn ], next[ maxn << 1 ], ev[ maxn << 1 ], ew[ maxn << 1 ];
int len;
int f[ maxn ], g[ maxn ], h[ maxn ]; // 最优 次优 来自父节点
int vis[ maxn ], lst[ maxn ];

int Max( int a, int b ) { return ( a > b ? a : b ); }

void init( )
{
	len = 0;
	memset( head, 0, sizeof( head ) );
	memset( f, 0, sizeof( f ) );
	memset( g, 0, sizeof( g ) );
	memset( h, 0, sizeof( h ) );
	memset( lst, -1, sizeof( lst ) );
}

void addedge( int u, int v, int val )
{
	next[ ++len ] = head[ u ];
	head[ u ] = len;
	ev[ len ] = v;
	ew[ len ] = val;
}

void dfs( int u )
{
	vis[ u ] = 1;
	if( head[ u ] == 0 ) return;
	int best = -1, besti;
	for( int i = head[ u ]; i; i = next[ i ] )
	{
		int v = ev[ i ];
		dfs( v );
		if( best < f[ v ] + ew[ i ] )
		{
			best = f[ v ] + ew[ i ];
			besti = v;
		}
	}
	lst[ u ] = besti;
	f[ u ] = best;
	int best1 = -1;
	for( int i = head[ u ]; i; i = next[ i ] )
	{
		int v = ev[ i ];
		if( v != besti && f[ v ] + ew[ i ] > best1 )
			best1 = f[ v ] + ew[ i ];
	}
	if( best1 != -1 ) g[ u ] = best1;
}

void DFS( int u )
{
	for( int i = head[ u ]; i; i = next[ i ] )
	{
		int v = ev[ i ];
		if( v == lst[ u ] ) h[ v ] = Max( h[ u ], g[ u ] ) + ew[ i ];
		else h[ v ] = Max( h[ u ], f[ u ] ) + ew[ i ];
		DFS( v );
	}
}

int main(int argc, char *argv[])
{
	int n, a, b;
	while( scanf( "%d", &n ) != EOF )
	{
		init( );
		for( int i = 2; i <= n; i++ )
		{
			scanf( "%d%d", &a, &b );
			addedge( a, i, b );
		}
		dfs( 1 );
		DFS( 1 );
		for( int i = 1; i <= n; i++ )
			printf( "%d\n", Max( h[ i ], Max( f[ i ], g[ i ] ) ) );
	}
	return 0;
}
