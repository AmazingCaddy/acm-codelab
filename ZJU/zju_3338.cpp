#include<iostream>
#include<cmath>
#include<complex>
using namespace std;
typedef complex<double> point;

const double eps = 1e-6;
point map[5];
double w, h;

int main( )
{
	int t, i;
	point p, q;
	double x, y, a1, b1, c1, a2, b2, c2;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%lf%lf",&w,&h);
		for( i = 0; i < 4; i++ )
		{
			scanf("%lf%lf",&x,&y);
			map[i] = point( x, y );
		}
		p = ( map[1] - map[0] ) / w;
		q = ( map[3] - map[0] ) / h;
		a1 = real( p ) - 1;  b1 = real( q );  c1 = real( map[0] );
		a2 = imag( p );  b2 = imag( q ) - 1;  c2 = imag( map[0] );
		x = ( b1 * c2 - b2 * c1 ) / ( a1 * b2 - b1 * a2 );
		y = ( a2 * c1 - a1 * c2 ) / ( a1 * b2 - b1 * a2 );
		printf("%.2lf %.2lf\n",x,y);
	}
	return 0;
}