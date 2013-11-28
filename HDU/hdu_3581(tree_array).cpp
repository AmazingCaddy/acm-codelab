#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxm = 505;
const int maxn = 100006;
int tree[maxm][maxm];
int n, m;

void update( int x, int y, int val )
{
	while( x <= m )
	{
		int tmp = y;
		while( tmp <= m )
		{
			tree[x][tmp] += val;
			tmp += ( tmp & -tmp );
		}
		x += ( x & -x );
	}
}

int query( int x, int y )
{
	int sum = 0;
	while( x > 0 )
	{
		int tmp = y;
		while( tmp > 0 )
		{
			sum += tree[x][tmp];
			tmp -= ( tmp & - tmp );
		}
		x -= ( x & - x );
	}
	return sum;
}

int seg[maxn][2];
int p[maxm];
int ans[maxm][maxm];

int main(int argc, char *argv[])
{
	int cas;
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d%d",&n,&m);
		for( int i = 0; i < n; i++ )
			scanf("%d%d",&seg[i][0],&seg[i][1]);
		for( int i = 0; i < m; i++ )
			scanf("%d",&p[i]);

		memset( tree, 0, sizeof( tree ) );
		int st, ed;
		for( int i = 0; i < n; i++ )
		{
			st = lower_bound( p, p + m, seg[i][0] ) - p + 1;
			ed = upper_bound( p, p + m, seg[i][1] ) - p;
			//printf("%d %d\n",st, ed);
			update( st, st, 1 );
			update( st, ed + 1, -1 );
			update( ed + 1, st, -1 );
			update( ed + 1, ed + 1, 1 );
		}
		
		for( int i = 1; i <= m; i++ )
		{
			ans[i][i] = query( i, i );
			for( int j = i + 1; j <= m; j++ )
				ans[i][j] = ans[j][i] = query( i, j );
		}
		printf("Case %d:\n",t);
		for( int i = 1; i <= m; i++ )
		{
			for( int j = 1; j <= m; j++ )
			{
				if( j != 1 )printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
