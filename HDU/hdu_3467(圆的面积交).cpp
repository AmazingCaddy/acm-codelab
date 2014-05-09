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
    point p1, p2;
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
    if( dblcmp( imag( a.p1 ) - imag( b.p1 ) ) == 0 &&
        dblcmp( imag( a.p2 ) - imag( b.p2 ) ) == 0 )
        return a.flag > b.flag;
    if( dblcmp( imag( a.p1 ) - imag( b.p1 ) ) == 0 )
        return imag( a.p2 ) > imag( b.p2 );
    return imag( a.p1 ) > imag( b.p1 );
}

double solve( double x1, double x2, const int & n )
{
    node tmp;
    point p1, p2;
	double d1, d2, A, B, C, t, angle;
    vector<node> V;
    for( int i = 1; i <= n; i++ )
    {
        d1 = fabs( real( c[i].p ) - x1 ) - c[i].r;
        d2 = fabs( real( c[i].p ) - x2 ) - c[i].r;
        if( dblcmp( d1 ) > 0 || dblcmp( d2 ) > 0 ) return 0;

        d1 = sqrt( c[i].r * c[i].r - ( real( c[i].p ) - x1 ) * ( real( c[i].p ) - x1 ) );
        p1 = point( x1, imag( c[i].p ) - d1 );
        d2 = sqrt( c[i].r * c[i].r - ( real( c[i].p ) - x2 ) * ( real( c[i].p ) - x2 ) );
        p2 = point( x2, imag( c[i].p ) - d2 );

        A = abs( p1 - p2 ), B = abs( p1 - c[i].p ), C = abs( p2 - c[i].p );
		t = ( B * B + C * C - A * A ) / ( 2 * B * C );
        angle = acos( t );

        tmp.area = c[i].r * c[i].r * angle / 2 - fabs( p1 - c[i].p ^ p2 - c[i].p ) / 2;
        tmp.p1 = p1;
        tmp.p2 = p2;
        tmp.flag = 1;  // 圆弧朝上
        V.push_back( tmp );

        tmp.p1 = point( x1, imag( c[i].p ) + d1 );
        tmp.p2 = point( x2, imag( c[i].p ) + d2 );
        tmp.flag = 2;  // 圆弧朝下
        V.push_back( tmp );
    }
    sort( V.begin( ), V.end( ), cmp );
    int cnt = 0, flag = 0;
    double y1, y2, y3, y4, ans = 0;
    for( int i = 0; i < V.size( ); i++ )
    {
        cnt += ( V[i].flag == 1 ? -1 : 1 );
        if( cnt == n )
        {
            y1 = imag( V[i].p1 );
            y2 = imag( V[i].p2 );
            ans += V[i].area;
            flag = 1;
        }
        if( cnt == n-1 && flag )
        {
            y3 = imag( V[i].p1 );
            y4 = imag( V[i].p2 );
            ans += V[i].area;
            flag = 2;
            break;
        }
    }
    if( flag == 2 ) ans = ans + ( y1 - y3 + y2 - y4 ) * ( x2 - x1 ) / 2;
    return ans;
}

bool check( const point &p, const int & n )
{
	for( int i= 1; i <= n; i++ )
	{
		if( dblcmp( abs( p - c[i].p ) - c[i].r ) > 0 )
			return false;
	}
	return true;
}

int main( )
{
    double r, x, y;
    int n;
    //freopen("song.in","r",stdin);
	//freopen("out.txt","w",stdout);
	while( scanf("%lf",&r) != EOF )
    {
		n = 5;
        for( int i = 1; i <= n; i++ )
        {
            scanf("%lf%lf",&x,&y);
            c[i] = circle( point( x, y ), r );
        }
		inter.clear( );
        lisanhua( n );
        double ans = 0;
        for( int i = 1; i < vec.size( ); i++ )
        {
            double tmp = solve( vec[i-1], vec[i], n );
            ans = ans + tmp;
        }
		point p;
		int i;
		for( i = 0; i < inter.size( ); i++ )
		{
			if( check( inter[i], n ) )
			{
				p = inter[i];
				break;
			}
		}
		if( dblcmp( ans ) > 0 ) printf("The total possible area is %.2lf.\n",ans);
		else if( i == inter.size( ) )
			printf("Poor iSea, maybe 2012 is coming!\n");
		else printf("Only the point (%.2lf, %.2lf) is for victory.\n",real(p),imag(p));
    }
    return 0;
}

/*
1
3
0 0
1 0
0.5 0.86602540378443860
*/

/*
2
0 0 1.414213562373095
1 1 1.414213562373095
*/
