#include<iostream>
#include<complex>
#include<algorithm>
#include<cmath>
using namespace std;
typedef complex<double> point;
const double eps = 1e-6;
double P,Q,R;

int dblcmp( double x ){ return ( x < -eps ? -1 : x > eps ); }

bool same_point( point a, point b )
{
	return dblcmp( a.imag( ) - b.imag( ) ) == 0 && 
		dblcmp( a.real( ) - b.real( ) ) == 0;
}
point a,b,c,d,p0,p1;

double check( double x )
{
	p1 = c + x * ( d - c );
	return abs( a - p0 ) / P + abs( p0 - p1 ) / R + abs( p1 - d ) / Q;
}

double tri_check( double x )
{
	double l = 0.0, r = 1.0, mid1, mid2;
	p0 = a + x * ( b - a );
	while( r - l > eps )
	{
		mid1 = l + ( r - l ) / 3.0;
		mid2 = mid1 + ( r - l ) / 3.0;
		if( check( mid1 ) < check( mid2 ) ) r = mid2;
		else l = mid1;
	}
	return check( l );
}

int main( )
{

	int t;
	double x1,x2,y1,y2,l,r,mid1,mid2;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a = point( x1, y1 );
		b = point( x2, y2 );
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		c = point( x1, y1 );
		d = point( x2, y2 );
		scanf("%lf%lf%lf",&P,&Q,&R);
		l = 0.0, r = 1.0;
		while( r - l > eps )
		{
			mid1 = l + ( r - l ) / 3.0;
			mid2 = mid1 + ( r - l ) / 3.0;
			if( tri_check( mid1 ) < tri_check( mid2 ) ) r = mid2;
			else l = mid1;
		}
		printf("%.2lf\n",tri_check( l ));
	}
	return 0;
}