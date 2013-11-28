/*
    author: AmazingCaddy
    time:    
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

const int maxn = 104;
const double eps = 1e-10;

double a[ maxn ][ maxn ], b[ maxn ];
int gauss_cpivot( int n ) {
    int i, j, k, row;
    double maxp, t;
    for ( k = 0; k < n; k++ ) {
        for( maxp = 0, i = k; i < n; i++ ) {
            if( fabs( a[ i ][ k ] ) > fabs( maxp ) ) {
                maxp = a[ row = i ][ k ];
            }
        }
        if( fabs( maxp ) < eps ) {
            return 0;
        }
        if( row != k ) {
            for( j = k; j < n; j++ ) {
                t = a[ k ][ j ], a[ k ][ j ] = a[ row ][ j ], a[ row ][ j ] = t;
            }
            t = b[ k ], b[ k ] = b[ row ], b[ row ] = t;
        }
        for( j = k + 1; j < n; j++ ) {
            a[ k ][ j ] /= maxp;
            for( i = k + 1; i < n; i++ ) {
                a[ i ][ j ] -= a[ i ][ k ] * a[ k ][ j ];
            }
        }
        b[ k ] /= maxp;
        for( i = k + 1; i < n; i++ ) {
            b[ i ] -= b[ k ] * a[ i ][ k ];
        }
    }
    for( i = n - 1; i >= 0; i-- ) {
        for( j = i + 1; j < n; j++ ) {
            b[ i ] -= a[ i ][ j ] * b[ j ];
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
//    freopen( "in.txt", "r", stdin );
    int n, m;
    double p, q;
    while( scanf( "%d%d%lf%lf", &n, &m, &p, &q ) != EOF ) {
        int len = n + m + 1;
        double x = q * ( 1 - p ), y = p * ( 1 - q );
        memset( a, 0, sizeof( a ) );
        memset( b, 0, sizeof( b ) );
        for( int i = 1; i < n + m; i++ ) {
            a[ i ][ i - 1 ] = x;
            a[ i ][ i ] = -x - y;
            a[ i ][ i + 1 ] = y;
        }
        a[ 0 ][ 0 ] = 1;
        a[ n + m ][ n + m ] = 1;
        b[ n + m ] = 1;
        gauss_cpivot( len );
        printf( "%.2lf\n", b[ n ] );
    }
    return 0;
}