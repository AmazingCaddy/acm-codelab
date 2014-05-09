/*
    author: AmazingCaddy
    time:    
    solve:    
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const double eps = 1e-7;
const double pi = acos( -1.0 );

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
    return point( a.x * scale, a.y * scale );
}
point operator / ( const point &a, double scale ) {
    return point( a.x / scale, a.y / scale );
}
double operator ^ ( const point &a, const point &b ) {
    return a.x * b.y - a.y * b.x;
}
double operator & ( const point &a, const point &b ) {
    return a.x * b.x + a.y * b.y;
}
double dis2( const point &a, const point &b ) {
    point p = a - b;
    return ( p.x * p.x + p.y * p.y );
}
double dis( const point &a, const point &b ) {
    return sqrt( dis2( a, b ) );
}
double det( const point &o, const point &a, const point &b ) {
    return ( a - o ^ b - o );
}
double get_angle( const point &o, const point &a, const point &b ) {
    return acos( ( a - o & b - o ) / dis( o, a ) / dis( o, b ) );
    //return atan2( fabs( a - o ^ b - o ), ( a - o & b - o ) );
}
point get_point( const point &a, const point &b, double t, double s ) {
    return a + ( b - a ) * ( t / ( s + t ) );
}
point seg_cross( const point &a, const point &b, const point &c, const point &d ) {
    double t = ( c - a ^ d - a );
    double s = ( d - b ^ c - b );
    return a + ( b - a ) * ( t / ( s + t ) );
}

struct triangle {
    point p[ 3 ];
    triangle( ) { }
    triangle( point a, point b, point c ) {
        p[ 0 ] = a, p[ 1 ] = b, p[ 2 ] = c;
    }
    double get_area2( ) const {
        return fabs( p[ 1 ] - p[ 0 ] ^ p[ 2 ] - p[ 0 ] );
    }
};

bool operator == ( const triangle &t1, const triangle &t2 ) {
    double len1[ 5 ], len2[ 5 ];
//    double angle1[ 5 ], angle2[ 5 ];
    for( int i = 0; i < 3; i++ ) {
        len1[ i ] = dis2( t1.p[ i ], t1.p[ ( i + 1 ) % 3 ] );
        len2[ i ] = dis2( t2.p[ i ], t2.p[ ( i + 1 ) % 3 ] );
//        angle1[ ( i + 1 ) % 3 ] = get_angle( t1.p[ ( i + 1 ) % 3 ], t1.p[ i ], t1.p[ ( i + 2 ) % 3 ] );
//        angle2[ ( i + 1 ) % 3 ] = get_angle( t2.p[ ( i + 1 ) % 3 ], t2.p[ i ], t2.p[ ( i + 2 ) % 3 ] );
    }
    for( int i = 0; i < 3; i++ ) {
        int flag = 0;
        for( int k = 0; k < 3; k++ ) {
            if( D( len1[ ( i + k ) % 3 ] - len2[ k ] ) != 0 ) {
                flag = 1;
                break;
            }
        }
        if( !flag ) {
            return true;
        }
    }
    reverse( len1, len1 + 3 );
    for( int i = 0; i < 3; i++ ) {
        int flag = 0;
        for( int k = 0; k < 3; k++ ) {
            if( D( len1[ ( i + k ) % 3 ] - len2[ k ] ) != 0 ) {
                flag = 1;
                break;
            }
        }
        if( !flag ) {
            return true;
        }
    }
    return false;
}

struct quadangle {
    point p[ 4 ];
    int flag;    // 1 凸四边形  0 退化为三角形  -1 凹四边形
    int pp;        // 记录退化的顶点，或者凹的顶点
    void couter_clockwise( ) {
        double area = 0;
        for( int i = 0; i < 4; i++ ) {
            area += ( p[ i ] ^ p[ ( i + 1 ) % 4 ] );
        }
        if( area < 0 ) {
            reverse( p, p + 4 );
        }
    }
    void get_type( ) {
        flag = 1;
        for( int i = 0; i < 4; i++ ) {
            int tmp = D( det( p[ i ], p[ ( i + 1 ) % 4 ], p[ ( i + 2 ) % 4 ] ) );
            if( tmp != 1 ) {
                flag = tmp;
                pp = ( i + 1 ) % 4;
                break;
            }
        }
    }
    bool check( const triangle &t1, const triangle &t2, 
        const triangle &t3, const triangle &t4 ) {
        if( t1 == t3 && t2 == t4 || t1 == t4 && t2 == t3 ) {
            return true;
        }
        return false;
    }
    bool cut_triangle( const triangle &t1, const triangle &t2 ) {
        triangle t3, t4;
        int p0, p1, p2, len;
        double area1, area2;
        point q[ 4 ], o;
        switch( flag ) {
        case 1:
            t3 = triangle( p[ 0 ], p[ 1 ], p[ 3 ] );
            t4 = triangle( p[ 3 ], p[ 1 ], p[ 2 ] );
            if( check( t1, t2, t3, t4 ) ) {
                return true;
            }
            t3 = triangle( p[ 0 ], p[ 1 ], p[ 2 ] );
            t4 = triangle( p[ 3 ], p[ 0 ], p[ 2 ] );
            if( check( t1, t2, t3, t4 ) ) {
                return true;
            }
            break;
    
        case 0:
            area1 = t1.get_area2( ), area2 = t2.get_area2( );
            len = 0;
            for( int i = 0; i < 4; i++ ) {
                if( i != pp ) {
                    q[ len ++ ] = p[ i ];
                }
            }
            for( int i = 0; i < 3; i++ ) {
                q[ 3 ] = get_point( q[ ( i + 1 ) % 3 ], q[ ( i + 2 ) % 3 ], area1, area2 );
                t3 = triangle( q[ i ], q[ ( i + 1 ) % 3 ], q[ 3 ] );
                t4 = triangle( q[ i ], q[ 3 ], q[ ( i + 2 ) % 3 ] );
                if( check( t1, t2, t3, t4 ) ) {
                    return true;
                }
                q[ 3 ] = get_point( q[ ( i + 1 ) % 3 ], q[ ( i + 2 ) % 3 ], area2, area1 );
                t3 = triangle( q[ i ], q[ ( i + 1 ) % 3 ], q[ 3 ] );
                t4 = triangle( q[ i ], q[ 3 ], q[ ( i + 2 ) % 3 ] );
                if( check( t1, t2, t3, t4 ) ) {
                    return true;
                }
            }
            break;

        case -1:
            p0 = ( pp + 1 ) % 4, p1 = ( pp + 2 ) % 4, p2 = ( pp + 3 ) % 4;
            t3 = triangle( p[ pp ], p[ p1 ], p[ p2 ] );
            t4 = triangle( p[ pp ], p[ p0 ], p[ p1 ] );
            if( check( t1, t2, t3, t4 ) ) {
                return true;
            }
            o = seg_cross( p[ p2 ], p[ pp ], p[ p0 ], p[ p1 ] );
            t3 = triangle( p[ p1 ], p[ p2 ], o );
            t4 = triangle( p[ pp ], p[ p0 ], o );
            if( check( t1, t2, t3, t4 ) ) {
                return true;
            }
            o = seg_cross( p[ p0 ], p[ pp ], p[ p1 ], p[ p2 ] );
            t3 = triangle( p[ p0 ], p[ p1 ], o );
            t4 = triangle( p[ p2 ], p[ pp ], o );
            if( check( t1, t2, t3, t4 ) ) {
                return true;
            }
            break;
        }
        return false;
    }
};

int main(int argc, char *argv[]){
    int cas;
    triangle t1, t2;
    quadangle qua;
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ) {
        for( int i = 0; i < 3; i++ ) {
            t1.p[ i ].input( );
        }
        for( int i = 0; i < 3; i++ ) {
            t2.p[ i ].input( );
        }
        for( int i = 0; i < 4; i++ ) {
            qua.p[ i ].input( );
        }
        qua.couter_clockwise( );
        qua.get_type( );
        printf( "Case #%d: ", t );
        if( qua.cut_triangle( t1, t2 ) ) {
            printf( "Yes\n" );
        }
        else {
            printf( "No\n" );
        }
    }
    return 0;
}