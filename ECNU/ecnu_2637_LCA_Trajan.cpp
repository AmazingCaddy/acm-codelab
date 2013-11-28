#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10005;
const int maxm = 1000005;
struct Node {
    int v, w;	// w有两个用处，一个是记录边的权值，一个是记录问题的id号
    Node( int a = 0, int b = 0 ) : v( a ), w( b ) { }
};

vector<Node> tree[ maxn ], query[ maxn ];
int p[ maxn ], r[ maxn ];
int num[ maxn ], dis[ maxn ];
int ans[ maxm ], ancestor[ maxn ];
bool mark[ maxn ];
int n, m, q, cnt;

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

void dfs( int u )
{
    mark[ u ] = true;
    num[ u ] = cnt;
    for( int i = 0; i < tree[ u ].size( ); i++ )
        if( !mark[ tree[ u ][ i ].v ] )
			dfs( tree[ u ][ i ].v );
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
            dis[ tree[ u ][ i ].v ] = dis[ u ] + tree[ u ][ i ].w;
            //printf("dis[%d]=%d\n",tree[u][i].v,dis[tree[u][i].v]);
            LCA( tree[ u ][ i ].v );
            Union( u, tree[ u ][ i ].v );
            ancestor[ find_set( u ) ] = u;
        }
    }
    for( int i = 0; i < query[ u ].size( ); i++ )
    {
        if( mark[ query[ u ][ i ].v ] )
        {
            if( num[ u ] != num[ query[ u ][ i ].v ] ) ans[ query[ u ][ i ].w ] = -1;
            else 
            {
                ans[ query[ u ][ i ].w ] = dis[ u ] + dis[ query[ u ][ i ].v ] - 
					2 * dis[ ancestor[ find_set( query[ u ][ i ].v ) ] ];
            }
        }
    }
}

void init( )
{
    for( int i = 1; i <= n; i++ )
    {
        tree[ i ].clear( );
        query[ i ].clear( );
    }
    memset( r, 0, sizeof( r ) );
    memset( dis, 0, sizeof( dis ) );
}

int main( )
{
    //freopen("in.txt","r",stdin);
    int i;
    int a,b,w;
    while( scanf( "%d%d%d", &n, &m, &q ) != EOF )
    {
        init();

        for( i = 0; i < m; i++ )
        {
            scanf( "%d%d%d", &a, &b, &w );
            tree[a].push_back( Node( b, w ) );
            tree[b].push_back( Node( a, w ) );
        }

        for( i = 0; i < q; i++ )
        {
            scanf( "%d%d", &a, &b );
            if( a == b ) query[ a ].push_back( Node( b, i ) );
            else
            {
                query[ a ].push_back( Node( b, i ) );
                query[ b ].push_back( Node( a, i ) );
            }
        }

        memset( mark, false, sizeof( mark ) );
        for( cnt = 0, i = 1;i <= n; i++ )
        {
            if( !mark[ i ] )
            {
                cnt++;
                dfs( i );
            }
        }

        memset( mark, false, sizeof( mark ) );
        for( i = 1;i <= n; i++ )
        {
            if( !mark[ i ] )
            {
                LCA( i );
            }
        }

        for( i = 0; i < q; i++ )
        {
            if( ans[ i ] == -1 ) puts( "Not connected" );
            else printf( "%d\n", ans[ i ] );
        }
    }
}
