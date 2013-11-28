//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define MAXN 65600
//#define MAXM 50005
//using namespace std;
//int n,m;
//int a[MAXM],b[MAXM];
//int dp[MAXN];
//int max( int a, int b )
//{
//	return a>b?a:b;
//}
//int main( )
//{
//	int i,j,t,y,x,flag,ans,k,p;
//	while( scanf("%d%d",&n,&m) != EOF )
//	{
//		if( m==0 )
//		{
//			printf("0\n");
//			continue;
//		}
//		memset( a, 0, sizeof(a) );
//		memset( b, 0, sizeof(b) );
//		k=0;
//		for( i=0; i<m; i++ )
//		{
//			scanf("%d",&t);
//			y=0;
//			flag=0;
//			for( j=0; j<t; j++ )
//			{
//				scanf("%d",&x);
//				x--;
//				if( (y&(1<<x))==0 ) y=y|(1<<x);
//				else flag=1;
//			}
//			if( !flag )a[k++]=y;
//		}
//		sort( a, a+k );
//		b[0]=a[0];
//		p=1;
//		for( i=1; i<k; i++ )
//		{
//			for( j=0; j<p; j++ )
//				if( ( a[i] & b[j] ) == b[j] )
//					break;
//			if( j==p )b[p++]=a[i];
//		}
//		memset( dp, 0, sizeof(dp) );
//		for( i=0; i<p; i++ )
//			for( j=(1<<n)-1; j>=0; j-- )
//				if( ( j & b[i] ) == 0 )
//					dp[j|b[i]]=max( dp[j]+1, dp[j|b[i]] );
//		ans=0;
//		for( i=0; i<(1<<n); i++ )
//			ans=max( ans, dp[i] );
//		printf("%d\n",ans);
//	}
//	return 0;
//}