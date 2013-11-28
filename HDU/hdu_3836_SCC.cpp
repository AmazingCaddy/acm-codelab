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
const int maxn = 20004;
const int maxm = 50005;
const int inf = 0x3fffffff;

int head[ maxn ], next[ maxm ], ev[ maxm ];
int headt[ maxn ], nextt[ maxm ], evt[ maxm ];
int len, lent;

int mk[ maxn ], list[ maxn ];
int color, n, m, num;
int col[ maxn ], indv[ maxn ], outdv[ maxn ];

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
        mk[ i ] = 0, col[ i ] = 0;
    
    color = 0;
    for( int i = 1; i <= n; i++ ) 
    {
        if ( !mk[ list[ i ] ] )
        { 
            color++;
            back( list[ i ] );
        }
    }
    if( color == 1 )
    {
        printf( "0\n" );
        return ;
    }
    memset( indv, 0, sizeof( indv ) );
    memset( outdv, 0, sizeof( outdv ) );
    for( int i = 1; i <= n; i++ )
        for( int j = head[ i ]; j; j = next[ j ] )
            if( col[ i ] != col[ ev[ j ] ] )
                outdv[ col[ i ] ] = indv[ col[ ev[ j ] ] ] = 1;
    int cnt1 = 0, cnt2 = 0;
    for( int i = 1; i <= color; i++ )
    {
        if( !indv[ i ] ) cnt1++;
        if( !outdv[ i ] ) cnt2++;
    }
    printf( "%d\n", ( cnt1 > cnt2 ? cnt1 : cnt2 ) );
}


int main(int argc, char *argv[])
{
    int a, b;
    while( scanf( "%d%d", &n, &m ) != EOF )
    {
        init( );
        for( int i = 0; i < m; i++ )
        {
            scanf( "%d%d", &a, &b );
            addedge( a, b, head, next, ev, len );
            addedge( b, a, headt, nextt, evt, lent );
        }
        SCC( );
    }
    return 0;
}
