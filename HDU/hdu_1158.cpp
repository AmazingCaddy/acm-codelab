#include<iostream>
using namespace std;
const int maxn = 10003;
const int INF = 2000000000;
int m[13];
int dp[13][maxn];

int main( )
{
	int i, j, k, n, hire, salary, fire, maxm, cost, t;
	while( scanf("%d",&n) && n )
	{
		scanf("%d%d%d",&hire,&salary,&fire);
		for( i = 1; i <= n; i++ )
			scanf("%d",&m[i]);
		for( maxm = 0, i = 1; i <= n; i++ )
			if( m[i] > maxm ) maxm = m[i];
		for( i = m[1]; i <= maxm; i++ )
			dp[1][i] = i * ( salary + hire );
		for( i = 2; i <= n; i++ )
		{
			for( j = m[i]; j <= maxm; j++ )
			{
				for( t = INF, k = m[i-1]; k <= maxm; k++ )
				{
					if( j < k )	cost = ( k - j ) * fire + j * salary;
					else if( j == k ) cost = j * salary;
					else cost = ( j - k ) * hire + j * salary;
					if( t > cost + dp[i-1][k] ) t = cost + dp[i-1][k];
				}
				dp[i][j] = t;
			}
		}
		for( t = INF, i = m[n]; i <= maxm; i++ )
			if( t > dp[n][i] ) t = dp[n][i];
		printf("%d\n",t);
	}
	return 0;
}