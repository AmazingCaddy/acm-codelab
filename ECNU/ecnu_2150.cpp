#include<iostream>
#include<queue>
#define MAXN 11
using namespace std;
struct NODE 
{
	int x,y,z,step;
};

bool visit[MAXN][MAXN][MAXN];
int d,t,x1,x2,y1,y2,z1,z2;
int dir[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

int bfs( )
{
	queue<NODE> que;
	NODE head,temp;
	int i,x,y,z,step,nx,ny,nz;
	head.x=x1;head.y=y1;head.z=z1;head.step=0;
	visit[x1][y1][z1]=true;
	que.push( head );
	while( !que.empty( ) )
	{
		temp=que.front( );
		que.pop( );
		x=temp.x;y=temp.y;z=temp.z;step=temp.step;
		for( i=0; i<6; i++ )
		{
			nx=x+dir[i][0];ny=y+dir[i][1];nz=z+dir[i][2];
			if( ( ( nx==0 || nx==d ) && ( ny<=d && ny>=0 && nz<=d && nz>=0 ) ||
				  ( ny==0 || ny==d ) && ( nx<=d && nx>=0 && nz<=d && nz>=0 ) ||
				  ( nz==0 || nz==d ) && ( nx<=d && nx>=0 && ny<=d && ny>=0 ) ) && 
				  !visit[nx][ny][nz] )
			{
				if( !( nx==x2 && ny==y2 && nz==z2 ) )
				{
					temp.x=nx;
					temp.y=ny;
					temp.z=nz;
					temp.step=step+1;
					que.push( temp );
					visit[nx][ny][nz]=true;
				}
				else return step+1;
			}
		}
	}
	return -1;
}

int main()
{
	int n,x,y,z;
	scanf("%d",&n);
	while( n-- )
	{
		memset( visit, false, sizeof(visit) );
		scanf("%d%d%d%d%d%d%d",&d,&x1,&y1,&z1,&x2,&y2,&z2);
		scanf("%d",&t);
		while( t-- )
		{
			scanf("%d%d%d",&x,&y,&z);
			visit[x][y][z]=true;
		}
		printf("%d\n",bfs( ));
	}
	return 0;
}	