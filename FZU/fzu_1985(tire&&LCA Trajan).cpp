/*
	author: AmazingCaddy
	time: 2011/3/9  22:07
	compiler: GNU C++
	algorithm: tire tree && LCA
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100005;

struct node
{
	node * child[ 4 ];
	int id;
};
node tree[ maxn ];
char buf[ maxn ];
int num[ maxn ];
int len, cnt;

struct query 
{
	int v, qid;
	query( int a, int b ) : v( a ), qid( b ) { }
};
vector<query> q[ maxn ];
int ans[ maxn ], vis[ maxn ], ancestor[ maxn ], dis[ maxn ];
int pre[ maxn ], r[ maxn ];

int f( char ch )
{
	switch( ch )
	{
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
	}
	return -1;
}

void init( )
{
	// init for union_find_set
	for( int i = 0; i < 4; i++ )
		tree[ 0 ].child[ i ] = NULL;
	tree[ 0 ].id = 0;
	len = cnt = 1;
	// init for LCA
	for( int i = 0; i < maxn; i++ )
		q[ i ].clear( );
	memset( r, 0, sizeof( r ) );
	memset( vis, 0, sizeof( vis ) );
	dis[ 0 ] = 0;
}

node * NewNode( )
{
	tree[ len ].id = -1;
	for( int i = 0; i < 4; i++ )
		tree[ len ].child[ i ] = NULL;
	return & tree[ len++ ];
}

void insert( int id )
{
	int k;
	node * p = & tree[ 0 ];
	for( int i = 0; buf[ i ]; i++ )
	{
		k = f( buf[ i ] );
		if( p -> child[ k ] == NULL ) p -> child[ k ] = NewNode( );
		p = p -> child[ k ];
		if( p -> id == -1 ) p -> id = cnt++;
	}
	num[ id ] = p -> id;
}

void make_set( int u )
{
	pre[ u ] = u;
}

int find_set( int u )
{
	if( pre[ u ] != u )
		pre[ u ] = find_set( pre[ u ] );
	return pre[ u ];
}

void union_set( int x, int y )
{
	x = find_set( x );
	y = find_set( y );
	if( x == y ) return;
	if( r[ x ] <= r[ y ] )
	{
		pre[ x ] = y;
		if( r[ x ] == r[ y ] ) r[ y ]++;
	}
	else pre[ y ] = x;
}

void LCA( node *p )
{
	int u = p -> id;
	make_set( u );
	ancestor[ u ] = u;
	vis[ u ] = 1;
	for( int i = 0; i < 4; i++ )
	{
		if( p -> child[ i ] )
		{
			dis[ p -> child[ i ] -> id ] = dis[ u ] + 1;
			LCA( p -> child[ i ] );
            union_set( u, p -> child[ i ] -> id );
            ancestor[ find_set( u ) ] = u;
		}
	}
	for( int i = 0; i < q[ u ].size( ); i++ )
		if( vis[ q[ u ][ i ].v ] )
			ans[ q[ u ][ i ].qid ] = dis[ ancestor[ find_set( q[ u ][ i ].v ) ] ];
}

int main(int argc, char *argv[])
{
	int cas, n, m, a, b;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		init( );
		printf( "Case %d:\n", t );
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", buf );
			insert( i );
		}
		scanf( "%d", &m );
		for( int i = 0; i < m; i++ )
		{
			scanf( "%d%d", &a, &b );
			q[ num[ a ] ].push_back( query( num[ b ], i ) );
			q[ num[ b ] ].push_back( query( num[ a ], i ) );
		}
		LCA( &tree[ 0 ] );
		for( int i = 0; i < m; i++ )
			printf( "%d\n", ans[ i ] );
	}
	return 0;
}
