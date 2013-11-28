/*
    author: AmazingCaddy
    time: 2011/3/5  23:35
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1005;
const int inf = 1000000000;

int g[ maxn ][ maxn ];
int cost[ maxn ][ maxn ];
int dis[ maxn ], f[ maxn ];
int n, m;

void dij( int s )
{
    int vis[ maxn ], min;
    for( int i = 1; i <= n; i++ )
    {
        dis[ i ] = g[ s ][ i ];
        vis[ i ] = 0;
        f[ i ] = cost[ s ][ i ];
    }
    vis[ s ] = 1;
    for( int i = 1; i < n; i++ )
    {
        min = inf;
        int k = 0;
        for( int j = 1; j <= n; j++ )
            if( !vis[ j ] && dis[ j ] < min )
                min = dis[ j ], k = j;
        if( k == 0 ) continue;
        vis[ k ] = 1;
        for( int j = 1; j <= n; j++ )
        {
            if( !vis[ j ] )
            {
                if( dis[ k ] + g[ k ][ j ] < dis[ j ] )
                {
                    dis[ j ] = dis[ k ] + g[ k ][ j ];
                    f[ j ] = f[ k ] + cost[ k ][ j ];
                }
                else if( dis[ k ] + g[ k ][ j ] == dis[ j ] && f[ j ] > f[ k ] + cost[ k ][ j ] )
                    f[ j ] = f[ k ] + cost[ k ][ j ];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int s, t, a, b, d, p;
    while( 1 )
    {
        scanf( "%d %d", &n, &m );
        if( n == 0 && m == 0 ) break;
        for( int i = 1; i <= n; i++ )
        {
            g[ i ][ i ] = cost[ i ][ i ] = 0;
            for( int j = i + 1; j <= n; j++ )
            {
                g[ i ][ j ] = g[ j ][ i ] = inf;
                cost[ i ][ j ] = cost[ j ][ i ] = inf;
            }
        }
        for( int i = 0; i < m; i++ )
        {
            scanf( "%d%d%d%d", &a, &b, &d, &p );
            if( d < g[ a ][ b ] || ( g[ a ][ b ] == d && p < cost[ a ][ b ] ) )
            {
                g[ a ][ b ] = g[ b ][ a ] = d;
                cost[ a ][ b ] = cost[ b ][ a ] = p;
            }
        }
        scanf( "%d %d", &s, &t );
        dij( s );
        printf( "%d %d\n", dis[ t ], f[ t ] );
    }
    return 0;
}
