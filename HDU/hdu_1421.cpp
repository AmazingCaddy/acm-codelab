#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1003;
const int INF = 1000000000;
int dp[maxn<<1][maxn];
int a[maxn<<1];
int min( int a, int b ){ return ( a > b ? b : a ); }
int main( )
{
	int i, j, n, k;
	while( scanf("%d%d",&n,&k) != EOF )
	{
		for( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		sort( a+1, a+n+1 );
		for( i = 1; i < n; i++ )
			a[i] = ( a[i] - a[i+1] ) * ( a[i] - a[i+1] );
		for( i = 0; i <= n; i++ )
			for( j = 0; j <= k; j++ )
				dp[i][j] = INF;
		for( i = 0; i <= n; i++ )
			dp[i][0] = 0;
		for( i = 2; i <= n; i++ )
			for( j = 1; j * 2 <= i; j++ )
				dp[i][j] = min( dp[i-2][j-1] + a[i-1], dp[i-1][j] );
		        // ×´Ì¬×ªÒÆ·½³Ì
		printf("%d\n",dp[n][k]);
	}
	return 0;
}
