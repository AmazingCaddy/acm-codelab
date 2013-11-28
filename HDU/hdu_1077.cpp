/*
    author : AmazingCaddy
    time : 2011-06-01 17:52:27 
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

const int maxn = 304;
const int inf = 0x3fffffff;
const double eps = 1e-4;
const double pi = acos( -1.0 );

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point
{
    double x, y;
    point( ){ }
    point( double _x, double _y ) : x( _x ), y( _y ) { }
    void input( ) { scanf( "%lf%lf", &x, &y ); }
};

struct circle
{
    point o;
    double r;
};
circle c[ maxn ];

struct Event{
    int in; // in  1 or out -1
    double a;
    Event( ){ }
    Event( int in, double a ) : in( in ), a( a ) { }
    bool operator < ( const Event & e )const
    {
        return a < e.a;
    }
};
Event E[maxn << 2];
int Ecnt;

point operator + ( const point &a, const point &b )
{
    return point ( a.x + b.x, a.y + b.y );
}

point operator - ( const point &a, const point &b )
{
    return point ( a.x - b.x, a.y - b.y );
}

point operator * ( const point &a, const double &scale )
{
    return point( a.x * scale, a.y * scale );
}

point operator / ( const point &a, const double &scale )
{
    return point( a.x / scale, a.y / scale );
}

double operator ^ ( const point &a, const point &b )
{
    return a.x * b.y - a.y * b.x;
}

double operator & ( const point &a, const point &b )
{
    return a.x * b.x + a.y * b.y;
}

double dis( const point &a, const point &b )
{
    point p = a - b;
    return sqrt( p.x * p.x + p.y * p.y );
}

// 这题每个圆的半径都是1
void circle_cross( const circle &c1, const circle &c2, point &p1, point &p2 )
{
    double d = dis( c1.o, c2.o );
    point p = ( c2.o + c1.o ) / 2.0;
    double op = dis( c1.o, p );
    double h = sqrt( c1.r * c1.r - op * op );
    point p0 = point( c2.o.y - c1.o.y, c1.o.x - c2.o.x );
    p1 = p + p0 * h / d;
    p2 = p - p0 * h / d;
}

void solve( int n )
{
    int i, j, k, cnt, mcnt;
    double a, b;
    point p1, p2;
    int ans = 1;
    for( i = 0; i < n; i++ )
    {
        for( cnt = 1, j = Ecnt = 0; j < n; j++ )
        {
            if( i == j ) continue;
            double d = dis( c[ i ].o, c[ j ].o );
            if( d > 2 ) continue;
            circle_cross( c[ i ], c[ j ], p1, p2 );
            if( D( c[ j ].o - c[ i ].o ^ p1 - c[ i ].o ) > 0 ) swap( p1, p2 );
            a = atan2( p1.y - c[ i ].o.y, p1.x - c[ i ].o.x );
            b = atan2( p2.y - c[ i ].o.y, p2.x - c[ i ].o.x );
            E[ Ecnt++ ] = Event( 1, a );
            E[ Ecnt++ ] = Event( -1, b );
            if( b < a ) cnt++;
        }
        sort( E, E + Ecnt );
        for( j = 0; j < Ecnt; j++ )
        {
            cnt += E[ j ].in;
            if( cnt > ans ) ans = cnt;
        }
    }
    printf( "%d\n", ans );
}

int main(int argc, char *argv[])
{
    int cas, n;
    scanf( "%d", &cas );
    while( cas-- )
    {
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ )
        {
            c[ i ].o.input( );
            c[ i ].r = 1.0;
        }
        solve( n );
    }
    return 0;
}

