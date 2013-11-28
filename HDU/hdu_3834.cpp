#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double eps =  1e-6;
const double pi = acos( -1.0 );

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct point{
    double x, y;
    point( ) { }
    point( double _x, double _y ) : x( _x ), y( _y ) { }
    double len2( ){ return x * x + y * y; }
    point normal( double k )//将他视为向量，将模长变成 k 
    {
        double dist = sqrt( x * x + y * y );
        return point( x * k / dist, y * k / dist );
    }
    point turnLeft( ) { return point( -y, x ); }
    void in( ){ scanf("%lf %lf", &x, &y ); }
};

struct circle { point c; double r; };

point operator * ( double k, const point &a ) { return point( k * a.x, k * a.y ); }
point operator * ( const point &a, double k ) { return point( k * a.x, k * a.y ); }
point operator / ( const point &a, double k ) { return point( a.x / k, a.y / k ); }
point operator + ( const point &a, const point &b ) { return point( a.x + b.x, a.y + b.y ); }
point operator - ( const point &a, const point &b ) { return point( a.x - b.x, a.y - b.y ); }
double operator ^ ( const point &a, const point &b ) { return a.x * b.y - b.x * a.y; }
double operator & ( const point &a, const point &b ) { return a.x * b.x + a.y * b.y; }

double dis( const point &a, const point &b ){
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

double dis2( const point &a, const point &b ){
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}

double det( const point& a, const point& b, const point& c ){
    return ( b.x - a.x ) * ( c.y - a.y ) - ( c.x - a.x ) * ( b.y - a.y );
}

//求直线ab和直线cd的交点
point cross(const point &a, const point &b, const point &c, const point &d)
{
    point ret = a;
    double t =  ((c.x - a.x)*(d.y - c.y) - (c.y - a.y)*(d.x - c.x))/
                ((b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x));
    ret.x += (b.x - a.x) * t;
    ret.y += (b.y - a.y) * t;
    return ret;
}

//计算直线与圆的交点,保证直线与圆有交点
void cross( const circle & b, const point &l1, const point &l2, point& p1, point &p2 ){
    point p=b.c;
    p.x+=l1.y-l2.y;
    p.y+=l2.x-l1.x;
    p=cross(p,b.c,l1,l2);
    double t=sqrt(b.r*b.r-(p.x-b.c.x)*(p.x-b.c.x)-(p.y-b.c.y)*(p.y-b.c.y))/dis(l1,l2);
    p2.x=p.x + (l2.x - l1.x) * t;
    p2.y=p.y + (l2.y - l1.y) * t;
    p1.x=p.x - (l2.x - l1.x) * t;
    p1.y=p.y - (l2.y - l1.y) * t;
    if( D( p1 - l1 & l2 - l1 ) > 0 ) swap( p1, p2 ); // 保证正解在 p2 里
}

point rotate( const point &a, const point &b, double angle )
{
    point p = b - a;
    double sind = sin( angle ), cosd = cos( angle );
    return a + point( p.x * cosd - p.y * sind, p.y * cosd + p.x * sind );
}

double vec_angle( const point &a, const point &b, const point &c )
{
    double x = b - a & c - a;
    double y = b - a ^ c - a;
    return atan2( y, x );        // > 0 逆时针， < 0 顺时针
}

int main( ) {
    int cas;
    circle table;
    point ball, vec, p1, p2, ans;
    double Ti, ball_r, v;
    scanf( "%d", &cas );
    while( cas -- )
    {
        table.c.in( );    scanf( "%lf", & table.r );
        ball.in( );        scanf( "%lf", & ball_r );
        vec.in( );        scanf( "%lf", & Ti );
        
        table.r -= ball_r;
        v = sqrt( vec.len2( ) );
        
        point tmp = ball + vec;
        cross( table, ball, tmp, p1, p2 );
        
        //printf( "p1 = ( %lf, %lf )  p2 = ( %lf, %lf )\n", p1.x, p1.y, p2.x, p2.y );
        double t1 = dis( ball, p2 ) / v;                    // 开始不完整的一段花费的实践
        double t2 = dis( p1, p2 ) / v;                         // 每段弦长花费的时间
        double angle = 2 * vec_angle( p2, table.c, p1 );    // 每次碰撞转过的角度
        
        if( angle < 0 ) angle = -pi - angle;
        else angle = pi - angle;
        
        //printf( "t1 = %lf, t2 = %lf angle = %lf\n", t1, t2, angle );
        if( D( t1 - Ti ) >= 0 ) ans = ball + t1 * vec;
        else
        {
            Ti -= t1;
            ll sum = floor( Ti / t2 );
            //cout << "sum = " << sum << endl;
            point start = p2;
            double scale = Ti - sum * t2;
            p1 = rotate( table.c, start, angle * sum );
            p2 = rotate( table.c, start, angle * sum + angle );
            //printf( "p1 = ( %lf, %lf )  p2 = ( %lf, %lf )\n", p1.x, p1.y, p2.x, p2.y );
            ans = p1 + ( p2 - p1 ) * scale / t2;
        }
        printf( "%.1lf %.1lf\n", ans.x, ans.y );
    }
}
