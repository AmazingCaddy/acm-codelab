#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <complex>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double pi = acos( -1.0 );

struct point
{
    double x, y, z;
    point( ) { }
    point( double _x, double _y, double _z ) : x( _x ), y( _y ), z( _z ) { }
    void input( ) { scanf( "%lf%lf%lf", &x, &y, &z ); }
};

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

double dis( const point &p1, const point &p2 )
{
    return sqrt( ( p1.x - p2.x ) * ( p1.x - p2.x )
     + ( p1.y - p2.y ) * ( p1.y - p2.y )
     + ( p1.z - p2.z ) * ( p1.z - p2.z ) );
}

double get( double x1, double x2, double r )
{
    double ans1 = pi * r * r * ( x2 - x1 );
    double ans2 = pi / 3.0 * ( x2 * x2 * x2 - x1 * x1 * x1 );
    return ans1 - ans2;
}

double solve( point p1, double r1, point p2, double r2 )
{
    double ans = 4.0 / 3.0 * pi * ( r1 * r1 * r1 + r2 * r2 * r2 );
    double d = dis( p1, p2 );
    if( D( d - ( r1 + r2 ) ) >= 0 ) return ans;
    if( D( d - fabs( r1 - r2 ) ) <= 0 )
    {
        double r = r1 > r2 ? r1 : r2;
        return 4.0 / 3.0 * pi * r * r * r;
    }
    double t = r1 * r1 + d * d - r2 * r2;
    double s = r2 * r2 + d * d - r1 * r1;
    double d1 = t / ( s + t ) * d;
    double d2 = s / ( s + t ) * d;
    
    double ans1 = get( d1, r1, r1 );
    double ans2 = get( d2, r2, r2 );
    
    return ans - ( ans1 + ans2 );
}

int main( )
{
    double r1, r2, ans;
    point c1, c2;
    int cas;
    scanf( "%d", &cas );
    while( cas-- )
    {
        c1.input( );
        scanf( "%lf", &r1 );
        c2.input( );
        scanf( "%lf", &r2 );
        ans = solve( c1, r1, c2, r2 );
        printf( "%.2lf\n", ans );
    }
    return 0;
}
