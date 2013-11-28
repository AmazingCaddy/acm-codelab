// 3026 Borg Maze
// Time Limit: 1000MS		Memory Limit: 65536K
// Total Submissions: 2827		Accepted: 888

#include<iostream>
#include<queue>
#define MAXN 105
#define N 55
#define INF 10000000
using namespace std;
struct node
{
	int x,y;
	int step;
};
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char maze[N][N];
bool vis[N][N];
int g[MAXN][MAXN],v[N][N];
node d[MAXN];
int n,m,cnt;
void BFS( node a )
{
	int i,x,y,nx,ny,step;
	node p;
	queue<node> que;
	memset( vis, false, sizeof(vis) );
	que.push( a );
	vis[a.x][a.y]=true;
	while( !que.empty( ) )
	{
		p=que.front( );
		que.pop( );
		x=p.x,y=p.y,step=p.step+1;
		for( i=0; i<4; i++ )
		{
			nx=x+dir[i][0],ny=y+dir[i][1];
			if( nx<m && nx>=0 && ny<n && ny>=0 && !vis[nx][ny])
			{
				if( maze[nx][ny]=='S' || maze[nx][ny]=='A' )
				{
					g[v[a.x][a.y]][v[nx][ny]]=g[v[nx][ny]][v[a.x][a.y]]=step;
					p.x=nx,p.y=ny,p.step=step;
					que.push( p );
					vis[nx][ny]=true;
				}
				if( maze[nx][ny]==' ' )
				{
					p.x=nx,p.y=ny,p.step=step;
					que.push( p );
					vis[nx][ny]=true;
				}
			}
		}
	}
}

void create_graph( )
{
	int i,j;
	for( i=0; i<m; i++ )
		gets( maze[i] );
	cnt=0;
	for( i=0; i<m; i++ )
		for( j=0; j<n; j++ )
			if( maze[i][j]=='A' || maze[i][j]=='S' )
				d[cnt].x=i,d[cnt].y=j,d[cnt].step=0,v[i][j]=cnt++;
	for( i=0; i<cnt; i++ )
		for( g[i][i]=0, j=i+1; j<cnt; j++ )
			g[i][j]=g[j][i]=INF;
	for( i=0; i<cnt; i++ )
		BFS( d[i] );
}

int prim( )
{
	int i,j,k,min,ans;
	int dis[MAXN];
	for( i=0; i<cnt; i++ )
		dis[i]=g[0][i];
	ans=0;
	for( i=1; i<cnt; i++ )
	{
		min=INF,k=-1;
		for( j=0; j<cnt; j++ )
			if( dis[j] && dis[j]<min )
				min=dis[j],k=j;
		ans+=min;
		dis[k]=0;
		for( j=0; j<cnt; j++ )
			if( dis[j] && g[k][j]<dis[j] )
				dis[j]=g[k][j];
	}
	return ans;
}

int main( )
{
	int ans,t;
	char c[100];
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		gets( c );
		create_graph( );
		ans=prim( );
		printf("%d\n",ans);
	}
	return 0;
}