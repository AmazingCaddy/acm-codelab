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
#include <queue>
using namespace std;

//typedef __int64 ll;
typedef long long ll;

const int maxn = 504;

int team[ ][ 8 ] =	{ { 1, 2, 1, 1, 2, 1, 1, 2 },
					  { 1, 2, 1, 1, 3, 1, 1, 1 },
					  { 1, 2, 1, 1, 3, 0, 0, 3 },
					  { 1, 3, 0, 0, 3, 1, 1, 2 },
					  { 1, 3, 0, 0, 4, 1, 1, 1 },
					  { 1, 3, 1, 1, 3, 0, 0, 2 },
					  { 1, 4, 1, 1, 3, 0, 0, 1 }
					};
struct PLAYER
{
	string name;
	int pos[ 8 ];
};
PLAYER p[ maxn ];


int cx[ maxn ], cy[ maxn ], sx[ maxn ], sy[ maxn ], lx[ maxn ], ly[ maxn ];
int nx, ny, match, g[ 12 ][ maxn ];

int path( int u )
{
	sx[ u ] = 1; 
	for( int v = 1; v <= ny; v++ ) 
	{
		if( g[ u ][ v ] == lx[ u ] + ly[ v ] && !sy[ v ] )
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

void KuhnMunkres( )
{
	int i, j, u, min;
	memset( lx, 0, sizeof( lx ) );	memset( ly, 0, sizeof( ly ) );
	memset( cx, 0, sizeof( cx ) );	memset( cy, 0, sizeof( cy ) );
	for( i = 1; i <= nx; i++ )
		for( j = 1; j <= ny; j++ )
			if( lx[ i ] < g[ i ][ j ] ) lx[ i ] = g[ i ][ j ];
	for( u = 1; u <= nx; u++ )
	{
		if( !cx[ u ] )
		{
			memset( sx, 0, sizeof( sx ) );
			memset( sy, 0, sizeof( sy ) );
			while( !path( u ) )
			{
				min = 0x3fffffff;
				for( i = 1; i <= nx; i++ )
					if( sx[ i ] )
						for( j = 1; j <= ny; j++ )
							if( !sy[ j ] && lx[ i ] + ly[ j ] - g[ i ][ j ] < min )
								min = lx[ i ] + ly[ j ] - g[ i ][ j ];
				for( i = 1; i <= nx; i++ ) if( sx[ i ] ) { lx[ i ] -= min; sx[ i ] = 0; }
				for( j = 1; j <= ny; j++ ) if( sy[ j ] ) { ly[ j ] += min; sy[ j ] = 0; }
			}
		}
	}
	match = 0;
	for( i = 1; i <= 11; i++ )
		match += g[ i ][ cx[ i ] ];
//		match += g[ cy[ i ] ][ i ];
}

int st[ 10 ], ed[ 10 ];
vector<int> ans;

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 1; i <= n; i++ )
		{
			cin >> p[ i ].name;
			for( int j = 0; j < 8; j++ )
				scanf( "%d", &p[ i ].pos[ j ] );
		}
		int Max = 0;
		nx = 11, ny = n;
		ans.clear( );
		for( int k = 0; k < 7; k++ )
		{
			memset( g, 0, sizeof( g ) );
			ed[ 0 ] = 1;
			for( int i = 1; i <= 8; i++ )
			{
				st[ i ] = ed[ i - 1 ];
				ed[ i ] = st[ i ] + team[ k ][ i - 1 ];
			}
			for( int i = 1; i <= n; i++ )
				for( int j = 1; j <= 8; j++ )
					for( int q = st[ j ]; q < ed[ j ]; q++ )
						g[ q ][ i ] = p[ i ].pos[ j - 1 ];
			match = 0;
			KuhnMunkres( );
			if( match > Max ) { Max = match; ans.clear( ); ans.push_back( k ); }
			else if( match == Max ) ans.push_back( k );
		}
		sort( ans.begin( ), ans.end( ) );
		for( int i = 0; i < ans.size(); i++ )
		{
			if( ans[ i ] != 6 ) printf( "Formation %c has the highest points %d.\n", ans[ i ] + 'A', Max );
			else printf( "Formation China has the highest points %d.\n", Max );
		}
		printf( "\n" );
	}
	return 0;
}
