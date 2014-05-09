// poj 3041 Asteroids
// 二分图最大匹配=最小点覆盖

#include<iostream>
#define MAXN 505
using namespace std;
bool map[MAXN][MAXN],vis[MAXN];
int match[MAXN];       //记录Y集合匹配的点
int n,k;

bool DFS( int from )  //若为n×m的矩阵，那么下面n全部改为m
{
	int i;
	for( i=1; i<=n; i++ )
	{
		if( map[from][i] && !vis[i] )
		{
			vis[i]=true;
			if( match[i]==-1 || DFS(match[i]) )
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
		if( DFS(i) )
			sum++;
	}
	return sum;
}

int main( )
{
	int i,x,y;
	while( scanf("%d%d",&n,&k) != EOF )
	{
		memset( map, false, sizeof(map) );
		for( i=0; i<k; i++ )
		{
			scanf("%d%d",&x,&y);
			map[x][y]=true;
		}
		printf("%d\n",find_match( ));
	}
	return 0;
}