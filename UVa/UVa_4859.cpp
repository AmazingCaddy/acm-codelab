// sigma(1/n) = ln n + r + 1 / 2n - 1 / 12n^2 + O(e/120n^4)
// r = 0.5772156649

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const double r = 0.5772156649;
const double eps = 1e-8;

int W, L;

double ln( double x )
{
	if( fabs( x ) < eps ) return 0;
	return log( x ) + 1 / ( 2 * x ) - 1 / ( 12 * x * x ) + r;
}

double solve( int a, int b )
{
	if( b - a + 1 < 10000 )
	{
		double ans = 0;
		for( int i = a; i <= b; i++ )
			ans += 1.0 / ( i + L );
		ans = ans * ( L + W ) / ( b - a + 1 );
		return ans;
	}
	return (W+L)*1.0/(b-a+1)*(ln( b + L ) - ln( L + a - 1 ));
}

int main( )
{
	int cas = 1;
	while( 1 )
	{
		scanf("%d%d",&W,&L);
		if( W == 0 && L == 0 ) break;
		printf("Case %d:\n",cas++);
		if( L == 0 && W % 8 )
		{
			printf("Situation Impossible.\n");
			continue;
		}
		int a = max( 0, ( W - 7 * L + 7 ) / 8 );
		int b = W / 8;
		printf("On Average Bob Reaches Round %.2lf\n",solve(a,b));
	}
	return 0;
}
