#include<iostream>
#include<complex>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef complex<double> point;

const int maxn = 120;
const double pi = acos( -1.0 );
const double eps = 1e-8;

struct circle
{
    point p;
    double r;
    circle( ){ }
    circle( point _p, double _r ) : p( _p ), r( _r ) { }
};

circle c[maxn];
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

void lisanhua( int n )
{
    point p1, p2;
    for( int i = 1; i <= n; i++ )
    {
        inter.push_back( point( real( c[i].p ) + c[i].r, imag( c[i].p ) ) );
        inter.push_back( point( real( c[i].p ) - c[i].r, imag( c[i].p ) ) );
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
        }
    }
}

int check( const point & p, const int & n )
{
	int cnt = 0;
	for( int i = 1; i <= n; i++ )
		if( dblcmp( abs( p - c[i].p ) - c[i].r ) <= 0 )
			cnt++;
	return cnt;
}

int main( )
{
    double r, x, y;
    int n;
	while( scanf("%d",&n) != EOF )
    {
        for( int i = 1; i <= n; i++ )
        {
            scanf("%lf%lf%lf",&x,&y,&r);
            c[i] = circle( point( x, y ), r );
        }
		inter.clear( );
        lisanhua( n );
        int ans = 0;
		for( int i = 0; i < inter.size( ); i++ )
		{
			int tmp = check( inter[i], n );
			if( tmp > ans ) ans = tmp;
		}
		printf("%d\n",ans);
    }
    return 0;
}
