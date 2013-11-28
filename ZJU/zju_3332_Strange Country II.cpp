#include <iostream>
#include <cstdio>

using namespace std;

const int L = 103;

int n, adj[ L ][ L ], path[ L ], pathLen;
bool inpath[ L ];

bool dfs( int i ) {
        int j, k;
        path[ pathLen++ ] = i;
        inpath[ i ] = true;
        if ( pathLen >= n ) {
                return true;
        }
        for ( j = adj[ i ][ 0 ]; j > 0; --j ) {
                k = adj[ i ][ j ];
                if ( ! inpath[ k ] ) {
                        if ( dfs( k ) ) {
                                return true;
                        }
                }
        }
        --pathLen;
        inpath[ i ] = false;
        return false;
}

bool haveAns( void ) {
        for ( int i = 1; i <= n; ++i ) {
                pathLen = 0;
                memset( inpath, 0, sizeof( inpath ) );
                if ( dfs( i ) ) {
                        return true;
                }
        }
        return false;
}

int main() {
        int td, m, i, j;
        scanf( "%d", &td );
        while ( td-- ) {
                scanf( "%d", &n );
                for ( i = 1; i <= n; ++i ) {
                        adj[ i ][ 0 ] = 0;
                }
                m = ( n - 1 ) * n / 2;
                while ( m-- ) {
                        scanf( "%d%d", &i, &j );
                        adj[ i ][ ++adj[ i ][ 0 ] ] = j;
                }
                if ( haveAns() ) {
                        printf( "%d", path[ 0 ] );
                        for ( i = 1; i < pathLen; ++i ) {
                                printf( " %d", path[ i ] );
                        }
                        printf( "\n" );
                }
                else {
                        printf( "Impossible\n" );
                }
        }
        return 0;
}
