#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const double e = 2.71828182845904523536;

int main(int argc, char *argv[])
{
	int ua, u0, u1, t1, n;
	int t, q, s;
	const double ln = log10( e );
	scanf("%d",&t);
	for( int p = 1; p <= t; p++ )
	{
		scanf("%d%d%d%d%d",&ua,&u0,&u1,&t1,&n);
		printf("Case %d:\n",p);
		if( u1 == u0 )
		{
			for( int i = 0; i < n; i++ )
			{
				scanf("%d%d",&q,&s);
				//printf("Case %d:\n",p);
				double ans;
				if( q == 0 )
				{
					ans = 0;
				}
				else 
				{
					ans = u0;
				}
				printf("%.2lf\n",ans);
			}
		}
		else
		{
			double B = log10( 1.0 * (u0 - ua) ) / ln;
			double k = log10( 1.0 * ( u1 - ua ) / ( u0 - ua ) ) / ln / t1;
			for( int i = 0; i < n; i++ )
			{
				scanf("%d%d",&q,&s);
				
				double ans;
				if( q == 0 )
				{
					ans = log10( 1.0 *( s - ua ) / ( u0 - ua ) ) / ln / k;
				}
				else
				{
					ans = ua + ( u0 - ua ) * pow( e, k * s );
				}
				printf("%.2lf\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}
