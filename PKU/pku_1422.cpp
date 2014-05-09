// poj 1422 Air Raid
// P×P的有向图中，求最小的路径覆盖 ans=|P|-对应的无向图的最大匹配数

#include<iostream>
#define MAXN 125
using namespace std;
bool map[MAXN][MAXN],vis[MAXN];
int match[MAXN];
int n,k;
bool DFS( int from )
{
	int i;
	for( i=1; i<=n; i++ )
	{
		if( map[from][i] && !vis[i] )
		{
			vis[i]=true;
			if( match[i]==-1 || DFS( match[i] ) )
			{
				match[i]=from;
				return true;
			}
		}
	}
	return false;
}

int find_match( )
{
	int i,sum;
	memset( match, -1, sizeof(match) );
	sum=0;
	for( i=1; i<=n; i++ )
	{
		memset( vis, false, sizeof(vis) );
		if( DFS(i) )sum++;
	}
	return sum;
}

int main( )
{
	int ans,i,t,x,y;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&k);
		memset( map, false, sizeof(map) );
		for( i=0; i<k; i++ )
		{
			scanf("%d%d",&x,&y);
			map[x][y]=true;
		}
		ans=n-find_match( );
		printf("%d\n",ans);
	}
	return 0;
}