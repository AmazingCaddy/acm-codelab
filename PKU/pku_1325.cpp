// poj 1325 Machine Schedule
// 最小点覆盖 转换次数=最小点覆盖-1

#include<iostream>
#define MAXN 102
using namespace std;
bool map[MAXN][MAXN],vis[MAXN];
int match[MAXN];
int n,m,k;

bool DFS( int from )
{
	int i;
	for( i=1; i<m; i++ )
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

int Hungray( )
{
	int i,sum;
	memset( match, -1, sizeof(match) );
	sum=0;
	for( i=1; i<n; i++ )
	{
		memset( vis, false, sizeof(vis) );
		if( DFS( i ) )
			sum++;
	}
	return sum;
}

int main( )
{
	int num,x,y,i;
	while( scanf("%d",&n) && n )
	{
		scanf("%d%d",&m,&k);
		memset( map, false, sizeof(map) );
		for( i=0; i<k; i++ )
		{
			scanf("%d%d%d",&num,&x,&y);
				map[x][y]=true;
		}
		printf("%d\n",Hungray( ));
	}
	return 0;
}