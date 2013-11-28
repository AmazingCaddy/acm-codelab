#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<complex>
using namespace std;

typedef complex<double> point;
const double eps = 1e-4;
const double inf = 1e20;
const double pi  = acos( -1.0 );
const double g = 9.18;

double operator ^ ( const point p1, const point p2 ) { return imag( conj( p1 ) * p2 ); }
double operator & ( const point p1, const point p2 ) { return real( conj( p1 ) * p2 ); }
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct line
{
    point a, b;
    line( ){ }
    line( point u, point v ) : a( u ) , b( v ) {  }
};

struct POLY
{
    point p[12];
    int n, type;
    double h, k;
}poly[12];

bool cmp( const POLY & a, const POLY & b ) { return ( a.h == b.h && a.type < b.type ) || a.h > b.h; }

point operator*( line l0, line l1 )
{
    double t = l0.a - l1.a^ l0.b - l1.a;
    double s = l0.b - l1.b^ l0.a - l1.b;
    return l1.a + ( l1.b - l1.a ) * t / ( t + s );
}

//  不是逆时针，转化成逆时针的
void changeclockwise( POLY & P )
{
    int pn = P.n;
    if( ( P.p[1] - P.p[0] ^ P.p[2] - P.p[0] ) < 0 )
        for( int i = 0; i < pn / 2; i++ )
            swap( P.p[i], P.p[pn-1-i] );
}

bool point_on_segment( const point & p, const line & l )
{
    if( dblcmp( l.a - p ^ l.b - p ) ) return false;
    if( dblcmp( l.a - p & l.b - p ) <= 0 ) return true;
    return false;
}

bool segment_cross( const line & l1, const line l2 )
{
    point p1 = l1.a, p2 = l1.b, p3 = l2.a, p4 = l2.b;
    if( ( dblcmp( p2 - p1 ^ p3 - p1 ) ^ dblcmp( p2 - p1 ^ p4 - p1 ) ) == -2 && 
        ( dblcmp( p4 - p3 ^ p1 - p3 ) ^ dblcmp( p4 - p3 ^ p2 - p3 ) ) == -2 )
        return true;
    return false;
}

bool PointInPoly( const point & p, const POLY & Q )
{
    int qn = Q.n;
    double area1 = 0, area2 = 0;
    for( int i = 0; i < qn; i++ )
        area1 = area1 + ( Q.p[i] ^ Q.p[i+1] );
    for( int i = 0; i < qn; i++ )
        area2 = area2 + fabs( Q.p[i] - p ^ Q.p[i+1] - p );
    if( dblcmp( fabs( area1 ) - area2 ) == 0 )
        return true;
    return false;
}

point seg_cross_poly( line l, const POLY & Q )
{
    int qn = Q.n;
    point s;
    for( int i = 0; i < qn; i++ )
    {
        line l1 = line( Q.p[i], Q.p[i+1] );
        if( dblcmp( l.a - l.b ^ l1.a - l1.b ) != 0 )
        {
            s = l * l1;
            if( point_on_segment( s, l1 ) && dblcmp( s - l.a & l.b - l.a ) > 0 && !point_on_segment( s, l ) )
                break;
        }
    }
    return s;
}

void solve( )
{
    int n;
    double vx, vy, H, x, y,TIME;
    scanf("%lf%lf%lf",&vx,&vy,&H);
    point v( vx, vy ), s( 0, 0 );  // v 速度矢量，s 位移矢量
    point s0;
    scanf("%d",&n);
    for( int i = 0; i < n; i++ )
    {
        scanf("%lf%d",&poly[i].h,&poly[i].n);
        for( int j = 0; j < poly[i].n; j++ )
        {
            scanf("%lf%lf",&x,&y);
            poly[i].p[j] = point( x, y );
        }
        changeclockwise( poly[i] );
        poly[i].p[poly[i].n] = poly[i].p[0];
        scanf("%d%lf",&poly[i].type,&poly[i].k);
    }

    poly[n].n = 4; poly[n].h = 0; poly[n].type = 3; poly[n].k = 0;
    poly[n].p[0] = point( 1e8, 1e8 );
    poly[n].p[1] = point( -1e8, 1e8 );
    poly[n].p[2] = point( -1e8, -1e8 );
    poly[n].p[3] = point( 1e8, -1e8 );
    poly[n].p[4] = point( 1e8, 1e8 );
    n++;
    sort( poly, poly + n, cmp );

    if( dblcmp( H ) < 0 )
    {
        printf("Forever!\n");
        return ;
    }
    TIME = 0.0;
    for( int i = 0; i < n; i++ )
    {   
        double h = poly[i].h;
        double k = poly[i].k;
        if( h == 0 )
        {
            TIME += sqrt( 2 * ( H - h ) / g );
            printf("%.2lf\n",TIME);
            return ;
        }
        if( H < h ) continue;
        double time = sqrt( 2 * ( H - h ) / g );
        s0 = s + v * time;
        if( PointInPoly( s0, poly[i] ) )
        {
            s = s0;
            TIME += time;
            H = h;
            switch( poly[i].type )
            {
            case 0:
                v = v * point( cos( k ), sin( k ) );
                break;

            case 1:
                v = point( k, imag( v ) );
                break;

            case 2:
                v = point( real( v ), k );
                break;
            }
            if( dblcmp( abs( v ) ) == 0 ) 
            {   
                printf("Forever!\n");
                return ;
            }
            point z = seg_cross_poly( line( s, s + v ), poly[i] );
            TIME = TIME + abs( z - s ) / abs( v );
            s = z;
        }
    }
}

int main( )
{
    int t;
    //freopen("in","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for( int i = 1; i <= t; i++ )
    {
        printf("Case %d: ",i);
        solve( );
    }
    return 0;
}
