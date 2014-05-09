//  dp[i][j]:第i分钟疲劳度为j时的最大路径值
//  转移方程：
//  dp[i][j] = dp[i-1][j-1] + distance[i] ( j > 0 )
//  dp[i][0] = max ( dp[i-1][0], dp[i-j][j]( i-j >= j && j <= M ) )
//  i-j>=j 因为第i-j分钟疲劳度为j，到第i分钟，疲劳度必须为0，
//  且因为选择休息，必须休息到疲劳度为0为止

#include<iostream>
const int SIZE_T = 10001;
const int SIZE_M = 501;
int dp[SIZE_T][SIZE_M];
int T, M, dist[SIZE_T];
using namespace std;
void Solve( )
{
	int i, j;
	for ( i = 0; i <= M; i++ )   //第0分钟，疲劳度为i的最大路径都为0
		dp[0][i] = 0;
	for ( i = 1; i <= T; i++ )
	{
		dp[i][0] = dp[i-1][0];
		for ( j = 1; i-j >= j && j <= M; j++ )
			dp[i][0] = ( dp[i][0] > dp[i-j][j] ? dp[i][0] : dp[i-j][j] );
		for ( j = 1; j <= M; j++ )
			dp[i][j] = dp[i-1][j-1] + dist[i]; 
	}
	printf("%d\n", dp[T][0]);
}

int main( )
{
	int i;
	scanf("%d %d", &T, &M );
	for ( i = 1; i <= T; i++ )
		scanf("%d", &dist[i]);
	Solve( );
	return 0;
}