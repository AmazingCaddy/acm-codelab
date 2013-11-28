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
const double eps = 1e-8;
const double g = 9.8;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

int main(int argc, char *argv[])
{
    double H, Vx, Vy, t, ans[ 3 ], Ti, v1, v2, v3;
    char color[ 20 ];
    while( scanf( "%lf%s%lf%lf", &H, color, &Vx, &Vy ) != EOF ) {
        double t = Vy / g;
        double h = Vy / g * Vy / 2 + H;
        double t1 = sqrt( h * 2 / g );    
        if( color[ 0 ] == 'R' ) {
            ans[ 0 ] = ( t1 + Vy / g ) * Vx;
            printf( "%.3lf\n", ans[ 0 ] );
        }
        else if( color[ 0 ] == 'B' ) {
            double vx[ 3 ];
            scanf( "%lf", &Ti );
            for( int i = 0; i < 3; i++ ) {
                scanf( "%lf", &vx[ i ] );
            }
            if( D( t + t1 - Ti ) <= 0 ) {
                ans[ 0 ] = ( t1 + Vy / g ) * Vx;
                printf( "%.3lf\n", ans[ 0 ] );
            }
            else {
                double v = Vy + (-g) * Ti;
                double v1 = -sqrt( Vy * Vy + 2 * g * H );
                double x = Vx * Ti;
                double y = ( v * v - Vy * Vy ) / ( -2 * g ) + H;
                double tt = ( v1 - v ) / (-g);
                for( int i = 0; i < 3; i ++ ) {
                    ans[ i ] = x + vx[ i ] * tt;
                }
                printf( "%.3lf %.3lf %.3lf\n", ans[ 0 ], ans[ 1 ], ans[ 2 ] );
            }
        }
        else {
            scanf( "%lf", &Ti );
            if( D( t + t1 - Ti ) <= 0 ) {
                ans[ 0 ] = ( t1 + Vy / g ) * Vx;
                printf( "%.3lf\n", ans[ 0 ] );
            }
            else {
                double v = Vy + (-g) * Ti;
                double x = Vx * Ti;
                double y = ( v * v - Vy * Vy ) / ( -2 * g ) + H;
                double a = -g / 2, b = 2 * v, c = y;
                double delta = sqrt( b * b - 4 * a * c );
                double tt = ( -b - delta ) / ( 2 * a );
                ans[ 0 ] = x + tt * Vx * 2;
                printf( "%.3lf\n", ans[ 0 ] );
            }
        }
    }
    return 0;
}