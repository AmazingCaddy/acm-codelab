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
using namespace std;
const int maxn = 1004;

int g[ maxn ][ maxn ], n, mk[ maxn ], list[ maxn ], num;
int ans, color;
int col[ maxn ];

void back ( int v )
{
	mk[ v ] = 1;
	//cout << v << " ";
	col[ v ] = color;
	for( int u = 1; u <= n; u++ )
		if ( !mk[ u ] && g[ u ][ v ] )
			back( u );
}

void dfs( int u )
{
	mk[ u ] = 1;
	for( int v = 1; v <= n; v++ )
		if( !mk[ v ] && g[ u ][ v ] )
			dfs( v );
	list[ num-- ] = u;
}

int main(int argc, char *argv[])
{
	int i, j, k, l, m;
	int a, b;
	while( scanf( "%d", &n ) && n )
	{
		scanf( "%d", &m );
		memset( g, 0, sizeof( g ) );
		for( i = 0; i < m; i++ )
		{
			scanf( "%d%d", &a, &b );
			g[ a ][ b ] = 1;
		}
		memset( mk, 0, sizeof( mk ) );
		num = n;
		for( i = 1; i <= n; i++ )
			if( !mk[ i ] ) dfs( i );
		memset( mk, 0, sizeof( mk ) );
		memset( col, 0, sizeof( col ) );
		color = 1;
		for( i = 1; i <= n; i++ ) 
		{
			if ( !mk[ list[ i ] ] )
			{ 
				color++;
				back( list[ i ] );
			}
		}
		ans = 0;
		for( int i = 1; i <= n; i++ )
			for( int j = 1; j <= n; j++ )
				if( g[ i ][ j ] && col[ i ] == col[ j ] ) ans++;
		printf( "%d\n", ans );
	}
	return 0;
}
