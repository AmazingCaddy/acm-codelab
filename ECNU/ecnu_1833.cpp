#include<iostream>
#include<cmath>
#define MAXN 100
#define pi 3.141592653589793
using namespace std;
int main()
{
	double sum,r[MAXN],h[MAXN];
	int i,c,n;
	scanf("%d",&c);
	while( c-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%lf",&r[i]);
		for( i=0; i<n; i++ )
			scanf("%lf",&h[i]);
		sum=pi*r[0]*r[0];
		for( i=0; i<n-1; i++ )
		{
			sum+=h[i]*2*pi*r[i];
			sum+=pi*fabs(r[i+1]*r[i+1]-r[i]*r[i]);
		}
		sum=sum+pi*r[n-1]*r[n-1]+h[n-1]*2*pi*r[n-1];
		printf("%.2lf\n",sum);
	}
	return 0;
}
