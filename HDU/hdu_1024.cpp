#include<iostream>
using namespace std;
const int maxn = 100004;
const int INF = -2000000001;

int dp[maxn];   // dp[i] 是前i个数据，必须包括 a[i] 最优子段和
int best[maxn]; // best[i] 前i个数据 最优子段和
int a[maxn], sum[maxn];
int max( int a, int b ){ return ( a > b ? a : b ); }
int main( )
{
	int i, j, m, n;
	while( scanf("%d%d",&m,&n) != EOF )
	{
		sum[0] = 0; 
		for( i = 1; i <= n; i++ )
		{
			scanf("%d",&a[i]);
			sum[i] = sum[i-1] + a[i];
			best[i] = INF;
		}	 
		for( i = 1; i <= m; i++ )
		{
			dp[i] = sum[i];
			best[i] = sum[i];
			//best[i] = max( dp[i], best[i-1] );
			for( j = i + 1; j <= n; j++ )
			{
				dp[j] = max( dp[j-1], best[j-1] ) + a[j];
				best[j] = max( dp[j], best[j-1] );
			}
		}
		printf("%d\n",best[n]);
	}
	return 0;
}


//#include<cstdio>
//#include<algorithm>
//#define MAX 1000003
//#define MIN -2000000000
//using namespace std;
//int f[MAX],best[2][MAX],a[MAX],sum[MAX];
//int main()
//{
//	int n,m;
//	int i,j,cur,max_value;
//	while(scanf("%d%d",&m,&n)!=EOF)
//	{
//		sum[0]=best[0][0]=0;
//		for(i=1;i<=n;i++)
//		{
//			scanf("%d",&a[i]);
//			sum[i]=sum[i-1]+a[i];
//			best[0][i]=0;
//		}
//		cur=0;
//		for(i=1;i<=m;i++)
//		{
//			for(j=0;j<i;j++)
//				best[1-cur][j]=MIN;
//			f[j]=sum[j];
//			best[1-cur][j]=max(f[j],best[1-cur][j-1]);
//			for(j++;j<=n;j++)
//			{
//				f[j]=max(f[j-1],best[cur][j-1])+a[j];
//				best[1-cur][j]=max(f[j],best[1-cur][j-1]);
//			}
//			cur=1-cur;
//		}
//		max_value=MIN;
//		printf("%d\n",best[cur][n]);
//	}
//	return 0;
//}


//
//#include<stdio.h>
//#include<stdlib.h>
//#define MIN_SUM 0x80000000
//int max_sum( int e[], int n, int m )
//{
//	int *curr_best;
//	int *prev_best;
//	int max_sum, i, j;
//	curr_best = (int*)malloc(sizeof(int) * (n + 1));
//	prev_best = (int*)calloc(n + 1, sizeof(int));
//	*curr_best = 0;
//	e--;
//	for(i = 1; i <= m; ++i)
//	{
//		max_sum = MIN_SUM;
//		for(j = i; j <= n; ++j)
//		{
//			if(curr_best[j - 1] < prev_best[j - 1])
//				curr_best[j] = prev_best[j - 1] + e[j];
//			else
//				curr_best[j] = curr_best[j - 1] + e[j];
//			prev_best[j - 1] = max_sum;
//			if(max_sum < curr_best[j])
//				max_sum = curr_best[j];
//		}
//		prev_best[j - 1] = max_sum;
//	}
//	free(prev_best);
//	free(curr_best);
//	return max_sum;
//}
//int main()
//{
//	int n, m, i, *data;
//	while(scanf("%d%d", &m, &n) == 2 && n > 0 && m > 0)
//	{
//		data = (int*)malloc(sizeof(int) * n);
//		for(i = 0; i < n; ++i)
//			scanf("%d", &data[i]);
//		printf("%d\n", max_sum(data, n, m));
//		free(data);
//	}
//	return 0;
//}