#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1000000 + 10;
int Q[maxn<<1], sum[maxn<<1];
char neck[maxn<<1];
int vis[2][maxn];

void solve( int n, int m, int v )
{
	sum[0] = 0;
	for( int i = 1; i < m; i++ )
		sum[i] = sum[i-1] + ( neck[i] == 'C' ? 1 : -1 );
	int head = 0, tail = 0;
	for( int i = 0; i < m; i++ )
	{
		while( head < tail && sum[Q[tail-1]] >= sum[i] ) tail--;
		Q[tail++] = i;
		if( i >= n )
		{
			while( i - Q[head] >= n ) head++;
			vis[v][i-n] = ( sum[i-n] <= sum[Q[head]] );
		}
	}
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	for( int p = 1; p <= t; p++ )
	{
		scanf("%s",neck+1);
		int n = strlen( neck + 1 );
		int m = n * 2 + 1;
		for( int i = 1; i <= n; i++ )
			neck[i+n] = neck[i];
		neck[m] = 0;
		memset( vis, 0, sizeof( vis ) );
		solve( n, m, 0 );
		reverse( neck + 1, neck + m );
		solve( n, m, 1 );
		int ans = 0;
		for( int i = 1; i <= n; i++ )
			if( vis[0][i] || vis[1][n-i] ) ans ++;
		printf("Case %d: %d\n",p,ans);
	}
	return 0;
}
