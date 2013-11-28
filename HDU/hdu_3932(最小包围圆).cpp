/*
	最小包围圆
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
#include <ctime>
using namespace std;
typedef complex<double> point;

const int maxn = 1003;
const double eps = 1e-8;
const double inf = 1e100;

double operator ^( const point & p1, const point & p2 ) { return imag( conj( p1 ) * p2 ); }
double operator &( const point & p1, const point & p2 ) { return real( conj( p1 ) * p2 ); }
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }
struct line
{
	point a, b;
	line(){}
	line( point u, point v ) : a( u ) , b( v ) { }
};
//struct triangle { point p[3]; };
struct circle 
{
	point p; double r;
	circle( ){ }
	circle( point u, double x ) : p( u ), r( x ){ }
};

point a[maxn];

point operator *( const line &l1, const line &l2 )
{
	double t = l2.b - l1.a ^ l2.a - l1.a;
	double s = l2.a - l1.b ^ l2.b - l1.b;
	return l1.a + ( l1.b - l1.a ) * t / ( t + s );
}

// 逆时针旋转 90度
point ratate( point u, point v )
{
	return u + ( v - u ) * point( 0.0, 1.0 );
}

circle getcircle( point p1, point p2 )
{
	circle c;
	c.p = ( p1 + p2 ) / 2.0;
	c.r = abs( p1 - p2 ) / 2.0;
	return c;
}

circle getcircle( point A, point B, point C )
{
	circle tmp;
	//根据 S = a * b * c / R / 4; 求半径R
	double t = fabs( A - B ^ C - B ) / 2.0;
	tmp.r = abs( A - B ) * abs( A - C ) * abs( B - C ) / t / 4.0;
	point p1 = ( A + B ) / 2.0, p2 = ( A + C ) / 2.0;
	line l1 = line( p1, ratate( p1, B ) );
	line l2 = line( p2, ratate( p2, C ) );
	tmp.p = l1 * l2;
	return tmp;
}

circle C2( int n, int k1, int k2 )
{
	circle c = getcircle( a[k1], a[k2] );
	for( int i = 0; i < n; i++ )
	{
		if( dblcmp( abs( c.p - a[i] ) - c.r ) <= 0 ) continue;
		c = getcircle( a[i], a[k1], a[k2] );
	}
	return c;
}

circle C1( int n, int k1 )
{
	circle c = getcircle( a[0], a[k1] );
	for( int i = 1; i < n; i++ )
	{
		if( dblcmp( abs( c.p - a[i] ) - c.r ) <= 0 ) continue;
		c = C2( i, i, k1 );
	}
	return c;
}

circle C( int n )
{
	if( n == 1 ) return circle( a[0], 0.0 );
	circle c = getcircle( a[0], a[1] );
	for( int i = 2; i < n; i++ )
	{
		if( dblcmp( abs( c.p - a[i] ) - c.r ) <= 0 )continue;
		c = C1( i, i );
	}
	return c;
}

int main(int argc, char *argv[])
{
	int n;
	int X, Y;
	double x, y;
	//freopen("out.txt","w",stdout);
	//srand( (unsigned)time(0) );
	while( scanf("%d%d%d",&X, &Y, &n) != EOF )
	{
		for( int i = 0; i < n; i++ )
		{
			scanf("%lf%lf",&x,&y);
			a[ i ] = point( x, y );
		}
		circle c = C( n );
		double ans = 0;
		for( int i = 0; i < n; i++ )
		{
			double tmp = abs( c.p - a[ i ] );
			if( tmp > ans ) ans = tmp;
		}
		printf("(%.1lf,%.1lf).\n%.1lf\n",real(c.p), imag(c.p), ans);
	}
	return 0;
}

/*
8
1 0
2 0
3 1
2 2
1 2
0 1
2 1
1 1
*/
