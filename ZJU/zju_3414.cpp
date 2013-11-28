#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef complex<double> point;

const int maxn = 1005;
const double eps = 1e-8;
double operator ^( const point &p1, const point &p2 ) { return imag( conj( p1 ) * p2 ); }
double operator &( const point &p1, const point &p2 ) { return real( conj( p1 ) * p2 ); }
int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
point p[ maxn ];
point ans[ maxn ];
double dis[ maxn ];

int main(int argc, char *argv[])
{
	int n, m, i, j, k, cas = 1;
	double sum, avg, x, y;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		p[ 0 ] = point( 0.0, 0.0 );
		n++;
		for( i = 1; i < n; i++ )
		{
			scanf("%lf%lf",&x,&y);
			p[ i ] = point( x, y );
		}
		sum = 0;
		for( i = 1; i < n; i++ )
		{
			dis[ i ] = abs( p[ i ] - p[ i - 1 ] );
			sum += dis[ i ];
		}
		avg = sum / ( m + 1 );
		k = 1;
		double avg1 = avg;
		point st = p[ 0 ], ed = p[ 1 ];

		for( j = 1, i = 1; i <= m; )
		{
			double d = abs( ed - st );
			if( d < avg1 )
			{
				avg1 -= d;
				st = ed;
				j++;
				ed = p[ j ];
			}
			else
			{
				ans[ i ] = st + ( ed - st ) * ( avg1 / d );
				st = ans[ i ];
				i++;
				avg1 = avg;
			}
		}
		printf("Route %d\n",cas++);
		for( j = 1; j < i; j++ )
			printf("CP%d: (%.3lf, %.3lf)\n",j,real(ans[j]), imag( ans[j]));
	}
	return 0;
}
