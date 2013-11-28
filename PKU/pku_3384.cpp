//  holy cow -- haozi's template
#include<iostream>
#include<cstdio>
#include<complex>
#include<vector>
#include<deque>
#include<cmath>
#include<algorithm>

using namespace std;

const double eps = 1e-8;
const double inf = 10000;
const double PI  = acos(-1.0);
typedef complex<double> point;

double operator^( point p0, point p1 ) { return imag( conj(p0) * p1 ); }//计算叉积
int dcmp( double x ) { return x < -eps ? -1 : x > eps; }

point rotation( point p1, point p2, double r ) // 逆时针旋转90度,长度变为r
{
	point p;
	double t = r / abs( p2 - p1 );
	p.real( ( imag(p1) - imag(p2) ) * t );
	p.imag( ( real(p2) - real(p1) ) * t );
	return p;
}

struct line
{
	point a, b;
	double angle;
	line( ){ }
	line( point u, point v ):a(u), b(v)
	{
		angle = arg( b - a );   //计算幅角
	}
	bool operator<( const line & l ) const
	{
		return	dcmp( angle - l.angle ) < 0 || dcmp( angle - l.angle) == 0 && dcmp( b - a ^ l.b - a ) < 0; 
	}
};

deque<point> P;
deque<int> E;
vector<line> cut;
vector<point> pp;

bool onLeft( point p, line l )
{
	return dcmp( l.b - l.a ^ p - l.a ) >= 0;
}

point operator*( line l0, line l1 )  // 计算两直线的交点
{
	double t = l0.a - l1.a^ l0.b - l1.a;
    double s = l0.b - l1.b^ l0.a - l1.b;
    return l1.a + ( l1.b - l1.a ) * t / ( t + s );
}

void MyUnique( )
{
	vector<line> tem;
	tem.push_back( cut[0] );
	for( int i = 1; i < cut.size( ); i++ )
	{
		if( dcmp( tem.back( ).angle - cut[i].angle ) != 0 )
			tem.push_back( cut[i] );
	}
	cut = tem;
}

void solve( )
{
	sort( cut.begin( ), cut.end( ) );
	MyUnique( );
	point last;
	bool ok = false; 
	for( int i = 0; i < cut.size( ); i++ )
	{
		int step = dcmp( cut[i].angle - cut[0].angle -  PI );
		if( ok && onLeft( last, cut[i] ) )continue;
		
		while( !P.empty( ) && !onLeft( P.back( ), cut[i] ) ) P.pop_back( ), E.pop_back( );
		
		if( step >= 0 )
		{
			while( !P.empty( ) && !onLeft( P.front( ), cut[i]) ) P.pop_front( ), E.pop_front( );
			if( P.empty( ) ) return ;
		}
		
		if( !E.empty( ) )P.push_back( cut[ E.back( ) ] * cut[i] );
		E.push_back( i );
		
		if( step > 0 )ok = true, last = cut[ E.front( ) ] * cut[ E.back( ) ];
	}
	P.push_back( last );
}

int main( int argc, char *argv[] )
{
	int i,n,sz,j;
	double x,y,r,ans,t;
	point p1,p2,p;
	while( scanf("%d%lf",&n,&r) != EOF )
	{
		cut.clear( );
		P.clear( );
		E.clear( );
		pp.clear( ); 
		//cut.push_back( line( point( 0, 0 ), point( inf, 0 ) ) );
		//cut.push_back( line( point( inf, 0 ), point( inf, inf ) ) );
		//cut.push_back( line( point( inf, inf ), point( 0, inf ) ) );
		//cut.push_back( line( point( 0, inf ), point( 0, 0 ) ) );
		for( i = 0; i < n; i++ )
		{
			scanf("%lf %lf", &x, &y );
			pp.push_back( point( x, y ) );
			//cut.push_back( line( point( x1,y1 ), point( x2, y2 ) ) );
		}
		sz=pp.size( );
		p = rotation( pp[0], pp[sz-1], r );
		cut.push_back( line( pp[0]+p, pp[sz-1]+p ) );
		for( i=sz-1; i>0; i-- )
		{
			p = rotation( pp[i], pp[i-1], r );
			cut.push_back( line( pp[i]+p, pp[i-1]+p ) );
		}
		solve( );
		sz = P.size( );
		ans = -1.0;
		for( i=0; i<sz; i++ )
		{
			for( j=0; j<sz; j++ )
			{
				t = abs( P[i]-P[j] );
				if( t > ans )
				{
					ans = t;
					p1 = P[i];
					p2 = P[j];
				}
			}
		}
		printf("%.4lf %.4lf %.4lf %.4lf\n",p1.real( ),p1.imag( ),p2.real( ),p2.imag( ));
	}
	return 0;
}
