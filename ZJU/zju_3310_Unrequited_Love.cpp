//#include<iostream>
//#define MAXN 1000005
//using namespace std;
//int a[MAXN],dp[MAXN];
//int max( int a, int b )
//{
//	return a>b?a:b;
//}
//int main( )
//{
//	int n,i,ans1,ans2,ans,t;
//	while( scanf("%d",&n) != EOF )
//	{
//		for( i=1; i<=n; i++ )
//			scanf("%d",&a[i]);
//		if( n==1 )ans=a[1];
//		else if( n==2 )ans=max( a[1], a[2] );
//		else if( n==3 )ans=max( max( a[1], a[2] ), a[3] );
//		else 
//		{
//			memset( dp, 0, sizeof(dp) );
//			dp[1]=a[1],dp[2]=0,dp[3]=a[1]+a[3];
//			ans1=dp[3];
//			for( i=4; i<=n-1; i++ )
//			{
//				dp[i]=max( dp[i-2], dp[i-3] )+a[i];
//				ans1=max( ans1, dp[i] );
//			}
//			memset( dp, 0, sizeof(dp) );
//			dp[1]=0,dp[2]=a[2],dp[3]=a[3];
//			ans2=max( dp[2], dp[3] );
//			for( i=4; i<=n; i++ )
//			{
//				dp[i]=max( dp[i-2], dp[i-3] )+a[i];
//				ans2=max( ans2, dp[i] );
//			}
//			ans=max( ans1, ans2 );
//			printf("%d\n",ans);
//		}
//	}
//	return 0;
//}