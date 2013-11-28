#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef __int64 ll;
const int maxn = 100030;
ll sum[20][maxn];
int Left[20][maxn];
int sorted[maxn];
int tree[20][maxn];
ll total[maxn];

void make_tree( int L, int R, int v )
{
	if( L == R ) return;
	int mid = ( L + R ) >> 1, same = 0;
	for( int i = L; i <= R; i++ )
		if( tree[v][i] < sorted[mid] )same++;
	same = mid - L + 1 - same;
	int lcnt = L, rcnt = mid + 1, m = sorted[mid];
	for( int i = L; i <= R; i++ )
	{
		if( tree[v][i] < m )
		{
			tree[v+1][lcnt++] = tree[v][i];
			sum[v][i] = sum[v][i-1] + tree[v][i]; 
		}
		else if( tree[v][i] == m && same )
		{
			tree[v+1][lcnt++] = tree[v][i];
			sum[v][i] = sum[v][i-1] + tree[v][i];
			same--;
		}
		else
		{
			tree[v+1][rcnt++] = tree[v][i];
			sum[v][i] = sum[v][i-1];
		}
		// 这个写得漂亮
		Left[v][i] = Left[v][L-1] + lcnt - L;
	}
	make_tree( L, mid, v + 1 );
	make_tree( mid + 1, R, v + 1 );
}

ll query( int L, int R, int l, int r, int v, int k, ll & S )
{
	if( l == r ) return tree[v][l];
	int mid = ( L + R ) >> 1;
	int cnt = Left[v][r] - Left[v][l-1], off;
	if( cnt >= k )
	{
		off = Left[v][l-1] - Left[v][L-1];
		// 重新计算查找区间
		return query( L, mid, L + off, L + off + cnt - 1, v + 1, k, S );
	}
	else
	{
		S = S + sum[v][r] - sum[v][l-1];
		off = ( l - L ) - ( Left[v][l-1] - Left[v][L-1] );
		k = k - cnt;
		cnt = r - l + 1 - cnt;
		// 重新计算查找区间
		return query( mid + 1, R, mid + 1 + off, mid + off + cnt, v + 1, k, S );
	}
}

int main(int argc, char *argv[])
{
	int t, l, r, n, m;
	scanf("%d",&t);
	for( int p = 1; p <= t; p++ )
	{
		scanf("%d",&n);
		total[0] = 0;
		for( int i = 1; i <= n; i++ )
		{
			scanf("%d",&tree[0][i]);
			sorted[i] = tree[0][i];
			total[i] = total[i-1] + tree[0][i];
		}
		sort( sorted + 1, sorted + n + 1 );
		make_tree( 1, n, 0 );
		printf("Case #%d:\n",p);
		scanf("%d",&m);
		ll S, ans, mid; 
		for( int i = 0; i < m; i++ )
		{
			scanf("%d%d",&l,&r);
			S = 0;    // S 求得是 将区间[l,r]中的数排序之后，最小的数到中位数前一个数之和
			mid = query( 1, n, l + 1, r + 1, 0, ( r - l ) / 2 + 1, S );
			ans = ( r - l ) / 2 * mid - S;
			S = total[r+1] - total[l] - S - mid;
			ans += S - ( r - l + 1 ) / 2 * mid;
			printf("%I64d\n",ans);
		}
		printf("\n");
	}
	return 0;
}
