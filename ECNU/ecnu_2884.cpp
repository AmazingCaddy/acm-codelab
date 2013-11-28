/*
	author: AmazingCaddy
	time: 2011/3/27  12:12
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

const int maxn = 105;
struct node
{
	int u, step;
};
int g[ maxn ][ maxn ];
int vis[ maxn ];
vector< int > buf[ maxn ];

void init( )
{
	for( int i = 0; i < maxn; i++ )
		buf[ i ].clear( );
}

void BFS( int s, int n )
{
	queue< node > que;
	node tmp;
	int u, step, k;
	memset( vis, 0, sizeof( vis ) );
	tmp.step = 0, tmp.u = s;
	que.push( tmp );
	vis[ s ] = 1; k = 0;
	while( !que.empty( ) )
	{
		tmp = que.front( );
		que.pop( );
		u = tmp.u, step = tmp.step;
		buf[ step ].push_back( u );
		for( int i = 1; i <= n; i++ )
		{
			if( g[ u ][ i ] && !vis[ i ] )
			{
				tmp.u = i;
				tmp.step = step + 1;
				que.push( tmp );
				vis[ i ] = 1;
			}
		}
	}
	for( int i = 0; buf[ i ].size( ); i++ )
	{
		sort( buf[ i ].begin( ), buf[ i ].end( ) );
		for( int j = 0; j < buf[ i ].size( ); j++ )
		{
			if( j ) printf( " " );
			printf( "%d", buf[ i ][ j ] );
		}
		printf( "\n" );
	}
}

int main(int argc, char *argv[])
{
	int n, m;
	scanf( "%d %d", &n, &m );
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= n; j++ )
			scanf( "%d", &g[ i ][ j ] );
	BFS( m, n );
	return 0;
}
