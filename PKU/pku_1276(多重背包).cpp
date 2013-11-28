#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100004;
// 多重背包 加一个限制
int dp[maxn], num[maxn];
int val[12], cnt[12];

int main(int argc, char *argv[])
{
	int n, total;
	while( scanf("%d%d",&total,&n) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf("%d%d",&cnt[i],&val[i]);
		memset( dp, 0, sizeof( dp ) );
		dp[0] = 1;
		for( int i = 0; i < n; i++ )
		{
			memset( num, 0, sizeof( num ) );
			for( int j = val[i]; j <= total; j++ )
			{
				if( !dp[j] )
				{
					int k = j - val[i];
					if( dp[k] && num[k] < cnt[i] )
						dp[j] = 1, num[j] = num[k] + 1;
				}
			}
		}
		int i = total;
		while( !dp[i] ) i--;
		printf("%d\n",i);
	}
	return 0;
}
