#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100020;
int Left[20][maxn], sorted[maxn], tree[20][maxn];

void build_tree( int L, int R, int v )
{
	int mid = ( L + R ) >> 1;
	if( L == R ) return;
	int m = sorted[mid];
	int same = mid - L + 1;     // same表示和m = sorted[mid] 相等且分到左边的
	for( int i = L; i <= R; i++ )
		if( tree[v][i] < m ) same--;
	int lpos = L;
	int rpos = mid+1;
	int ss = 0;
	for( int i = L; i <= R; i++ )
	{
		if( i == L ) Left[v][i] = 0;
		else Left[v][i] = Left[v][i-1];
		if( tree[v][i] < m )
		{
			tree[v+1][lpos++] = tree[v][i];
			Left[v][i]++;
		}
		else if( tree[v][i] > m )
		{
			tree[v+1][rpos++] = tree[v][i];
		}
		else 
		{
			if( ss < same )
			{
				tree[v+1][lpos++] = tree[v][i];
				Left[v][i]++;
				ss++;
			}
			else tree[v+1][rpos++] = tree[v][i];
		}
	}
	build_tree( L, mid, v + 1 );
	build_tree( mid + 1, R, v + 1 );
}

int query( int L, int R, int l, int r, int k, int v )
{
	int mid = ( L + R ) >> 1;
	if( l == r ) return tree[v][l];
	int off;      // off表示 [ L, l-1 ]有多少个分到左边
	int cnt;      // cnt表示 [ l, r ]有多少个分到左边
	if( l == L )
	{
		off = 0;
		cnt = Left[v][r];
	}
	else
	{
		off = Left[v][l-1];
		cnt = Left[v][r] - Left[v][l-1];
	}
	if( cnt >= k ) //有多于k个分到左边,显然去左儿子区间找第k个
	{
		int lnew = L + off;
		int rnew = lnew + cnt - 1;
		return query( L, mid, lnew, rnew, k, v + 1 );
	}
	else 
	{
		off = l - L - off;      // off表示 [ L, l-1 ]有多少个分到右边
		k = k - cnt;
		cnt = r - l + 1 - cnt;  // cnt表示 [ l, r ]有多少个分到右边
		int lnew = mid + 1 + off;
		int rnew = lnew + cnt - 1;
		return query( mid + 1, R, lnew, rnew, k, v + 1 );
	}
}

int main(int argc, char *argv[])
{
	int t, n, m, l, r, k;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		for( int i = 1; i <= n; i++ )
		{
			scanf("%d",&tree[0][i]);
			sorted[i] = tree[0][i];
		}
		sort( sorted + 1, sorted + n + 1 );
		build_tree( 1, n, 0 );
		for( int i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",query( 1, n, l, r, k, 0 ) );
		}
	}
	return 0;
}
