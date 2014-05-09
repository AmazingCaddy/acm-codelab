//  tower[0..n-1][0..n-1]，数塔靠右存储，tower[0..n-1][n]=0。

#include<iostream>
#define MAXN 505
using namespace std;

int maxn( int a, int b )
{
	return a>b?a:b;
}

int main( )
{
	int tower[MAXN][MAXN],dp[2][MAXN];
	int i,j,k,res,t,ans,n,a;
	scanf("%d",&t);
	while( t-- )
	{
		memset( tower, 0, sizeof(tower) );
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			for( j=n-i-1; j<=n-1; j++ )
				scanf("%d",&tower[i][j]);
		ans=0;
		for( k=0; k<n-1; k++ )
		{
			for( i=0; i<=n; i++ )
			{
				dp[0][i]=tower[0][i];
				dp[1][i]=0;
			}
			for( i=0; i<n-1; i++ )
			{
				if( i==k )
				{
					res=0;
					for( j=n-i-1; j<=n-1; j++ )
						res=maxn( res, dp[i%2][j] );
					for( j=n-i-2; j<=n-1; j++ )
						dp[(i+1)%2][j]=res+tower[i+1][j];
				}
				else 
					for( j=n-i-2; j<=n-1; j++ )
						dp[(i+1)%2][j]=tower[i+1][j]+maxn( dp[i%2][j], dp[i%2][j+1] );
			}
			a=0;	
			for( i=0; i<n; i++ )
				if( a<dp[(n-1)%2][i] )
					a=dp[(n-1)%2][i];
			if( a>ans ) ans=a;
		}
		printf("%d\n",ans);
	}
	return 0;
}