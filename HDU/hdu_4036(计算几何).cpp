/*
    author: AmazingCaddy
    time:    2011-09-11 13:52:20 
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

const int maxn = 1004;
const int inf = 0x3fffffff;
const double eps = 1e-5;
const double g = 20.0;

struct point {
    int x, h;
    point( ){ }
    point( int _x, int _h ) : x( _x ), h( _h ) { }
    void input( ) { scanf( "%d%d", &x, &h ); }
};
point peak[ maxn ];

struct node {
    int p, v, m;
};
node bitter[ maxn ];

int N, M, W, maxpeak;
int X[ maxn ];
double K[ maxn ];

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
double fix( double x ) { return x < 0 ? 0 : x; }

bool check( double init_v ) {
    double h = maxpeak - peak[ 1 ].h;
    if( init_v * init_v < 2 * g * h ) {
        return false;
    }
    double lasth = peak[ 1 ].h;
    double lastv = init_v;
    for( int i = 0; i < M; i++ ) {
        int tmp = upper_bound( X + 1, X + N + 1, bitter[ i ].p ) - X - 1;
        double k = K[ tmp ];
        h = peak[ tmp ].h + k * ( bitter[ i ].p - peak[ tmp ].x );
        double delta_h = h - lasth;
        double v = sqrt( lastv * lastv - 2 * g * delta_h );
        if( v <= bitter[ i ].v ) {
            return false;
        }
        lastv = v;
        lasth = h;
    }
    return true;
}

int main(int argc, char *argv[]) {
    int cas;
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ) {
        scanf( "%d%d%d", &N, &M, &W );
        maxpeak = -inf;
        for( int i = 1; i <= N; i++ ) {
            peak[ i ].input( );
            X[ i ] = peak[ i ].x;
            if( maxpeak < peak[ i ].h ) {
                maxpeak = peak[ i ].h;
            }
        }
        for( int i = 0; i < M; i++ ) {
            scanf( "%d%d%d", &bitter[ i ].p, &bitter[ i ].v, &bitter[ i ].m );
        }
        for( int i = 2; i <= N; i++ ) {
            K[ i - 1 ] = 1.0 * ( peak[ i ].h - peak[ i - 1 ].h ) 
                        / ( peak[ i ].x - peak[ i - 1 ].x );
        }
        double l = 0, r = 1e10, mid;
        while( r - l > eps ) {
            mid = ( l + r ) / 2;
            if( check( mid ) ) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        printf( "Case %d: %.2lf\n", t, mid );
    }
    return 0;
}