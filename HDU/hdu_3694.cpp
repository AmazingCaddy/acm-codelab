/*
    author: AmazingCaddy
    time:    
	solve:	º∆À„º∏∫Œ
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
#define lowbit(x) ((x)&(-(x)))
typedef long long ll;

const int maxn = 10004;
const double eps = 1e-8;
const double inf = 1e20;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point {
    double x, y;
    point( ) { }
    point( double _x, double _y ) : x( _x ), y( _y ) { }
    void input( ) { scanf( "%lf%lf", &x, &y ); }
};

point operator + ( const point &a, const point &b ) {
    return point( a.x + b.x, a.y + b.y );
}
point operator - ( const point &a, const point &b ) {
    return point( a.x - b.x, a.y - b.y );
}
point operator * ( const point &a, double scale ) {
    return point ( a.x * scale, a.y * scale );
}
point operator / ( const point &a, double scale ) {
    return point ( a.x / scale, a.y / scale );
}
double operator ^ ( const point &a, const point &b ) {
    return a.x * b.y - a.y * b.x;
}
double operator & ( const point &a, const point &b ) {
    return a.x * b.x + a.y * b.y;
}
double dis2( const point &a, const point &b ) {
    point p = a - b;
    return p.x * p.x + p.y * p.y;
}
double dis( const point &a, const point &b ) {
    return sqrt( dis2( a, b ) );
}
double det( const point &o, const point &a, const point &b ) {
    return a - o ^ b - o;
}
double cmp( const point &a, const point &b, const point &c, const point &d ) {
    return a - b ^ c - d;
}

bool operator == ( const point &a, const point &b ) {
    return D( a.x - b.x ) == 0 && D( a.y - b.y ) == 0;
}

point p[ 4 ];

point seg_cross( const point &a, const point &b, const point &c, const point &d ) {
    double t = ( c - a ^ d - a );
    double s = ( d - b ^ c - b );
    return a + ( b - a ) * t / ( s + t );
}

int main(int argc, char *argv[]) {
//    freopen( "in.txt", "r", stdin );
    while( 1 ) {
        int cnt = 0;
        for( int i = 0; i < 4; i++ ) {
            p[ i ].input();
            if( p[ i ] == point( -1, -1 ) ) {
                cnt++;
            }
        }
        if( cnt == 4 ) {
            break;
        }
        double ans = inf;
        for( int i = 0; i < 4; i++ ) {
            double d = 0;
            for( int j = 0; j < 4; j++ ) {
                d += dis( p[ i ], p[ j ] );
            }
            if( d < ans ) {
                ans = d;
            }
        }
        point o;
        if( D ( cmp( p[ 0 ], p[ 1 ], p[ 2 ], p[ 3 ] ) ) != 0 ) {
            o = seg_cross( p[ 0 ], p[ 1 ], p[ 2 ], p[ 3 ] );
            double d = 0;
            for( int i = 0; i < 4; i++ ) {
                d += dis( o, p[ i ] );
            }
            if( d < ans ) {
                ans = d;
            }
        }
        if( D ( cmp( p[ 0 ], p[ 2 ], p[ 1 ], p[ 3 ] ) ) != 0 ) {
            o = seg_cross( p[ 0 ], p[ 2 ], p[ 1 ], p[ 3 ] );
            double d = 0;
            for( int i = 0; i < 4; i++ ) {
                d += dis( o, p[ i ] );
            }
            if( d < ans ) {
                ans = d;
            }
        }
        if( D ( cmp( p[ 0 ], p[ 3 ], p[ 2 ], p[ 1 ] ) ) != 0 ) {
            o = seg_cross( p[ 0 ], p[ 3 ], p[ 2 ], p[ 1 ] );
            double d = 0;
            for( int i = 0; i < 4; i++ ) {
                d += dis( o, p[ i ] );
            }
            if( d < ans ) {
                ans = d;
            }
        }
        printf( "%.4lf\n", ans );
    }
    return 0;
}