#include<iostream>
#define MAXN 102
using namespace std;
int dp[2][MAXN][10];

int main( )
{
	int tower[MAXN][MAXN];
	int i,j,k,t,n;
	scanf("%d",&t);
	while( t-- )
	{
		//memset( tower, 0, sizeof(tower) );
		scanf("%d",&n);
		for( i=1; i<=n; i++ )
			for( j=1; j<=i; j++ )
				scanf("%d",&tower[i][j]);
		memset( dp, 0, sizeof(dp) );
		dp[1][1][tower[1][1]%10]=1;
		for( i=1; i<n; i++ )
		{
			for( j=1; j<=i; j++ )
			{
				for( k=0; k<10; k++ )
					if( dp[i%2][j][k] )
					{
						dp[(i+1)%2][j][(k*tower[i+1][j])%10]=1;
						dp[(i+1)%2][j+1][(k*tower[i+1][j+1])%10]=1;
					}
			}
			memset( dp[i%2], 0, sizeof(dp[i%2]) );
		}
		for( i=9; i>=0; i-- )
		{
			for( j=1; j<=n; j++ )
			if( dp[n%2][j][i] )
			{
				printf("%d\n",i);
				break;
			}
			if( j != n+1 )break;
		}
	}
	return 0;
}