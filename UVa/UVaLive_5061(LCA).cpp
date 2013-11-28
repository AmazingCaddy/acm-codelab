#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100005;

struct Node {
    int v, w;	// w有两个用处，一个是记录边的权值，一个是记录问题的id号
    int id;
};

vector<Node> tree[ maxn ], query[ maxn ];
int p[ maxn ], r[ maxn ];
int add[ maxn ], ans[ maxn ];
int ancestor[ maxn ];
bool mark[ maxn ];
int vis[ maxn ];

void make_set( int x )
{
    p[ x ] = x;
}

int find_set( int x )
{
    if( p[ x ] != x ) p[ x ] = find_set( p[ x ] );
    return p[ x ];
}

void Union( int x, int y )
{
    x = find_set( x );
    y = find_set( y );
    if( x == y ) return ;
    if( r[ x ] > r[ y ] ) p[ y ] = x;
    else
    {
        p[ x ] = y;
        if( r[ x ] == r[ y ] ) r[ y ]++;
    }
}

void init( int n )
{
    for( int i = 1; i <= n; i++ )
    {
        tree[ i ].clear( );
        query[ i ].clear( );
    }
    memset( r, 0, sizeof( r ) );
}

void LCA( int u )
{
    make_set( u );
    ancestor[ u ] = u;
    mark[ u ] = true;
    for( int i = 0; i < tree[ u ].size( ); i++ )
    {
        if( !mark[ tree[ u ][ i ].v ] )
        {
			//dis[ tree[ u ][ i ].v ] = dis[ u ] + tree[ u ][ i ].w;
            //printf("dis[%d]=%d\n",tree[u][i].v,dis[tree[u][i].v]);
            LCA( tree[ u ][ i ].v );
            Union( u, tree[ u ][ i ].v );
            ancestor[ find_set( u ) ] = u;
        }
    }
    for( int i = 0; i < query[ u ].size( ); i++ )
    {
		Node tmp = query[ u ][ i ];
        if( mark[ tmp.v ] && !vis[ tmp.id ] )
        {
			//ans[ query[ u ][ i ].w ] = dis[ u ] + dis[ query[ u ][ i ].v ]
			//- 2 * dis[ ancestor[ find_set( query[ u ][ i ].v ) ] ];
			int lca = ancestor[ find_set( tmp.v ) ];
			add[ u ] += tmp.w;
			add[ tmp.v ] += tmp.w;
			add[ lca ] -= 2 * tmp.w;
			ans[ lca ] += tmp.w;
			vis[ tmp.id ] = 1;
        }
    }
}

void DFS( int u )
{
	mark[ u ] = true;
	for( int i = 0; i < (int)tree[ u ].size( ); i++ )
	{
		if( !mark[ tree[ u ][ i ].v ] )
		{
			DFS( tree[ u ][ i ].v );
			add[ u ] += add[ tree[ u ][ i ].v ];
		}
	}
	ans[ u ] += add[ u ];
}

int main( )
{
	int cas, n, a, b, w, q;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d", &n );
		init( n );
		Node tmp;
		for( int i = 1; i < n; i++ )
		{
			scanf( "%d%d", &a, &b );
			a++, b++;
			tmp.v = b;
			tree[ a ].push_back( tmp );
			tmp.v = a;
			tree[ b ].push_back( tmp );
		}
		scanf( "%d", &q );
		for( int i = 0; i < q; i++ )
		{
			scanf( "%d%d%d", &a, &b, &w );
			a++, b++;
			tmp.v = b, tmp.w = w, tmp.id = i;
			query[ a ].push_back( tmp );
			if( a != b )
			{
				tmp.v = a;
				query[ b ].push_back( tmp );
			}
		}
		memset( add, 0, sizeof( add ) );
		memset( mark, false, sizeof( mark ) );
		memset( ans, 0, sizeof( ans ) );
		memset( vis, 0, sizeof( vis ) );
		LCA( 1 );
		memset( mark, false, sizeof( mark ) );
		DFS( 1 );
		printf( "Case #%d:\n", t );
		for( int i = 1; i <= n; i++ )
		{
			printf( "%d\n", ans[ i ] );
		}
	}
	return 0;
}
