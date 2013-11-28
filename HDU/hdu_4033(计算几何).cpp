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

const int maxn = 105;
const double eps = 1e-6;
const double EPS = 1e-8;
const double pi = acos( -1.0 );
const double inf = 1e10;

int D( double x ) { return ( x < -EPS ? -1 : x > EPS ); }

int n;
double dis[ maxn ];

double get_angle( double a, double b, double c ) {
    double tmp = ( a * a + b * b - c * c ) / ( 2 * a * b );
    if( tmp < -1 ) {
        tmp = -1;
    }
    if( tmp > 1 ) {
        tmp = 1;
    }
    return acos( tmp );
}

int check_triangle( double a, double b, double c ) {
    if( D( c - fabs( a - b ) ) <= 0 ) {
        return -1;
    }
    if( D( c - ( a + b ) ) >= 0 ) {
        return 1;
    }
    return 0;
}

int check( double x ) {
    double sum = 0;
    for( int i = 0; i < n; i++ ) {
        int tmp = check_triangle( dis[ i ], dis[ i + 1 ], x );
        if( tmp != 0 ) {
            return tmp;
        }
        double angle = get_angle( dis[ i ], dis[ i + 1 ], x );
        sum += angle;
    }
    if( D( sum - 2 * pi ) < 0 ) {
        return -1;
    }
    if( D( sum - 2 * pi ) == 0 ) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int cas;
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ ) {
            scanf( "%lf", &dis[ i ] );
        }
        dis[ n ] = dis[ 0 ];
        double mind = 0, maxd = inf;
        for( int i = 0; i < n; i++ ) {
            if( maxd > dis[ i ] + dis[ i + 1 ] ) {
                maxd = dis[ i ] + dis[ i + 1 ];
            }
            if( mind < fabs( dis[ i ] - dis[ i + 1 ] ) ) {
                mind = fabs( dis[ i ] - dis[ i + 1 ] );
            }
        }
        printf( "Case %d: ", t );
//        printf( "mind = %lf, maxd = %lf\n", mind, maxd );
        if( D( mind - maxd ) > 0 ) {
            printf( "impossible\n" );
            continue;
        }
        if( D( mind - maxd ) == 0 ) {
            if( check( mind ) ) {
                printf( "%.3lf\n", mind );
            }
            else {
                printf( "impossible\n" );
            }
            continue;
        }
        double l = mind - eps, r = maxd + eps, mid;
        while( r - l > eps ) {
            mid = ( l + r ) / 2;
            int tmp = check( mid );
            if( tmp == 1 ) {
                r = mid;
            }
            else if( tmp == 0 ) {
                //ans = mid;
                break;
            }
            else {
                l = mid;
            }
        }
        if( mid < maxd && mid > mind ) {
            printf( "%.3lf\n", mid );
        }
        else {
            printf( "impossible\n" );
        }
        /*
        if( D( mid - mind ) >= 0 && D( mid - maxd ) <= 0 ) {
            printf( "%.3lf\n", mid );        
        }
        else {
            printf( "impossible\n" );
        }
        */
    }
    return 0;
}