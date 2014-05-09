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

struct node
{
	double area;
	int flag;       // 标记圆弧是朝上还是朝下
	double y, y1, y2;
};

circle c[maxn];
vector<double> vec;
vector<point> inter;
double ans1, ans2;

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
	vec.clear( );
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
			vec.push_back( real( p1 ) );
			vec.push_back( real( p2 ) );
		}
	}
	sort( vec.begin( ), vec.end( ) );
	myunique( vec );
}

bool cmp( const node & a, const node & b )
{
	return a.y > b.y;
}

void solve( double x1, double x2, const int & n )
{
	node tmp;
	point p1, p2;
	double x, d, d1, d2, A, B, C, t, angle;
	vector<node> V;
	for( int i = 1; i <= n; i++ )
	{
		if( dblcmp( real( c[i].p ) - c[i].r - x2 ) >= 0 )continue;
		if( dblcmp( real( c[i].p ) + c[i].r - x1 ) <= 0 )continue;
		// d1 = fabs( real( c[i].p ) - x1 ) - c[i].r;
		// d2 = fabs( real( c[i].p ) - x2 ) - c[i].r;
		//if( dblcmp( d1 ) > 0 || dblcmp( d2 ) > 0 ) continue;

		d1 = c[i].r * c[i].r - ( real( c[i].p ) - x1 ) * ( real( c[i].p ) - x1 );
		if( d1 < 0 ) d1 = 0;
		d1 = sqrt( d1 );
		p1 = point( x1, imag( c[i].p ) - d1 );
		d2 = c[i].r * c[i].r - ( real( c[i].p ) - x2 ) * ( real( c[i].p ) - x2 );
		if( d2 < 0 ) d2 = 0;
		d2 = sqrt( d2 );
		p2 = point( x2, imag( c[i].p ) - d2 );
		x = ( x1 + x2 ) / 2;
		d = c[i].r * c[i].r - ( real( c[i].p ) - x ) * ( real( c[i].p ) - x );
		if( d < 0 ) d = 0;
		d = sqrt( d );

		A = abs( p1 - p2 );          // B = C = c[i].r;
		B = abs( p1 - c[i].p ), C = abs( p2 - c[i].p );
		t = ( B * B + C * C - A * A ) / ( 2 * B * C );
		if( t < -1 ) t = -1.0;
		if( t > 1 ) t = 1.0;
		angle = acos( t );

		tmp.area = c[i].r * c[i].r * ( angle - sin( angle ) ) / 2;
		tmp.y1 = imag( p1 );
		tmp.y2 = imag( p2 );
		tmp.y = imag( c[i].p ) - d;
		tmp.flag = 1;  // 圆弧朝上
		V.push_back( tmp );

		tmp.y1 = imag( c[i].p ) + d1;
		tmp.y2 = imag( c[i].p ) + d2;
		tmp.y = imag( c[i].p ) + d;
		tmp.flag = 2;  // 圆弧朝下
		V.push_back( tmp );
	}
	sort( V.begin( ), V.end( ), cmp );
	double y1, y2, y3, y4, tem;
	int cnt = 0;
	for( int i = 0; i < V.size( ); i++ )
	{
		tem = 0;
		y1 = V[i].y1, y2 = V[i].y2;
		if( V[i].flag == 1 )
		{
			cnt--;
			tem -= V[i].area;
		}
		else
		{
			cnt++;
			tem += V[i].area;
		}
		if( cnt > 0 )
		{
			if( V[i+1].flag == 1 )
			{
				tem += V[i+1].area;
			}
			else tem -= V[i+1].area;
			y3 = V[i+1].y1, y4 = V[i+1].y2;
			tem = tem + ( y1 - y3 + y2 - y4 ) * ( x2 - x1 ) * 0.5;
			if( cnt % 2 ) ans1 += tem;
			else ans2 += tem;
		}
		//y1 = y3, y2 = y4;
	}
}

int main( )
{
	double r, x, y;
	int n;
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 1; i <= n; i++ )
		{
			scanf("%lf%lf%lf",&x,&y,&r);
			c[i] = circle( point( x, y ), r );
		}
		lisanhua( n );
		ans1 = ans2 = 0;
		for( int i = 1; i < vec.size( ); i++ )
		{
			solve( vec[i-1], vec[i], n );
		}
		printf("%.5lf %.5lf\n",ans1, ans2);
	}
	return 0;
}

/*

3
0 0 2
2 0 2
1 0 1

*/
