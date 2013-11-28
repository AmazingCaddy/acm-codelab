/*
    author: AmazingCaddy
    time:    2011-07-14 21:49:17 
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

const int maxn = 204;
const int inf = 0x3f3f3f3f;

struct point
{
    int x, y, r;
    point( ){ }
    point( int _x, int _y, int _r ) : x( _x ), y( _y ), r( _r ) { }
    void in( ) { scanf( "%d%d%d", &x, &y, &r ); }
};
point p[ maxn ];

int head[ maxn ], next[ maxn * maxn ], ev[ maxn * maxn ];
int len;
int dis1[ maxn ], dis2[ maxn ], dis3[ maxn ];

void init( )
{
    len = 0;
    memset( head, 0, sizeof( head ) );
}

void addedge( int u, int v )
{
    next[ ++len ] = head[ u ];
    head[ u ] = len;
    ev[ len ] = v;
}

void spfa( int st, int n, int dis[ ] )
{
    int inque[ maxn ];
    queue< int > que;
    for( int i = 1; i <= n; i++ )
        inque[ i ] = 0, dis[ i ] = inf;
    que.push( st );
    inque[ st ] = 1;
    dis[ st ] = 0;
    while( !que.empty( ) )
    {
        int u = que.front( );
        que.pop( );
        inque[ u ] = 0;
        for( int i = head[ u ]; i ; i = next[ i ] )
        {
            int v = ev[ i ];
            if( dis[ u ] + 1 < dis[ v ] )
            {
                dis[ v ] = dis[ u ] + 1;
                if( !inque[ v ] )
                {
                    inque[ v ] = 1;
                    que.push( v );
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
//    freopen( "in", "r", stdin );
//    freopen( "Earth Hour.in", "r", stdin );
//    freopen( "out", "w", stdout );
    int n, cas;
    scanf( "%d", &cas );
    while( cas-- )
    {
        scanf( "%d", &n );
        for( int i = 1; i <= n; i++ )
            p[ i ].in( );
        init( );
        for( int i = 1; i <= n; i++ )
        {
            for( int j = i + 1; j <= n; j++ )
            {
                if( ( p[ i ].r + p[ j ].r ) * ( p[ i ].r + p[ j ].r ) >=
                    ( p[ i ].x - p[ j ].x ) * ( p[ i ].x - p[ j ].x ) + 
                    ( p[ i ].y - p[ j ].y ) * ( p[ i ].y - p[ j ].y ) )
                {
                    addedge( i, j );
                    addedge( j, i );
                }
            }
        }
        /*
        for( int i = 1; i <= n; i++ )
        {
            for( int j = head[ i ]; j; j = next[ j ] )
                printf( "%d ", ev[ j ] );
            printf( "\n" );
        }
        */
        spfa( 1, n, dis1 );
        spfa( 2, n, dis2 );
        spfa( 3, n, dis3 );
        int ans = inf;
        for( int i = 1; i <= n; i++ )
        {
            if( dis1[ i ] == inf || dis2[ i ] == inf || dis3[ i ] == inf )
                continue;
            if( dis1[ i ] + dis2[ i ] + dis3[ i ] < ans )
                ans = dis1[ i ] + dis2[ i ] + dis3[ i ];
        }
        if( ans == inf ) printf( "-1\n" );
        else printf( "%d\n", n - ( ans + 1 ) );
    }
    return 0;
}
