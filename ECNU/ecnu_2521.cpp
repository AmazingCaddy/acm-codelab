#include<iostream>
using namespace std;
#define maxn 50000
#define MAX 700
const int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool visit[MAX][MAX];
int man[MAX][MAX],n,m,count;
int que[maxn][2];

void floodfill(int y,int x)
{
	int head=0,tail=1;
	bool high=true;
	que[tail][0]=y;que[tail][1]=x;
	while(head!=tail)
	{
		head+=1;
		y=que[head][0];
		x=que[head][1];
		for(int i=0; i<8; i++)
		{
			int newy=y+dir[i][0];
			int newx=x+dir[i][1];
			if( newy>=0 && newx>=0 && newy<n && newx<m )
				if( man[newy][newx]>man[y][x] ) high=false;
				else if( man[newy][newx]==man[y][x] && visit[newy][newx]==false)
				{
					visit[newy][newx]=true;
					tail+=1;
					que[tail][0]=newy;
					que[tail][1]=newx;
				}
		}
	}
	if(high) count++;
}

int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&man[i][j]);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(man[i][j]>0 && visit[i][j]==false)floodfill(i,j);
	cout<<count<<endl;
	return 0;
}