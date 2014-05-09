/*
    author: AmazingCaddy
    time:    2011/9/5    21:00
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
typedef long long ll;
const int maxn = 50004;

int vis[ maxn ], L[ maxn ], R[ maxn ], dv[ maxn ];
int head[ maxn ], next[ maxn ], ev[ maxn ];
int len, cnt;

void init( ) {
    memset( head, 0, sizeof( head ) );
    len = 0;
}

void addedge( int u, int v ) {
    next[ ++len ] = head[ u ];
    head[ u ] = len;
    ev[ len ] = v;
}

void dfs( int u ) {
    vis[ u ] = 1;
    L[ u ] = ++cnt;
    for( int i = head[ u ]; i; i = next[ i ] ) {
        int v = ev[ i ];
        if( !vis[ v ] ) {
            dfs( v );
        }
    }
    R[ u ] = ++cnt;
}

struct node {
    int l, r, col;
};
node tree[ maxn << 3 ];

void make_tree( int v, int l, int r ) {
    tree[ v ].l = l;
    tree[ v ].r = r;
    tree[ v ].col = -1;
    if( l + 1 != r ) {
        int mid = ( l + r ) >> 1;
        make_tree( v << 1, l, mid );
        make_tree( v << 1 | 1, mid, r );
    }
}

void push_down( int v, int color ) {
    tree[ v ].col = color;
}

void update( int v, int l, int r, int color ) {
    if( tree[ v ].l == l && tree[ v ].r == r ) {
        tree[ v ].col = color;
        return;
    }

    if( tree[ v ].col != -1 ) {
        push_down( v << 1, tree[ v ].col );
        push_down( v << 1 | 1, tree[ v ].col );
        tree[ v ].col = -1;
    }
    
    int mid = ( tree[ v ].l + tree[ v ].r ) >> 1;
    if( r <= mid ) {
        update( v << 1, l, r, color );
    }
    else if( l >= mid ) {
        update( v << 1 | 1, l, r, color );
    }
    else {
        update( v << 1, l, mid, color );
        update( v << 1 | 1, mid, r, color );
    }
}

int query( int v, int l, int r ) {
    if( tree[ v ].l == l && tree[ v ].r == r ) {
        return tree[ v ].col;
    }

    if( tree[ v ].col != -1 ) {
        push_down( v << 1, tree[ v ].col );
        push_down( v << 1 | 1, tree[ v ].col );
        tree[ v ].col = -1;
    }

    int mid = ( tree[ v ].l + tree[ v ].r ) >> 1;
    // 本题查询的是点，所有必定完全在mid的左边，或者右边
    if( r <= mid ) {
        return query( v << 1, l, r );
    }
    if( l >= mid ) {
        return query( v << 1 | 1, l, r );
    }
    return -1;
}

int main(int argc, char *argv[]) {
//    freopen( "in", "r", stdin );
//    freopen( "out1", "w", stdout );
    int cas, n, u, v, q, x, y;
    char op[ 10 ];
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ) {
        scanf( "%d", &n );
        init( );
        memset( dv, 0, sizeof( dv ) );
        for( int i = 1; i < n; i++ ) {
            scanf( "%d%d", &u, &v );
            dv[ u ]++;
            addedge( v, u );
        }
        int root = -1;
        for( int i = 1; i <= n; i++ ) {
            if( !dv[ i ] ) {
                root = i;
                break;
            }
        }
        memset( vis, 0, sizeof( vis ) );
        cnt = 0;
        dfs( root );
//        printf( "cnt = %d\n", cnt );
//        for( int i = 1; i <= n; i++ ) {
//            printf( "%d %d\n", L[ i ], R[ i ] );
//        }

        make_tree( 1, 0, cnt );
        printf( "Case #%d:\n", t );
        scanf( "%d", &q );
        for( int i = 0; i < q; i++ ) {
            scanf( "%s", op );
            if( op[ 0 ] == 'C' ) {
                scanf( "%d", &x );
                int ans = query( 1, L[ x ] - 1, L[ x ] );
                printf( "%d\n", ans );
            }
            else {
                scanf( "%d%d", &x, &y );
                update( 1, L[ x ] - 1, R[ x ], y );
            }
        }

    }
    return 0;
}

/*
1 
5 
4 3 
3 2 
1 3 
5 2 
5 
C 3 
T 2 1
C 3 
T 3 2 
C 3
*/
