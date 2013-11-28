#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
typedef complex<double> point;

const int maxn = 103;
const double eps = 1e-13;
const double inf = 1e100;

struct node
{
	double y;
	int id, flag;
	bool operator<( const node & a )const 
	{
		return y < a.y;
	}
};

struct circle
{
	point p;
	double r;
	circle( ){ }
	circle( point u, double x ) : p( u ), r( x ){ }
};
circle c[maxn];
vector<double> vec;
int vis[maxn];

double operator ^ ( const point p1, const point p2 ) { return imag( conj( p1 ) * p2 ); }
double operator & ( const point p1, const point p2 ) { return real( conj( p1 ) * p2 ); }
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

void intersect_circle_circle( circle c1, circle c2, point & p1, point & p2 )
{
	double d = abs( c1.p - c2.p );
	double s = c1.r * c1.r + d * d - c2.r * c2.r;
	double t = c2.r * c2.r + d * d - c1.r * c1.r;
	point p = c1.p + ( c2.p - c1.p ) * s / ( s + t );
	point p0( imag(c2.p) - imag(c1.p), real(c1.p) - real(c2.p) );
	double d1 = abs( p - c1.p );
	double l = abs( p0 );
	double m = sqrt( c1.r * c1.r - d1 * d1 ) / l;
	p1 = p + p0 * m;
	p2 = p - p0 * m;
}

void lisanhua( int n )
{
	vec.clear( );
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
			double t = fabs( c[i].r - c[j].r );
			if( dblcmp( c[i].r + c[j].r - abs( c[i].p - c[j].p ) ) < 0 ||
				dblcmp( t - abs( c[i].p - c[j].p ) ) > 0 )continue;
			intersect_circle_circle( c[i], c[j], p1, p2 );
			vec.push_back( real( p1 ) );
			vec.push_back( real( p2 ) );
		}
	}
	sort( vec.begin( ), vec.end( ) );
}

void solve( double x, int n )
{
	vector<node> V;
	node tmp;
	set<int> ID;
	for( int i = 1; i <= n; i++ )
	{
		if( dblcmp( fabs( real( c[i].p ) - x ) - c[i].r ) > 0 )
			continue;
		double d = sqrt( c[i].r * c[i].r - 
			( real( c[i].p ) - x ) * ( real( c[i].p ) - x ) );
		tmp.y = imag( c[i].p ) - d;
		tmp.id = -i;
		tmp.flag = 0;
		V.push_back( tmp );
		tmp.y = imag( c[i].p ) + d;
		//tmp.id = i;
		tmp.flag = 1;
		V.push_back( tmp );
	}
	sort( V.begin( ), V.end( ) );
	for( int i = 0; i < V.size( ); i++ )
	{
		if( ID.size( ) != 0 ) vis[-(*ID.begin())] = 1;
		if( V[i].flag == 0 ) ID.insert( V[i].id );
		else ID.erase( V[i].id );
		if( ID.size( ) != 0 ) vis[-(*ID.begin())] = 1;
	}
}

int main(int argc, char *argv[])
{
	int n;
	double x, y, r;
	while( scanf("%d",&n) && n )
	{
		for( int i = 1; i <= n; i++ )
		{
			scanf("%lf%lf%lf",&x,&y,&r);
			c[i] = circle( point( x, y ), r );
		}
		lisanhua( n );
		memset( vis, 0, sizeof( vis ) );
		for( int i = 1; i < vec.size( ); i++ )
		{
			if( dblcmp( vec[i] - vec[i-1] ) == 0 )continue;
			solve( ( vec[i] + vec[i-1] ) / 2, n );
		}
		int ans = 0;
		for( int i = 1; i <= n; i++ )
			if( vis[i] )ans++;
		printf("%d\n",ans);
	}
	return 0;
}
