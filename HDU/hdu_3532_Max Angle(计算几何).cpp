#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
using namespace std;
typedef complex<double> point;

const double eps = 1e-8;
const int maxn = 1004;
const double pi = acos( -1.0 );
const double inf = 1e10;

double operator ^ ( const point & p1, const point & p2 ){ return imag( conj( p1 ) * p2 ); }
double operator & ( const point & p1, const point & p2 ){ return real( conj( p1 ) * p2 ); }
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

double min( double x, double y ){ return ( x < y ? x : y ); }
double max( double x, double y ){ return ( x > y ? x : y ); }

point p[maxn];
double angle[maxn];

int main( )
{
	int n;
	double x, y;
	while( scanf("%d",&n) && n > 0 )
	{
		for( int i = 0; i < n; i++ )
		{
			scanf("%lf%lf",&x,&y);
			p[i] = point( x, y );
		}
		double ans = 0;
		for( int i = 0; i < n; i++ )
		{
			int len = 0;
			for( int j = 0; j < n; j++ )
				if( j != i ) angle[len++] = arg( p[j] - p[i] );
			sort( angle, angle + len );
			double angle1 = fabs( ( angle[len-1] - angle[0] ) - 2 * pi );
			double angle2 = 2 * pi - angle1;
			double tmp = min( angle1, angle2 );
			for( int j = 1; j < len; j++ )
			{
				angle1 = angle[j] - angle[j-1];
				angle2 = 2 * pi - angle1;
				tmp = min( tmp, min( angle1, angle2 ) );
			}
			ans = max( ans, tmp );
		}
		ans = ans / pi * 180;
		printf("%.4lf\n",ans);
	}
	return 0;
}
