//-(b*z0+c)/(z0*z0*d)+(a*z0*z0+b*z0+c)/(d*z0*z0)

#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef complex<double> point;

const double eps = 1e-8;
const double pi = acos( -1.0 );
const double EPS = 0.00005;

int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

int main( )
{
	//freopen("in1.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	double a, b, c, d, x, y, R;
	int cas;
	point z0, C( 0, 2 * pi ), ans;
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&x,&y,&R);
		z0 = point( x, y );
		int flag = dblcmp( abs( z0 ) - R );
		if( abs( z0 ) < eps ) ans = a / d * C;
		else
		{
			if( flag <= 0 )
			{
				ans = -( b * z0 + c ) / ( d * z0 * z0 ) + 
					( a * z0 * z0 + b * z0 + c ) / ( d * z0 * z0 );
				ans = ans * C;
			}
			else 
			{
				ans = -( b * z0 + c ) / ( d * z0 * z0 );
				ans = ans * C;
			}
		}
		double t1 = real( ans ), t2 = imag( ans );
		//int e1 = dblcmp( t1 ), e2 = dblcmp( t2 );
		if( fabs( t1 ) >= EPS && fabs( t2 ) >= EPS )
		{
			if( t2 >= EPS ) printf("%.4lf+%.4lfi\n",t1,t2);
			else printf("%.4lf%.4lfi\n",t1,t2);
		}
		else if( fabs( t1 ) < EPS && fabs( t2 ) >= EPS )
			printf("%.4lfi\n",t2);
		else if( fabs( t1 ) >= EPS && fabs( t2 ) < EPS )
			printf("%.4lf\n",t1);
		else printf("0.0000\n");
	}
	return 0;
}
