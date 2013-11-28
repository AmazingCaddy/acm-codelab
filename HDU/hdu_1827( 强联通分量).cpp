/*
	author: AmazingCaddy
	time: 2011/6/4  14:35
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
const int maxn = 1004;
const int inf = 0x3fffffff;

int head[ maxn ], next[ maxn << 1 ], ev[ maxn << 1 ];
int headt[ maxn ], nextt[ maxn << 1 ], evt[ maxn << 1 ];
int len, lent;

int mk[ maxn ], list[ maxn ];
int ans, color, n, m, num;
int col[ maxn ];
int cost[ maxn ], c[ maxn ], dv[ maxn ];

int Min( int a, int b ) { return ( a < b ? a : b ); }

void init( )
{
	len = lent = 0;
	memset( head, 0, sizeof( head ) );
	memset( headt, 0, sizeof( headt ) );
}

void addedge( int u, int v, int he[ ], int nt[ ], int ev[ ], int &le )
{
	nt[ ++le ] = he[ u ];
	he[ u ] = le;	
	ev[ le ] = v;
}

void back ( int v )
{
	mk[ v ] = 1;
	col[ v ] = color;
	cost[ color ] = Min( cost[ color ], c[ v ] );
	for( int j = headt[ v ]; j ; j = nextt[ j ] )
		if ( !mk[ evt[ j ] ] )
			back( evt[ j ] );
}

void dfs( int u )
{
	mk[ u ] = 1;
	for( int i = head[ u ]; i ; i = next[ i ] )
		if( !mk[ ev[ i ] ] )
			dfs( ev[ i ] );
	list[ num-- ] = u;
}

void SCC( )
{
	memset( mk, 0, sizeof( mk ) );
	num = n;
	for( int i = 1; i <= n; i++ )
		if( !mk[ i ] ) dfs( i );
	for( int i = 1; i <= n; i++ )
		cost[ i ] = inf, mk[ i ] = 0, col[ i ] = 0;
	color = 0;
	for( int i = 1; i <= n; i++ ) 
	{
		if ( !mk[ list[ i ] ] )
		{ 
			color++;
			back( list[ i ] );
		}
	}
	memset( dv, 0, sizeof( dv ) );
	for( int i = 1; i <= n; i++ )
		for( int j = head[ i ]; j; j = next[ j ] )
			if( col[ i ] != col[ ev[ j ] ] )
				dv[ col[ ev[ j ] ] ]++;
	int ans = 0, cnt = 0;
	for( int i = 1; i <= color; i++ )
		if( !dv[ i ] ) cnt++, ans += cost[ i ];
	printf( "%d %d\n", cnt, ans );
}

int main(int argc, char *argv[])
{
	int a, b;
	while( scanf( "%d%d", &n, &m ) != EOF )
	{
		for( int i = 1; i <= n; i++ )
			scanf( "%d", &c[ i ] );
		memset( g, 0, sizeof( g ) );
		init( );
		for( int i = 0; i < m; i++ )
		{
			scanf( "%d%d", &a, &b );
			g[ a ][ b ] = 1;
			addedge( a, b, head, next, ev, len );
			addedge( b, a, headt, nextt, evt, lent );
		}
		SCC( );
	}
	return 0;
}
