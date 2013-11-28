#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 400;
int dp[maxn][maxn], t[maxn][maxn];
int max( int a, int b ){ return ( a > b ? a : b ); }

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= i; j++ )
			scanf("%d",&t[i][j]);
	memset( dp, 0, sizeof( dp ) );
	dp[1][1] = t[1][1];
	for( int i = 2; i <= n; i++ )
		for( int j = 1; j <= i; j++ )
			dp[i][j] = max( dp[i-1][j-1], dp[i-1][j] ) + t[i][j];
	int ans = 0;
	for( int j = 1; j <=n; j++ )
		ans = max( ans, dp[n][j] );
	printf("%d\n",ans);
	return 0;
}
