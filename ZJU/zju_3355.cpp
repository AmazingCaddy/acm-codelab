#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const double eps = 1e-8;
int dblcmp( double x ) { return x < -eps ? -1 : x > eps ; }
int main( )
{
	double a, b, c;
	int t;
	scanf("%d",&t);
	for( int p = 0; p < t; p++ )
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		double x = 1 / a + 1 / b + 1 / c;
		if( dblcmp( x - 1 ) < 0 )
		{
			printf("Aha\n");
		}
		else printf("No way\n");
	}
	return 0;
}
