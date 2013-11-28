#include<iostream>
#include<queue>
#define MAXN 1000000
using namespace std;
struct node 
{
	int x,y;
	int step,num;
};
bool vis[MAXN];
int map[6][6];
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int cnt;
void BFS( int i, int j )
{
	int x,y,nx,ny,step,num;
	queue<node> que;
	node temp;
	temp.x=i,temp.y=j,temp.step=1,temp.num=map[i][j];
	que.push(temp);
	while( !que.empty( ) )
	{
		temp=que.front( );
		que.pop( );
		x=temp.x,y=temp.y,step=temp.step,num=temp.num;
		if( step==6 )
		{
			if( !vis[num] )
				vis[num]=true,cnt++;
			continue;
		}
		for( i=0; i<4; i++ )
		{
			nx=dir[i][0]+x,ny=dir[i][1]+y;
			if( nx>=1 && nx<=5 && ny>=1 && ny<=5 )
			{
				temp.x=nx,temp.y=ny;
				temp.step=step+1;
				temp.num=num*10+map[nx][ny];
				que.push(temp);
			}
		}
	}
}

int main( )
{
	int i,j;
	for( i=1; i<=5; i++ )
		for( j=1; j<=5; j++ )
			scanf("%d",&map[i][j]);
	memset( vis, false, sizeof(vis) );
	cnt=0;
	for( i=1; i<=5; i++ )
		for( j=1; j<=5; j++ )
			BFS( i, j );
	printf("%d\n",cnt);
	return 0;
}