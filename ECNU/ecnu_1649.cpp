#include<iostream>
#define N 10001
#define min(a,b) a>b?b:a
using namespace std;
int main()
{
	int i,j,c,m,n,x;
	int dp[N],text[N];
	scanf("%d",&c);
	while( c-- )
	{
		scanf("%d%d",&m,&n);
		dp[0]=0;
		for( i=1; i<=n; i++ )
			scanf("%d",&text[i]);
		for( i=1; i<=n; i++ )
		{
			dp[i]=dp[i-1]+(m-text[i])*(m-text[i]);
			x=m;
			for( j=i-1; j>=0; j-- )
			{
				if( j==i-1 )x=x-text[j+1];
				else x=x-text[j+1]-1;
				if( x>=0 )dp[i]=min(dp[i],dp[j]+x*x);
				else break;
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}