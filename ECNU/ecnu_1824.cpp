#include<iostream>
#define MAXN 102
using namespace std;
int dp[2][MAXN][10];

int main( )
{
	int tower[MAXN][MAXN];
	int i,j,k,t,ans,n;
	scanf("%d",&t);
	while( t-- )
	{
		memset( tower, 0, sizeof(tower) );
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			for( j=n-i-1; j<=n-1; j++ )
				scanf("%d",&tower[i][j]);
		memset( dp, 0, sizeof(dp) );
		dp[0][n-1][tower[0][n-1]%10]=1;
		for( i=1; i<n; i++ )
		{
			for( j=n-i-1; j<=n-1; j++ )
			{
				if( j!=n-i-1 && j!=n-1 )
				{
					for( k=0; k<10; k++ )
						if( dp[(i-1)%2][j][k] || dp[(i-1)%2][j+1][k] )
							dp[i%2][j][(k+tower[i][j])%10]=1;
				}
				else if( j==n-i-1 )
				{
					for( k=0; k<10; k++ )
						if( dp[(i-1)%2][j+1][k] )
							dp[i%2][j][(k+tower[i][j])%10]=1;
				}
				else if( j==n-1 )
				{
					for( k=0; k<10; k++ )
						if( dp[(i-1)%2][j][k] )
							dp[i%2][j][(k+tower[i][j])%10]=1;
				}
			}
		}
		ans=-1;
		for( i=0; i<n; i++ )
			for( j=0; j<10; j++ )
				if( dp[(n-1)%2][i][j] && j>ans ) 
					ans=j;
		printf("%d\n",ans);
	}
	return 0;
}