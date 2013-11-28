////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-08-15 20:01:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3520
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:360KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
using namespace std;

typedef complex<double> point;
const int maxn = 220;
const double eps = 1e-8;
const double pi = acos( -1.0 );
const double inf = 1e6;

double operator ^( const point & p1, const point & p2 ) { return imag( conj( p1 ) * p2 ); }
double operator &( const point & p1, const point & p2 ) { return real( conj( p1 ) * p2 ); }
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct line
{
	point a, b;
	double angle;
	line( ){ }
	line( point u, point v ) : a( u ), b( v )
	{
		angle = arg( b - a );
	}
	bool operator<( const line & l ) const
	{
		return	dblcmp( angle - l.angle) < 0 || 
			dblcmp( angle - l.angle) == 0 && dblcmp( b - a ^ l.b - a ) < 0; 
	}
};

deque< point > P;
deque< int > E;
vector< line > cut;

bool onLeft( const point & p, const line & l )
{
	return dblcmp( l.b - l.a ^ p - l.a ) > 0;
}

point operator*( const line & l0, const line & l1 )
{
	double t = l0.a - l1.a ^ l0.b - l1.a;
    double s = l0.b - l1.b ^ l0.a - l1.b;
    return l1.a + ( l1.b - l1.a ) * t / ( t + s );
}

void MyUnique( )
{
	vector< line > tem;
	tem.push_back( cut[0] );
	for( int i = 1; i < cut.size( ); i++ )
	{
		if( dblcmp( tem.back( ).angle - cut[i].angle ) != 0 )
			tem.push_back( cut[i] );
	}
	cut = tem;
}

double solve( )
{
	sort( cut.begin( ), cut.end( ) );
	MyUnique( );
	point last;
	bool ok = false; 
	for( int i = 0; i < cut.size(); i++ )
	{
		int step = dblcmp( cut[i].angle - cut[0].angle -  pi );
		if( ok && onLeft( last, cut[i]) )continue;
		
		while( !P.empty( ) && !onLeft( P.back( ), cut[i] ) )
			P.pop_back( ), E.pop_back( );
		
		if( step >= 0 )
		{
			while( !P.empty( ) && !onLeft( P.front( ), cut[i]) )
				P.pop_front( ), E.pop_front( );
			if( P.empty( ) )return 0;
		}
		
		if( !E.empty( ) ) P.push_back( cut[E.back( )] * cut[i] );
		E.push_back( i );
		
		if( step > 0 )
			ok = true, last = cut[E.front( )] * cut[E.back( )];
	}
	
	P.push_back( last );
	
	double ans = 0;
	int sz = P.size( );
	for(int i = 0; i < sz; i++)
	{
		ans += ( P[i] ^ P[(i+1) % sz] );
	}
	return fabs( ans / 2 );
}

bool cmp( const point & a, const point & b )
{
	return real(a) < real(b) || real(a)==real(b) && imag(a) < imag(b);
}

void Convex_Hull( vector<point> & p, vector<point> & poly )
{ 
	int sz = 0;
	poly.clear( );
	
	sort( p.begin( ), p.end( ), cmp );
	
	for( int i = 0; i < p.size( ); ++i )
	{
		while( sz >= 2 && dblcmp( poly[sz-2] - p[i] ^ poly[sz-1] - p[i] ) <= 0 )
		    poly.pop_back(), sz--;
		poly.push_back( p[i] );
		sz++;
	}
	int k = sz;
	for(int i = p.size() - 2; i >= 0; i--)
	{
		while( sz > k && dblcmp( poly[sz-2] - p[i] ^ poly[sz-1] - p[i] ) <= 0 )
		    poly.pop_back(), sz--;
		poly.push_back( p[i] );
		sz++;
	}
	poly.pop_back();
}

vector< point > pp;
point a[maxn], b[maxn];
double AREA;
int n, m;

int check( double x, const point & v )
{
	vector<point> c;
	vector<point> d;
	point u = v * x;
	for( int i = 0; i < m; i++ )
	{
		c.push_back( b[i] );
		c.push_back( b[i] + u );
	}
	Convex_Hull( c, d );
	int sz = d.size( );
	P.clear( );
	E.clear( );
	cut.clear( );
	for( int i = 0; i < sz; i++ )
		cut.push_back( line( d[i], d[(i+1)%sz] ) );
	for( int i = 0; i < n; i++ )
		cut.push_back( line( a[i], a[(i+1)%n] ) );
	double ans = solve( );
	return dblcmp( ans - AREA );
}

int main( int argc, char *argv[] )
{
	//freopen("1.std.in","r",stdin);
	//freopen("out.txt","w",stdout);
	double x, y, angle, rate;
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 0; i < n; i++ )
		{
			scanf("%lf%lf",&x,&y);
			a[i] = point( x, y );
		}
		a[n] = a[0];
		AREA = 0;
		for( int i = 1; i <= n; i++ )
			AREA += ( a[i-1] ^ a[i] );
		scanf("%d",&m);
		for( int i = 0; i < m; i++ )
		{
			scanf("%lf%lf",&x,&y);
			b[i] = point( x, y );
		}
		b[m] = b[0];
		scanf("%lf%lf",&angle,&rate);
		AREA = fabs( AREA ) / 2.0 * ( 1 - rate );
		angle = angle / 180.0 * pi;
		//printf("AREA = %.4lf\n",AREA);
		point v( cos( angle ), sin( angle ) );
		double l = 0, r = inf, mid;
		while( r - l > eps )
		{
			mid = ( l + r ) / 2;
			int t = check( mid, v );
			if( t >= 0 ) r = mid;
			else if( t == -1 ) l = mid;
		}
		if( dblcmp( mid - inf ) == 0 )printf("-1\n");
		else printf("%.4lf\n",mid);
	}
	return 0;
}
