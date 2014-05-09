// 记f[n][m]为n个disc，m个peg的Hanoi问题，
// 则有dp公式f[n][m]=min{f[n-k][m-1]+2*f[k][m]}。
// 即把上面的k个disc利用m个peg转移某个中间peg，
// 再把下面的n-k个disc利用m-1个peg转移到目标peg，
// 最后把上面的k个disc利用m个peg移到目标peg。
// dp过程记下使得f[n][m]最小的g[n][m]=k用于反向打印移动过程。
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 66;
const ll INF = 1000000000000000LL;

ll dp[ maxn ][ maxn ];
int path[ maxn ][ maxn ];
int top[ maxn ][ maxn ];
int has[ maxn ];
int n, m;
int vis[ maxn ];

void move( int a, int b )
{
	int x = top[ a ][ has[ a ] ];  // 从a柱子顶取出盘子 
	has[ a ]--;                    // has记录的是这根柱子的盘子的个数 
	if( has[ b ] == 0 ) printf("move %d from %d to %d\n",x,a,b);
	else printf("move %d from %d to %d atop %d\n",x,a,b,top[b][has[b]]);
	top[ b ][ ++has[ b ] ] = x;
}

// cnt 盘子数    dep 使用的柱子数
void dfs( int cnt, int a, int b, int dep )
{
	if( cnt == 0 ) return ;
	if( cnt == 1 ) { move( a, b ); return ; }
	int i;
	for( i = 1; i <= n; i++ )
		if( i != a && i != b && !vis[ i ] ) break;
	dfs( path[ cnt ][ dep ], a, i, dep );
	vis[ i ] = 1;
	dfs( cnt - path[ cnt ][ dep ], a, b, dep - 1 );
	vis[ i ] = 0;
	dfs( path[ cnt ][ dep ], i, b, dep );
}

int main(int argc, char *argv[])
{
	int cas;
	for( int i = 0; i < maxn; i++ )
		for( int j = 0; j < maxn; j++ )
			dp[ i ][ j ] = INF;
	for( int i = 0; i < maxn; i++ )
		dp[ 1 ][ i ] = 1;
	for( int i = 2; i < maxn; i++ )
	{
		for( int j = 3; j < maxn; j++ )
		{
			for( int k = 1; k < i; k++ )
			{
				if( dp[ i - k ][ j - 1 ] + 2 * dp[ k ][ j ] < dp[ i ][ j ] )
				{
					dp[ i ][ j ] = dp[ i - k ][ j - 1 ] + 2 * dp[ k ][ j ]; 
					path[ i ][ j ] = k;
				}
			}
		}
	}
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf("%d%d",&n,&m);
		printf("%lld\n",dp[n][m]);
		memset( vis, 0, sizeof( vis ) );
		for( int i = 2; i <= n; i++ ) has[ i ] = 0;
		has[ 1 ] = n;
		for( int i = 1; i <= n; i++ ) top[ 1 ][ i ] = n - i + 1;
		// for( int i = 1; i <= n; i++ ) top[ 1 ][ i ] = n - i + 1;
		dfs( n, 1, m, m );
	}
	return 0;
}
