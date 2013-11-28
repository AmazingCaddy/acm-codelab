#include<iostream>
#include<cmath>
#include<cstdio>
#define maxn 100005
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;
struct point{ double x, y, z; };
struct line{ point a, b; };
struct plane{ point a, b, c; };
point pp[maxn];
int dblcmp( double x ){ return ( x < -eps ? -1 : x > eps ); }
point xmult( point u, point v )
{
	point ret;
	ret.x = u.y * v.z - v.y * u.z;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - u.y * v.x;
	return ret;
}
double dmult( point u, point v ){ return u.x * v.x + u.y * v.y + u.z * v.z; }
point subt( point u, point v )
{
	point ret;
	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	ret.z = u.z - v.z;
	return ret;
}
double Distance( point p1, point p2 )
{
	return sqrt( ( p1.x - p2.x )*( p1.x - p2.x )+( p1.y - p2.y )*( p1.y - p2.y )+( p1.z - p2.z )*( p1.z - p2.z ) );
}
double vlen( point p ){ return sqrt( p.x * p.x + p.y * p.y + p.z * p.z ); }
double ptoline( point p, line l )
{
	return vlen( xmult( subt( p, l.a ), subt( l.b, l.a ) ) ) / Distance( l.a, l.b );
}
int main( )
{
	int n, i;
	point zju,Nep;
	double ans, D;
	line l; 
	while( scanf("%d",&n) != EOF )
	{
		scanf("%lf%lf%lf",&zju.x,&zju.y,&zju.z);
		scanf("%lf%lf%lf",&Nep.x,&Nep.y,&Nep.z);
		l.a = zju, l.b = Nep;
		for( i = 0; i < n; i++ )
			scanf("%lf%lf%lf",&pp[i].x,&pp[i].y,&pp[i].z);
		ans = 0.0;
		for( i = 0; i < n; i++ )
		{
			if( dblcmp( dmult( subt( Nep, zju ), subt( pp[i], zju ) ) ) >= 0 )
				D = ptoline( pp[i], l );
			else D = Distance( pp[i], l.a );
			if( D > ans ) ans = D;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}