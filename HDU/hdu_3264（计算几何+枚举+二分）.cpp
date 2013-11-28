#include<iostream>
#include<cmath>
using namespace std;
struct point
{
	double x,y;
};
struct circle
{
	point p;
	double r;
};

const double eps = 1e-8;
const int maxn = 22;
const double RR = 100000.0;
const double pi = acos( -1.0 );
circle c[maxn];
int n;

double Dis( point p1, point p2 )
{
	return sqrt( ( p2.x - p1.x )*( p2.x - p1.x )+( p2.y - p1.y )*( p2.y - p1.y ) );
}
bool same_point( point p1, point p2 )
{
	return ( ( p1.x == p2.x ) && ( p1.y == p2.y ) );
}
double get_area( double r, double R, double d )
{
	double area, ceta1, ceta2;
	ceta1 = acos( ( r * r + d * d - R * R ) / ( 2 * r * d ) );
	ceta2 = acos( ( R * R + d * d - r * r ) / ( 2 * R * d ) );
	area = ceta1 * r * r + ceta2 * R * R - r * d * sin( ceta1 );
	return area;
}

bool check( double R, point p )
{
	int i;
	double d, area1, area2;
	for( i=0; i<n; i++ )
	{
		if( !same_point( c[i].p, p ) )
		{
			d = Dis( c[i].p, p );
			if( R - d < -eps )return false;
			if( d + c[i].r <= R )continue;
			area1 = get_area( c[i].r, R, d );
			area2 = c[i].r * c[i].r * pi / 2.0;
			if( area1 - area2 < -eps )return false;
		}
	}
	return true;
}

int main( )
{
	int i,t;
	double mid,low,high,ans;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%lf%lf%lf",&c[i].p.x,&c[i].p.y,&c[i].r);
		if( n == 1 ) ans = c[0].r / sqrt( 2.0 );
		else 
		{
			ans = RR;
			for( i=0; i<n; i++ )
			{
				low=0; high = RR;
				while( high - low > eps )
				{
					mid = ( low + high ) / 2.0;
					if( check( mid, c[i].p ) ) high = mid;
					else low = mid;
				}
				if( mid < ans ) ans = mid;
			}
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}