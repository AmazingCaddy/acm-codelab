#include<iostream> 
#include<complex>
#include<cmath>
#include<algorithm>
using namespace std;
typedef complex<double> point;

const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos( -1.0 );
const int maxn = 103;
struct line
{
	point a, b;
	line( ){ }
	line( point u, point v ) : a( u ), b( v ) {  }
};
line L[maxn];
bool vis[maxn];

int dblcmp( double x ){ return ( x < -eps ? -1 : x > eps ); }
double operator^( point p1, point p2 ){ return imag( conj( p1 ) * p2 ); }  // 叉积
double operator&( point p1, point p2 ){ return real( conj( p1 ) * p2 ); }  // 点积
// 两直线交点，求交点之前先判断是否平行
point operator*( line u, line v )
{
	double t = v.a - u.a ^ v.b - u.a;
	double s = v.b - u.b ^ v.a - u.b;
	return u.a + ( u.b - u.a ) * t / ( t + s );
}
// 点到直线的距离
double DisPointToLine( point p, line l ){ return fabs( l.a - p ^ l.b - p ) / abs( l.a - l.b ); }
// 判断两直线平行
bool LineParallel( line u, line v ) { return dblcmp( ( u.a - u.b ^ v.a - v.b ) ) == 0; }
// 直线向左侧平移 
line Translation( line l )
{
	point p = ( l.b - l.a ) * point( 0.0, 1000.0 / abs( l.b - l.a ) );
	return line( l.a + p, l.b + p );
}
// 以l.a为原点，逆时针旋转90度 
line Rotation( line l )
{
	point p = ( l.b - l.a ) * point( 0.0, 1.0 );
	return line( l.a, l.a + p );
}
// 求 u 与 v 的一条角平分线
line GetLine( line u, line v )
{
	line l1 = Translation( u );
	line l2 = Translation( v );
	return line( u * v, l1 * l2 );
}

bool check( point p, int n, double val )
{
	int i;
	double D;
	for( i = 0; i < n; i++ )
	{
		D = DisPointToLine( p, L[i] );
		if( dblcmp( D - val ) != 0 )return false;
	}
	return true;
}

bool same_point( point p1, point p2 )
{
	return dblcmp( imag( p1 ) - imag( p2 ) ) == 0 && dblcmp( real( p1 ) - real( p2 ) ) == 0;
}

int MyUnique( point p[], int n )
{
	int i, len = 1;
	for( i = 1; i < n; i++ )
	{
		if( !same_point( p[i], p[i-1] ) )
			p[len++] = p[i];
	}
	return len;
}

void solve( int n )
{
	if( n < 3 ){ printf("Many\n"); return; }
	int i, j;
	line l[4], u, v, w;
	memset( vis, false, sizeof( vis ) );
	vis[0] = true;
	u = L[0];
	for( i = 1; i < n; i++ )
	{
		if( !LineParallel( L[0], L[i] ) )
		{
			vis[i] = true;
			v = L[i];
			break;
		}
	}
	if( i == n ){ printf("None\n"); return; }
	l[0] = GetLine( u, v );
	l[1] = Rotation( l[0] );
	for( i = 1; i < n; i++ )
	{
		if( !vis[i] && ( !LineParallel( u, L[i] ) || !LineParallel( v, L[i] ) ) )
		{
			vis[i] = true;
			w = L[i];
			break;
		}
	}
	if( !LineParallel( u, w ) )
	{
		l[2] = GetLine( u, w );
		l[3] = Rotation( l[2] );
	}
	else 
	{
		l[2] = GetLine( v, w );
		l[3] = Rotation( l[2] );
	}
	point p[4];
	double val[4];
	int len = 0;
	if( !LineParallel( l[0], l[2] ) ) { p[len] = l[0] * l[2]; val[len++] = DisPointToLine( p[len], u ); }
	if( !LineParallel( l[0], l[3] ) ) { p[len] = l[0] * l[3]; val[len++] = DisPointToLine( p[len], u ); }
	if( !LineParallel( l[1], l[2] ) ) { p[len] = l[1] * l[2]; val[len++] = DisPointToLine( p[len], u ); }
	if( !LineParallel( l[1], l[3] ) ) { p[len] = l[1] * l[3]; val[len++] = DisPointToLine( p[len], u ); }
	len = MyUnique( p, len );
	int cnt = 0;
	point P;
	for( i = 0; i < len; i++ )
	{
		if( check( p[i], n, val[i] ) )
		{
			P = p[i];
			cnt++;
		}
	}
	if( cnt == 0 )printf("None\n");
	else if( cnt == 1 )printf("%.5lf %.5lf\n",P.real( ), P.imag( ) );
	else printf("Many\n");
}

int main( )
{
	int i, n;
	double x1, x2, y1, y2;
	while( scanf("%d",&n) != EOF )
	{
		for( i = 0; i < n; i++ )
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			L[i] = line( point( x1, y1 ), point( x2, y2 ) );
		}
		solve( n );
	}
	return 0;
}
