#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 505;
int c[ maxn ], d[ maxn ];
int g[ maxn ][ maxn ];

struct node
{
    char ch1, ch2;
    int num1, num2;
};
node peo[ maxn ];

vector< node > cd, dc;
int nx, ny, sy[ maxn ], cx[ maxn ], cy[ maxn ];

int dfs( int u )
{
    for( int v = 1; v <= ny; v++ )
    {
        if( g[ u ][ v ] && !sy[ v ]  )
        {
            sy[ v ] = 1;
            if( !cy[ v ] || dfs( cy[ v ] ) )
            {
                cx[ u ] = v;
                cy[ v ] = u;
                return 1;
            }
        }
    }
    return 0;
}

int max_match( )
{
    int i, ret = 0;
    memset( cx, 0, sizeof( cx ) );
    memset( cy, 0, sizeof( cy ) );
    for( i = 1; i <= nx; i++ )
    {
        if( !cx[ i ] )
        {
            memset( sy, 0, sizeof( sy ) );
            ret += dfs( i );
        }
    }
    return ret;
}

int main()
{
    int n, m, p;
    while( scanf( "%d%d%d", &n, &m, &p ) != EOF )
    {
        node tmp;
        cd.clear( ), dc.clear( );
        for( int i = 0; i < p; i++ )
        {
            getchar( );
            scanf( "%c%d %c%d", &tmp.ch1, &tmp.num1, &tmp.ch2, &tmp.num2 );
            if( tmp.ch1 == 'C' ) cd.push_back( tmp );
            else dc.push_back( tmp );
        }
        memset( g, 0, sizeof( g ) );
        nx = cd.size( ), ny = dc.size( );
        for( int i = 0; i < nx; i++ )
        {
            for( int j = 0; j < ny; j++ )
            {
                if( cd[ i ].num1 == dc[ j ].num2 || cd[ i ].num2 == dc[ j ].num1 )
                    g[ i + 1 ][ j + 1 ] = 1;
            }
        }
        int ans = p - max_match( );
        printf( "%d\n", ans );
    }
    return 0;
}
