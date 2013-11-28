#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <complex>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

const int maxn = 100005;
const double eps = 1e-8;
struct point
{
    double x, y;
    point( ) { }
    point( double _x, double _y ) : x( _x ), y( _y ) { }
};
vector< point > p1, p2;

char buf[ 300 ];

point operator - ( const point &a, const point &b ) { return point( a.x - b.x, a.y - b.y ); } 

double dis( const point & a ) { return sqrt( a.x * a.x + a.y * a.y ); }

double getp( point a, double p )
{
    return pow( dis( a ), p );
}

int main( )
{
    int n;
    double x, y, p;
    char ch;
    while( gets( buf ) )
    {
        p1.clear( );
        p2.clear( );
        int len = strlen( buf );
        for( int i = 0; i < len; i++ )
            if( !( ( buf[ i ] <= '9' && buf[ i ] >= '0' ) || buf[ i ] == '.' || buf[ i ] == '-' ) )
                buf[ i ] = ' ';
        istringstream ss( buf );
        while( ss >> x >> y )
        {
            //cout << x << " " << y << endl;
            p1.push_back( point( x, y ) );
        }
        //printf( "OK\n" );
        
        gets( buf );
        len = strlen( buf );
        for( int i = 0; i < len; i++ )
            if( !( ( buf[ i ] <= '9' && buf[ i ] >= '0' ) || buf[ i ] == '.' || buf[ i ] == '-' ) )
                buf[ i ] = ' ';
        istringstream tt( buf );
        while( tt >> x >> y )
        {
            //cout << x << " " << y << endl;
            p2.push_back( point( x, y ) );
        }
        gets( buf );
        istringstream vv( buf );
        vv >> p;
        double ans = 0;
        for( int i = 0; i < p1.size( ); i++ )
        {
            //double tmp = getp( p1[ i ] - p2[ i ], p );
            //cout << tmp << endl;
            ans += getp( p1[ i ] - p2[ i ], p ); 
        }
        printf( "%.8lf\n", pow( ans, 1 / p ) );
    }
    return 0;
}
