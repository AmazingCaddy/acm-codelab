/*
    author: AmazingCaddy
    time:    2011-10-08 15:25:40 
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

const int maxn = 650;
const double pi = acos( -1.0 );
const double eps = 1e-6;
const double inf = 1e8;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
double fix( double x ) { return ( x < 0 ? 0 : x ); }

int head[ maxn ], next[ maxn * maxn ], ev[ maxn * maxn ];
double ew[ maxn * maxn ];
int len;

void init( ) {
    memset( head, -1, sizeof( head ) );
    len = 0;
}

void addedge( int u, int v, double val ) {
    next[ ++len ] = head[ u ];
    head[ u ] = len;
    ev[ len ] = v;
    ew[ len ] = val;
}

double dist[ maxn ];
int in[ maxn ], inque[ maxn ];
double spfa( int st, int ed, int n ) {
    queue< int > que;
    for( int i = 0; i < n; i++ ) {
        dist[ i ] = inf;
        inque[ i ] = 0;
    }
    dist[ st ] = 0;
    inque[ st ] = 1;
    que.push( st );
    while( !que.empty( ) ) {
        int u = que.front( );
        que.pop( );
        inque[ u ] = 0;
        for( int i = head[ u ]; i != -1; i = next[ i ] ) {
            int v = ev[ i ];
            if( D ( dist[ u ] + ew[ i ] - dist[ v ] ) < 0 ) {
                dist[ v ] = dist[ u ] + ew[ i ];
                if( !inque[ v ] ) {
                    que.push( v );
                    inque[ v ] = 1;
                }
            }
        }
    }
    return dist[ ed ];
}

struct point {
    double x, y;
    point( ){ }
    point( double _x, double _y ) : x( _x ), y( _y ) { }
    void input( ) { scanf( "%lf%lf", &x, &y ); }
};

struct circle {
    point o;
    double r;
    circle( ) { }
    circle( point _o, double _r ) : o( _o ), r( _r ) { }
} c[ 30 ];

bool cmp( const point & a, const point & b ) {
    if( D( a.x - b.x ) == 0 ) {
        return D( a.y - b.y ) < 0;
    }
    return D( a.x - b.x ) < 0;
}

point operator + ( const point & a, const point &b ) {
    return point( a.x + b.x, a.y + b.y );
}
point operator - ( const point & a, const point &b ) {
    return point( a.x - b.x, a.y - b.y );
}
point operator * ( const point & a, const double & scale ) {
    return point( a.x * scale, a.y * scale );
}
point operator / ( const point & a, const double & scale ) {
    return point( a.x / scale, a.y / scale );
}
double operator ^ ( const point & a, const point &b ) {
    return ( a.x * b.y - a.y * b.x );
}
double operator & ( const point & a, const point & b ) {
    return ( a.x * b.x + a.y * b.y );
}
double Dis2( const point & a, const point & b ) {
    point p = a - b;
    return ( p.x * p.x + p.y * p.y );
}
double Dis( const point & a, const point & b ) {
    return sqrt( Dis2( a, b ) );
}

double Dis_point_line( const point & p, const point & a, const point & b ) {
    return fabs( a - p ^ b - p ) / Dis( a, b );
}
// 前提，已经共线
bool on_segment( const point & p, const point & a, const point & b ) {
    return D( a - p & b - p ) <= 0;
}

point line_line( const point &a, const point &b, const point &c, const point &d ) {
    double t = ( c - a ^ d - a );
    double s = ( d - b ^ c - b );
    return a + ( b - a ) * t / ( s + t );
}

void line_circle( const point & a, const point & b, const circle &c, point &p1, point &p2 ) {
    point p = c.o + point( a.y - b.y, b.x - a.x );
    p = line_line( a, b, c.o, p );
    double tmp = fix( c.r * c.r - Dis2( p, c.o ) );
    double t = sqrt( tmp ) / Dis( a, b );
    p1 = p + ( b - a ) * t;
    p2 = p + ( a - b ) * t;
}

void circle_circle( const circle & c1, const circle & c2, point &p1, point &p2 ) {
    double t = ( 1 + ( c1.r * c1.r - c2.r * c2.r ) / Dis2( c1.o, c2.o ) ) / 2;
    point u = c1.o + ( c2.o - c1.o ) * t;
    point v = u + point( c1.o.y - c2.o.y, c2.o.x - c1.o.x );
    line_circle( u, v, c1, p1, p2 );
}

int check( const circle & c1, const circle & c2 ) {
    double d = Dis( c1.o, c2.o );
    if( D( d - ( c1.r + c2.r ) ) > 0 || D( d - fabs( c1.r - c2.r ) ) < 0 ) {
        return 0;
    }
    if( D( d - ( c1.r + c2.r ) ) == 0 ) {     // 外切
        return 1;
    }
    if( D( d - fabs( c1.r - c2.r ) ) == 0 ) {     // 内切
        return 2;
    }
    return 3;            // 相交
}

int check( point p[ ], int n, int len ) {
    for( int i = 1; i < len; i++ ) {
        point tmp = ( p[ i - 1 ] + p[ i ] ) / 2.0;
        int flag = 0;
        for( int j = 0; j < n; j++ ) {
            if( D( Dis( c[ j ].o, tmp ) - c[ j ].r ) <= 0 ) {
                flag = 1;
                break;
            }
        }
        if( !flag ) {
            return 0;
        }
    }
    return 1;
}

bool g[ maxn ][ maxn ];
point p[ maxn ], pp[ maxn ];
int num[ maxn ];

void solve( int n ) {
    int st = 0, ed = n - 1;
    int len = 0;
    for( int i = 0; i < n; i++ ) {
        p[ len++ ] = c[ i ].o;
    }
    for( int i = 0; i < n; i++ ) {
        for( int j = i + 1; j < n; j++ ) {
            int tmp = check( c[ i ], c[ j ] );
            if( tmp == 1 ) {
                p[ len++ ] = c[ i ].o + ( c[ j ].o - c[ i ].o ) * ( c[ i ].r / ( c[ i ].r + c[ j ].r ) );
            }
            else if( tmp == 2 ) {
                p[ len++ ] = c[ i ].o + ( c[ j ].o - c[ i ].o ) * ( c[ i ].r / ( c[ i ].r - c[ j ].r ) );
            }
            else if( tmp == 3 ) {
                point p1, p2;
                circle_circle( c[ i ], c[ j ], p1, p2 );
                p[ len++ ] = p1;
                p[ len++ ] = p2;
            }
        }
    }
    init( );
    memset( g, false, sizeof( g ) );
    for( int i = 0; i < n; i++ ) {
        int cnt = 0;
        for( int j = 0; j < len; j++ ) {
            if( D( Dis( c[ i ].o, p[ j ] ) - c[ i ].r ) <= 0 ) {
                num[ cnt ++ ] = j;
            }
        }
        for( int j = 0; j < cnt; j++ ) {
            for( int k = j + 1; k < cnt; k++ ) {
                int x = num[ j ], y = num[ k ];
                if( g[ x ][ y ] ) {
                    continue;
                }
                double d = Dis( p[ x ], p[ y ] );
                g[ x ][ y ] = g[ y ][ x ] = true;
                addedge( x, y, d );
                addedge( y, x, d );
            }
        }
    }
    for( int i = 0; i < len; i++ ) {
        for( int j = i + 1; j < len; j++ ) {
            if( g[ i ][ j ] ) {
                continue;
            }
            int cnt = 0;
            pp[ cnt++ ] = p[ i ];
            pp[ cnt++ ] = p[ j ];
            for( int k = 0; k < n; k++ ) {
                double d = Dis_point_line( c[ k ].o, p[ i ], p[ j ] );
                if( D( d - c[ k ].r ) <= 0 ) {
                    point p1, p2;
                    line_circle( p[ i ], p[ j ], c[ k ], p1, p2 );
                    if( on_segment( p1, p[ i ], p[ j ] ) ) {
                        pp[ cnt++ ] = p1;
                    }
                    if( on_segment( p2, p[ i ], p[ j ] ) ) {
                        pp[ cnt++ ] = p2;
                    }
                }
            }
            sort( pp, pp + cnt, cmp );
            if( check( pp, n, cnt ) ) {
                double d = Dis( p[ i ], p[ j ] );
                addedge( i, j, d );
                addedge( j, i, d );
                g[ i ][ j ] = g[ j ][ i ] = true;
            }
        }
    }
    double ans = spfa( st, ed, len );
    if( D( ans - inf ) == 0 ) {
        printf( "No such path.\n" );
    }
    else {
        printf( "%.4lf\n", ans );
    }
}

int main(int argc, char *argv[]) {
//    freopen( "in.txt", "r", stdin );
    int cas, n;
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ ) {
            c[ i ].o.input( );
            scanf( "%lf", &c[ i ].r );
        }
        printf( "Case %d: ", t );
        solve( n );
    }
    return 0;
}