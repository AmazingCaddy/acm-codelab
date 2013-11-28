#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 2003;
int dp[102][maxn];
int w[102], s[102];

int max( int a, int b, int c )
{
	int tmp = ( a > b ? a : b );
	return ( tmp > c ? tmp : c );
}

int main(int argc, char *argv[])
{
	int n, cas;
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d",&n);
		s[0] = 0;
		int flag = 0;
		for( int i = 1; i <= n; i++ )
		{
			scanf("%d",&w[i]);
			if( !w[i] )flag = 1;
			s[i] = s[i-1] + w[i];
		}
		for( int i = 0; i <= n; i++ )
			for( int j = 0; j <= s[n]; j++ )
				dp[i][j] = -100000;
		dp[0][0] = 0;
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 0; j <= s[i]; j++ )
			{
				if( j <= w[i] )
					dp[i][j] = max( dp[i-1][j], dp[i-1][w[i]-j]+w[i]-j,
						dp[i-1][j+w[i]]+w[i] );
				else            
					dp[i][j] = max( dp[i-1][j], dp[i-1][j-w[i]], 
						dp[i-1][j+w[i]]+w[i] );
			}
		}
		printf("Case %d: ",t);
		if( dp[n][0] > 0 || flag )
			printf("%d\n",dp[n][0]);
		else printf("-1\n");
	}
	return 0;
}
