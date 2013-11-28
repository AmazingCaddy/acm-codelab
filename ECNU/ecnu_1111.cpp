#include<iostream>
#define MAXN 102
#define INF 100000000
//#define minn(a,b) a<b?a:b
using namespace std;
int minn( int a, int b )
{
	return a<b?a:b;
}
int main( )
{
	int dp[2][MAXN];
	int tower[MAXN][MAXN];
	int i,j,n,c,ans;
	scanf("%d",&c);
	while( c-- )
	{
		scanf("%d",&n);
		for( i=1; i<=n; i++ )
			for( j=1; j<=i; j++ )
				scanf("%d",&tower[i][j]);
		for( i=0; i<=n; i++ )
			dp[0][i]=dp[1][i]=INF;
		dp[1][1]=tower[1][1];
		for( i=2; i<=n; i++ )
			for( j=1; j<=i; j++ )
				dp[i%2][j]=tower[i][j]+minn( dp[(i-1)%2][j], dp[(i-1)%2][j-1] );
		ans=INF;
		for( i=1; i<=n; i++ )
			if( dp[n%2][i]<ans )ans=dp[n%2][i];
		printf("%d\n",ans);
	}
	return 0;
}