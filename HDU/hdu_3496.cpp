#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1003;

int dp[103][maxn];
struct node {
	int val, t;
}a[103];

int main(int argc, char *argv[]) {
	int n, m, l, t;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d%d",&n,&m,&l);
		for( int i = 1; i <= n; i++ )
			scanf("%d%d",&a[i].t,&a[i].val);
		memset( dp, -1, sizeof( dp ) );
		//memset( dp1, 0, sizeof( dp1 ) );
		dp[0][0] = 0;

		for( int i = 1; i <= n; i++ ) {
			for( int j = l; j >= a[i].t; j-- ) {
				for( int k = 1; k <= m; k++ ) {
					if( dp[k-1][j-a[i].t] != -1 )
						dp[k][j] = max( dp[k-1][j-a[i].t] + a[i].val, dp[k][j] );
				}
			}
		}
		int ans = -1;
		for( int i = 0; i <= l; i++ )
			if( dp[m][i] > ans ) ans = dp[m][i];
		if( ans == -1 ) ans = 0;
		printf("%d\n",ans);
	}
	return 0;
}
