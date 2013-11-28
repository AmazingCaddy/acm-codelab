#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int x,y;
};
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char map[1001][81];
bool vis[1001][81];
int w,h;

int BFS( int i, int j )
{
	int x,y,nx,ny,sum;
	node temp;
	queue<node> que;
	temp.x=i,temp.y=j;
	que.push(temp);
	sum=1;
	vis[i][j]=true;
	while( !que.empty( ) )
	{
		temp=que.front( );
		que.pop( );
		x=temp.x,y=temp.y;
		for( i=0; i<4; i++ )
		{
			nx=dir[i][0]+x,ny=dir[i][1]+y;
			if( nx>=0 && nx<h && ny>=0 && ny<w && !vis[nx][ny] )
			{
				if( map[nx][ny]=='*' )
				{
					temp.x=nx,temp.y=ny;
					vis[nx][ny]=true;
					que.push( temp );
					sum++;
				}
			}
		}
	}
	return sum;
}

int main( )
{
	int i,j,ans,t;
	scanf("%d%d",&w,&h);
	for( i=0; i<h; i++ )
		scanf("%s",map[i]);
	memset( vis, false, sizeof(vis) );
	ans=0;
	for( i=0; i<h; i++ )
		for( j=0; j<w; j++ )
			if( map[i][j]=='*' && !vis[i][j] )
			{
				t=BFS( i, j );
				ans=( ans > t ? ans : t );
			}
	printf("%d\n",ans);
	return 0;
}