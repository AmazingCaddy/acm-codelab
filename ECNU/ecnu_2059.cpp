#include<iostream>
#include<queue>
#define MAXN 102
using namespace std;
struct node
{
	int x,y;
};
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n,m;

int BFS( int i, int j )
{
	int sum,x,y,nx,ny;
	queue<node> que;
	node temp;
	temp.x=i,temp.y=j;
	que.push(temp);
	vis[i][j]=true;
	sum=1;
	while( !que.empty( ) )
	{
		temp=que.front( );
		que.pop( );
		x=temp.x,y=temp.y;
		for( i=0; i<4; i++ )
		{
			nx=x+dir[i][0],ny=y+dir[i][1];
			if( nx>0 && nx<=n && ny>0 && ny<=m && !vis[nx][ny] )
			{
				if( map[nx][ny] )
				{
					temp.x=nx,temp.y=ny;
					vis[nx][ny]=true;
					que.push(temp);
					sum++;
				}
			}
		}
	}
	return sum;
}

int main( )
{
	int i,j,x,y,k,ans,max;
	scanf("%d%d%d",&n,&m,&k);
	memset( map, 0, sizeof(map) );
	for( i=0; i<k; i++ )
	{
		scanf("%d%d",&x,&y);
		map[x][y]=1;
	}
	max=0;
	memset( vis, false, sizeof(vis) );
	for( i=1; i<=n; i++ )
	{
		for( j=1; j<=m; j++ )
		{
			if( !vis[i][j] && map[i][j] )
			{
				ans=BFS( i, j );
				if( max<ans )max=ans;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}