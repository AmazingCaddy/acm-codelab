/*
    author: AmazingCaddy
    time:    2011-08-17 18:25:39 
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
typedef long long ll;

const int mod = 1000007;
int bit[ 32 ][ 104 ];
int n, m = 32;

int pow_mod( int a, int b ) {
    ll ans = 1, d = a % mod;
    while( b ) {
        if( b & 1 ) {
            ans = ans * d % mod;
        }
        d = d * d % mod;
        b >>= 1;
    }
    return ans;
}

void Swap( int p[ ], int q[ ] ) {
    for( int i = 0; i < n; i++ ) {
        swap( p[ i ], q[ i ] );
    }
}

void gauss( ) {
    for( int i = 0; i < m; i++ ) {
        if( !bit[ i ][ i ] ) {
            int flag = 0;
            for( int j = i + 1; j < m; j++ ) {
                if( bit[ j ][ i ] ) {
                    Swap( bit[ j ], bit[ i ] );
                    flag = 1;
                    break;
                }
            }
            if( !flag ) continue;
        }
        for( int j = i + 1; j < m; j++ ) {
            if( bit[ j ][ i ] ) {
                for( int k = i; k < n; k++ ) {
                    bit[ j ][ k ] ^= bit[ i ][ k ];
                }
            }
        }
    }
}
void print( ) {
    for( int i = 0; i < m; i++ ) {
        for( int j = 0; j < n; j++ ) {
            printf( "%d ", bit[ i ][ j ] );
        }
        printf( "\n" );
    }
}

int main(int argc, char *argv[]) {
//    freopen( "data.in", "r", stdin );
    int cas, A;
    scanf( "%d", &cas );
    while( cas-- ) {
        memset( bit, 0, sizeof( bit ) );
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ ) {
            scanf( "%d", &A );
            int j = 0;
            while( A ) {
                bit[ j ][ i ] = ( A & 1 );
                A >>= 1;
                j++;
            }
        }
        gauss( );
        int ans = 32;
        for( int i = m - 1; i >= 0; i-- ) {
            for( int j = 0; j < n; j++ ) {
                if( bit[ i ][ j ] != 0 ) {
                    goto finish;
                }
            }
            ans--;
        }
        finish:;
        ans = pow_mod( 2, n - ans );
        printf( "%d\n", ans );
    }
    return 0;
}