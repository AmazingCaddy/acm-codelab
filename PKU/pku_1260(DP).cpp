#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 103;
const int inf = 2000000000;
int dp[maxn], p[maxn], num[maxn];
int min( int a, int b ) { return ( a < b ? a : b ); }
int s[maxn];

// dp[i] = min{ dp[j] + ( num[j+1] + num[j+2] + ... + num[i] + 10 ) * p[i] ( 0 <= j < i ) } 

int main(int argc, char *argv[])
{
	int t, n, sum;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		s[0] = 0;
		for( int i = 1; i <= n; i++ )
		{
			scanf("%d%d",&num[i],&p[i]);
			s[i] = s[i-1] + num[i];
		}
		for( int i = 1; i <= n; i++ )
			dp[i] = inf;
		dp[0] = 0; 
		dp[1] = ( num[1] + 10 ) * p[1];
		for( int i = 2; i <= n; i++ )
		{
			for( int j = 0; j < i; j++ )
			{
				sum = dp[j] + ( s[i] - s[j] + 10 ) * p[i];
				dp[i] = min( dp[i], sum );
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
