#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 100005;
int tree[maxn], pos[maxn];
int n;

int max( int a, int b ) { return ( a > b ? a : b ); }

int KthNum( int k )
{
	int ret = 0;
	for( int i = 17; i >= 0; i-- )
	{
		ret += ( 1 << i );
		if( ret > n || tree[ret] >= k )
			ret -= ( 1 << i );
		else k -= tree[ret];
	}
	return ret + 1;
}

void AddTree( int idx, int val )
{
	for( ; idx <= n; idx += idx & -idx )
		tree[idx] += val;
}

void AddMax( int idx, int val )
{
	for( ; idx <= n; idx += idx & -idx )
		tree[idx] = max( tree[idx], val );
}

// 获取 [ 1, idx ] 中的最大值
int GetMax( int idx )
{
	int ret = 0;
	for( ; idx > 0; idx -= idx & -idx )
		ret = max( tree[idx], ret );
	return ret;
}

int Sum( int idx )
{
	int ret = 0;
	for( ; idx > 0; idx -= idx & -idx )
		ret += tree[idx];
	return ret;
}

int main(int argc, char *argv[])
{
	int cas;
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d",&n);
		for( int i = 1; i <= n; i++ )
			scanf("%d",&pos[i]);

		memset( tree, 0, sizeof( tree ) );
		for( int i = 1; i <= n; i++ )
			AddTree( i, 1 );

		for( int i = n; i >= 1; i-- )
		{
			pos[i] = KthNum( pos[i] + 1 );
			AddTree( pos[i], -1 );
		}

		printf("Case #%d:\n",t);
		memset( tree, 0, sizeof( tree ) );
		int t, ret = 0;
		for( int i = 1; i <= n; i++ )
		{
			t = GetMax( pos[i] ) + 1;
			if( ret < t ) ret = t;
			AddMax( pos[i], t );
			printf("%d\n",ret);
		}
		printf("\n");
	}
	return 0;
}
