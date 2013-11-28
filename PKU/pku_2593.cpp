#include<iostream>
#define MAXN 100001
#define max( n,m ) n>m?n:m	
using namespace std;
int dp1[MAXN],dp2[MAXN],a[MAXN];
int main()
{

	int t,i,m,n,sum1,sum2;
	while( scanf("%d",&n) && n )
	{
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		dp1[0]=a[0];sum1=a[0];
		for( i=1; i<n; i++ )
		{
			if( sum1<0 )
			{
				dp1[i]=max( dp1[i-1],a[i] );
				sum1=a[i];
			}
			else
			{
				sum1+=a[i];
				dp1[i]=max( sum1, dp1[i-1] );
			}
		}
		dp2[n-1]=a[n-1];sum2=a[n-1];
		for( i=n-2; i>=0; i-- )
		{
			if( sum2<0 )
			{
				dp2[i]=max( dp2[i+1], a[i] );
				sum2=a[i];
			}
			else 
			{
				sum2+=a[i];
				dp2[i]=max( sum2, dp2[i+1] );
			}
		}
		m=dp1[0]+dp2[1];
		for( i=1; i<n-1; i++ )
			if( m<dp1[i]+dp2[i+1] )
				m=dp1[i]+dp2[i+1];
		printf("%d\n",m);
	}
	return 0;
}