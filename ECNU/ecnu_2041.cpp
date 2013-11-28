#include<iostream>
#include<queue>
using namespace std;
//  个人觉得比较麻烦的BFS 
//  解题报告：题目大意是有些流星会达到地面，如果达到地面了包括自身和邻近4格再也不能走了
//  首先读取的时候如果有有流星那么保存最早的那颗
//  在状态转移时要判断转移目标周围四点的流星情况，并保存最早到的时间，如果比当前晚那么扩展
//  如果一颗也没有且目标点本身也不会有流星的干扰那么更新最小值，
//  注意如果一个点访问时间比当前小就不必访问了 
int map[401][401];
int a[401][401];
int n,m,sum,num;
struct Node
{
	int x,y,v;    
};
Node s,t;
queue<Node> q;
int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, -1, 0, 1 };
int small( int x, int y )
{
	return x<y?x:y;
}

bool check( int x, int y )
{
	if( x>=0 && x<=400 && y>=0 && y<=400 )return true;
	return false; 
}

void bfs( )
{
	int i,j,x,y,xx,yy,xxx,yyy,min;
	t.x=0,t.y=0,t.v=0;
	q.push( t );
	a[0][0]=0;
	sum=999999999;
	while( !q.empty( ) )
	{
		s=q.front( );
		q.pop( );
		x=s.x;  y=s.y;
		for( i=0; i<4; i++ )
		{
			xx=x+dx[i];     yy=y+dy[i];
			//    地图合法，    该地还可更新时间，  地图无炸弹或者炸弹来的时间比拜访的时间晚
			if( check(xx,yy) && a[xx][yy]>s.v+1 && ( map[xx][yy]==-1 || map[xx][yy]>s.v+1+1 ) )
			{ 
				min=999999999; 
				for( j=0; j<4; j++ ) //判断下一个点的四周是否会爆炸 
				{
					xxx=xx+dx[j];    yyy=yy+dy[j];
					if( check( xxx, yyy ) && map[xxx][yyy]!=-1 )
						min=small( min, map[xxx][yyy] );
				}
				if( s.v+1<min )  //min保存最小的爆炸时间，也可能不爆炸 
				{
					if( min==999999999 && map[xx][yy]==-1 )  //此处永远不会有炸弹, 为安全地带
					{
						if( sum>s.v+1 )//如果能有更快到达的时间，则更新之
							sum=s.v+1;
					}
					else
					{         
						t.x=xx;
						t.y=yy;
						t.v=s.v+1;
						a[xx][yy]=s.v+1;
						q.push(t);
					}
				}
			}
		}
	}
}

int main( )
{
	int i,j,x,y,z;
	scanf("%d",&n);
	for( i=0; i<=400; i++ )
	{
		for( j=0; j<=400; j++ )
		{
			a[i][j]=999999999;
			map[i][j]=-1;   //-1表示此处不会有炸弹炸到
		}               
	}
	for( i=0; i<n; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		if(map[x][y]==-1)map[x][y]=z;
		else if(map[x][y]>z)map[x][y]=z;//保存最早到的那个炸弹时间
	}      
	while( !q.empty( ) )q.pop( );
	bfs( );
	if( sum == 999999999 ) printf("-1\n");
	else printf("%d\n",sum);
	return 0;
}