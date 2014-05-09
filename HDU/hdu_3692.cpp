/*
    author: AmazingCaddy
    time:   
	solve:	计算几何
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

const int maxn = 104;
const double eps = 1e-6;
const double inf = 1e20;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point {
    double x, y;
    point( ) { }
    point( double _x, double _y ) : x( _x ), y( _y ) { }
    void input( ) { scanf( "%lf%lf", &x, &y ); }
};

struct point3d {
    double x, y, z;
    point3d( double _x, double _y, double _z ) : x( _x ), y( _y ), z( _z ) { }
    point3d( ) { }
    void input( ) { scanf( "%lf%lf%lf", &x, &y, &z ); }
    double dis( ) {
        return sqrt( x * x + y * y + z * z );
    }
};

point3d operator + ( const point3d &a, const point3d &b ) {
    return point3d( a.x + b.x, a.y + b.y, a.z + b.z );
}
point3d operator - ( const point3d &a, const point3d &b ) {
    return point3d( a.x - b.x, a.y - b.y, a.z - b.z );
}
point3d operator * ( const point3d &a, double scale ) {
    return point3d( a.x * scale, a.y * scale, a.z * scale );
}
point3d operator / ( const point3d &a, double scale ) {
    return point3d( a.x / scale, a.y / scale, a.z / scale );
}
point3d operator ^ ( const point3d &a, const point3d &b ) {
    return point3d( a.y * b.z - a.z * b.y, b.x * a.z - a.x * b.z, a.x * b.y - a.y * b.x );
}
double operator & ( const point3d &a, const point3d &b ) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

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
double dis2( const point3d &a, const point3d &b ) {
    point3d p = a - b;
    return p.x * p.x + p.y * p.y + p.z * p.z;
}
double dis( const point &a, const point &b ) {
    return sqrt( dis2( a, b ) );
}
double dis( const point3d &a, const point3d &b ) {
    return sqrt( dis2( a, b ) );
}

double det( const point &o, const point &a, const point &b ) {
    return a - o ^ b - o;
}

bool cmp( const point &a, const point &b ) {
    if( D( a.y - b.y ) == 0 ) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

bool operator == ( const point &a, const point &b ) {
    return D( a.x - b.x ) == 0 && D( a.y - b.y ) == 0;
}

point seg_cross( const point &a, const point &b, const point &c, const point &d ) {
    double t = ( c - a ^ d - a );
    double s = ( d - b ^ c - b );
    return a + ( b - a ) * t / ( s + t );
}

point p[ maxn ], np[ maxn ];
void convex_hull( int & n ) {
    sort( p, p + n, cmp );
    int top = 0;
    for( int i = 0; i < n; i++ ) {
        while( top >= 2 && D( det( np[ top - 2 ], np[ top - 1 ], p[ i ] ) ) <= 0 ) {
            top--;
        }
        np[ top++ ] = p[ i ];
    }
    int k = top;
    for( int i = n - 2; i >= 0; i-- ) {
        while( top > k && D( det( np[ top - 2 ], np[ top - 1 ], p[ i ] ) ) <= 0 ) {
            top --;
        }
        np[ top++ ] = p[ i ];
    }
    top--;
    n = top;
}

point3d p3[ maxn ], source;

int main(int argc, char *argv[]) {
//    freopen( "in.txt", "r", stdin );
    double a, b, c, d1, d2;
    int n;
    while( 1 ) {
        scanf( "%lf%lf%lf%lf", &a, &b, &c, &d1 );
        if( D( a ) == 0 && D( b ) == 0 && D( c ) == 0 && D( d1 ) == 0 ) {
            break;
        }
        d1 = -d1;
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ ) {
            p3[ i ].input( );
        }
        source.input( );         // 光源
        point3d N( a, b, c );     // 法向量
        d2 = -( a * source.x + b * source.y + c * source.z );
        point3d cd, ef, gh;
        if( D( a ) != 0 ) {
            cd = point3d( -d1 / a, 0, 0 );
            ef = point3d( -b, a, 0 );
        }
        else if( D( b ) != 0 ) {
            cd = point3d( 0, -d1 / b, 0 );
            ef = point3d( -b, a, 0 );
        }
        else if( D( c ) != 0 ) {
            cd = point3d( 0, 0, -d1 / c );
            ef = point3d( 0, -c, b );
        }
        int flag = 0;
        int tmp = D( a * cd.x + b * cd.y + c * cd.z + d2 );
        for( int i = 0; i < n; i++ ) {
            int t = D( a * p3[ i ].x + b * p3[ i ].y + c * p3[ i ].z + d2 );
            if( t * tmp <= 0 ) {
                flag ++;
            }
        }
        if( flag == n ) {
//            printf( "flag\n" );
            printf( "0.00\n" );    
        }
        else if( flag == 0 ) {
            gh = N ^ ef;
            ef = ef / ef.dis();
            gh = gh / gh.dis();
            point3d aa = source + N;
            double k = ( - d1 - a * source.x - b * source.y - c * source.z ) / 
                    ( a * ( source.x - aa.x ) + b * ( source.y - aa.y ) + c * ( source.z - aa.z ) );
            point3d oo = source + ( source - aa ) * k;
            for( int i = 0; i < n; i++ ) {
                k = ( - d1 - a * source.x - b * source.y - c * source.z ) / 
                    ( a * ( source.x - p3[ i ].x ) + b * ( source.y - p3[ i ].y ) + c * ( source.z - p3[ i ].z ) );
                point3d cross = source + ( source - p3[ i ] ) * k - oo;
                p[ i ] = point( cross & gh, cross & ef );
            }
            convex_hull( n );
            double area = 0;
            for( int i = 0; i < n; i++ ) {
                area += ( np[ i ] ^ np[ ( i + 1 ) % n ] );
            }
            printf( "%.2lf\n", fabs( area / 2 ) );
        }
        else {
            printf( "Infi\n" );
        }
    }
    return 0;
}