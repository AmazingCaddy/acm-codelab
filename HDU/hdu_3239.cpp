#include<iostream>
#include<complex>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef complex<double> point;

const int maxn = 20;
const double pi = acos( -1.0 );
const double eps = 1e-8;

struct circle
{
    point p;
    double r;
    circle( ){ }
    circle( point _p, double _r ) : p( _p ), r( _r ) { }
};

struct node
{
    double area;
    int flag; // 标记圆弧是朝上还是朝下
    double y1, y2, mid;
};

circle c[maxn];
vector<double> vec;
vector<point> inter;

double operator ^( const point & p1, const point & p2 ) { return imag( conj( p1 ) * p2 ); }
double operator &( const point & p1, const point & p2 ) { return real( conj( p1 ) * p2 ); }
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

bool samepoint( const point & p1, const point & p2 )
{
	return dblcmp( real( p1 ) - real( p2 ) ) == 0 && dblcmp( imag( p1 ) - imag( p2 ) ) == 0;
}

bool samecircle( const circle & c1, const circle & c2 )
{
	if( dblcmp( c1.r - c2.r ) == 0 && samepoint( c1.p, c2.p ) )
		return true;
	return false;
}

void intersect_circle_circle( const circle & c1, const circle & c2, point & p1, point & p2 )
{
	double d = abs( c1.p - c2.p );
	double s = c1.r * c1.r + d * d - c2.r * c2.r;
	double t = c2.r * c2.r + d * d - c1.r * c1.r;
	point p = c1.p + ( c2.p - c1.p ) * s / ( s + t );
	point p0( imag( c2.p ) - imag( c1.p ), real( c1.p ) - real( c2.p ) );
	double d1 = abs( p - c1.p );
	double l = abs( p0 );
	double m = sqrt( c1.r * c1.r - d1 * d1 ) / l;
	p1 = p + p0 * m;
	p2 = p - p0 * m;
}

void myunique( vector<double> & v )
{
    vector<double> u = v;
    v.clear( );
    v.push_back( u[0] );
    for( int i = 1; i < u.size( ); i++ )
        if( dblcmp( u[i] - u[i-1] ) != 0 )
            v.push_back( u[i] );
}

void lisanhua( int n )
{
    point p1, p2;
    for( int i = 1; i <= n; i++ )
    {
        vec.push_back( real( c[i].p ) + c[i].r );
        vec.push_back( real( c[i].p ) - c[i].r );
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = i + 1; j <= n; j++ )
        {
            double d = abs( c[i].p - c[j].p );
			if( samecircle( c[i], c[j] ) )continue;
			if( dblcmp( c[i].r + c[j].r - d ) < 0 ||
				dblcmp( fabs( c[i].r - c[j].r ) - d ) > 0 )continue;
            intersect_circle_circle( c[i], c[j], p1, p2 );
			inter.push_back( p1 );
			inter.push_back( p2 );
            vec.push_back( real( p1 ) );
            vec.push_back( real( p2 ) );
        }
    }
    sort( vec.begin( ), vec.end( ) );
    myunique( vec );
}

bool cmp( const node & a, const node & b )
{
	return a.mid > b.mid;
}

double solve( double x1, double x2, const int & n )
{
    node tmp;
	double y1, y2, y3, y4, x = ( x1 + x2 ) / 2;
    point p1, p2;
	double d, d1, d2, r, dis, px, py, angle, t, t1, t2;
    vector<node> V;
    for( int i = 1; i <= n; i++ )
    {
		r = c[i].r,  px = real( c[i].p ), py = imag( c[i].p ); 
        d1 = fabs( px - x1 ) - r;
        d2 = fabs( px - x2 ) - r;
        if( dblcmp( d1 ) > 0 || dblcmp( d2 ) > 0 ) return 0;

		t1 = r * r - ( px - x1 ) * ( px - x1 );
		if( t1 < 0 ) t1 = 0;
        d1 = sqrt( t1 );
        p1 = point( x1, py - d1 );
		
		t2 = r * r - ( px - x2 ) * ( px - x2 );
        if( t2 < 0 ) t2 = 0;
		d2 = sqrt( t2 );
        p2 = point( x2, py - d2 );
		
		t = r * r - ( px - x ) * ( px - x );
		if( t < 0 ) t = 0;
		d = sqrt( t );
	    
        dis = abs( p1 - p2 );
		t = ( r * r + r * r - dis * dis ) / ( 2 * r * r );
		if( t < -1 ) t = -1;
		if( t > 1 ) t = 1;
        angle = acos( t );

		//tmp.area = c[i].r * c[i].r * angle / 2 - c[i].r * c[i].r * sin( angle ) / 2;
        tmp.area = c[i].r * c[i].r * angle / 2 - fabs( p1 - c[i].p ^ p2 - c[i].p ) / 2;
        tmp.y1 = imag( p1 );
        tmp.y2 = imag( p2 );
		tmp.mid = imag( c[i].p ) - d;
        tmp.flag = -1;  // 圆弧朝上
        V.push_back( tmp );

        tmp.y1 = imag( c[i].p ) + d1;
        tmp.y2 = imag( c[i].p ) + d2;
		tmp.mid = imag( c[i].p ) + d;
        tmp.flag = 1;  // 圆弧朝下
        V.push_back( tmp );
    }
    sort( V.begin( ), V.end( ), cmp );
    int cnt = 0, flag = 0;
    double ans = 0;
    for( int i = 0; i < V.size( ); i++ )
    {
        cnt += V[i].flag;
        if( cnt == n )
        {
            y1 = V[i].y1;
            y2 = V[i].y2;
            ans += V[i].area;
            flag = 1;
        }
        if( cnt == n-1 && flag )
        {
            y3 = V[i].y1;
            y4 = V[i].y2;
            ans += V[i].area;
            flag = 2;
            break;
        }
    }
    if( flag == 2 ) ans = ans + ( y1 - y3 + y2 - y4 ) * ( x2 - x1 ) / 2;
    return ans;
}

double circle_jiao_area( int n )
{
	vec.clear( );
	lisanhua( n );
    double ans = 0;
    for( int i = 1; i < vec.size( ); i++ )
    {
		double tmp = solve( vec[i-1], vec[i], n );
        ans = ans + tmp;
    }
	return ans;
}

int main( )
{
    double r, x, y, ans1, ans;
    int n;
	point P[4];
	circle C[10];
	int k = 1;
	while( 1 )
    {
		int cnt = 0;
        for( int i = 0; i < 4; i++ )
        {
            scanf("%lf%lf",&x,&y);
			if( x == 0 && y == 0 )cnt++;
            P[i] = point( x, y );
        }
		if( cnt == 4 )break;
		C[1] = circle( ( P[0] + P[2] ) / 2.0, abs( P[0] - P[2] ) / 2 );
		C[2] = circle( ( P[0] + P[3] ) / 2.0, abs( P[0] - P[3] ) / 2 );
		C[3] = circle( ( P[1] + P[2] ) / 2.0, abs( P[1] - P[2] ) / 2 );
		C[4] = circle( ( P[1] + P[3] ) / 2.0, abs( P[1] - P[3] ) / 2 );
		n = 4;
		double ans = 0;
		for( int i = 1; i <= 4; i++ )
		{
			ans += pi * C[i].r * C[i].r;
		}
		for( int i =1; i <= 4; i++ )
		{
			for( int j = i + 1; j <= 4; j++ )
			{
				c[1] = C[i], c[2] = C[j];
				ans -= circle_jiao_area( 2 );
			}
		}
		for( int i = 1; i <= 4; i++ )
			for( int j = i + 1; j <= 4; j++ )
				for( int k = j + 1; k <= 4; k++ )
				{
					c[1] = C[i], c[2] = C[j], c[3] = C[k];
					ans += circle_jiao_area( 3 );
				}
		for( int i = 1; i <= 4; i++ )
			c[i] = C[i];
		ans -= 2 * circle_jiao_area( 4 );
		printf("Case %d: %.3lf\n\n",k++,ans);
    }
    return 0;
}
