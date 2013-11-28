#include<iostream>
using namespace std;
const int maxn = 100004;
int v[maxn][13];
int dp[2][13];
int max( int a, int b ){ return ( a > b ? a : b ); }
int max3( int a, int b, int c ){ return max( max( a, b ), c ); }

int main( )
{
	int n, i, j, d, t, tmax, tmin, ans;
	while( scanf("%d",&n) && n )
	{
		memset( v, 0, sizeof( v ) );
		memset( dp, 0, sizeof( dp ) );
		for( tmax = 0, tmin = maxn, i = 0; i < n; i++ )
		{
			scanf("%d%d",&d,&t);
			v[t][d]++;
			if( t > tmax ) tmax = t;
		}
		dp[1][4] = v[1][4];
		dp[1][5] = v[1][5];
		dp[1][6] = v[1][6];
		for( i = 1; i < tmax; i++ )
		{
			dp[(i+1)%2][0] = max( dp[i%2][0], dp[i%2][1] ) + v[i+1][0];
			dp[(i+1)%2][10] = max( dp[i%2][9], dp[i%2][10] ) + v[i+1][10];
			for( j = 1; j < 10; j++ )
				dp[(i+1)%2][j] = max3( dp[i%2][j-1], dp[i%2][j], dp[i%2][j+1] ) + v[i+1][j];
		}
		for( ans = 0, i = 0; i < 11; i++ )
			ans = max( dp[tmax%2][i], ans );
		printf("%d\n",ans);
	}
	return 0;
}
