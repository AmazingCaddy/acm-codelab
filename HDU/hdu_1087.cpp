#include<iostream>
using namespace std;
const int maxn = 1003;

__int64 dp[maxn];
int a[maxn];

int main( )
{
	int i, j, n;
	__int64 max;
	while( scanf("%d",&n) && n )
	{
		memset( dp, 0, sizeof( dp ) );
		for( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		for( i = 0; i < n; i++ )
			for( dp[i] = a[i], j = 0; j < i; j++ )
				if( a[j] < a[i] && dp[j] + a[i] > dp[i] )
					dp[i] = dp[j] + a[i];
		for( max = -1, i = 0; i < n; i++ )
			if( dp[i] > max ) max = dp[i];
		printf("%I64d\n",max);
	}
	return 0;
}