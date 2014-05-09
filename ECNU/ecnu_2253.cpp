#include<iostream>
using namespace std;
#define MAXN 30
int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};//八个方向
bool visit[MAXN][MAXN];
int x[MAXN],y[MAXN];     //分别记录x轴和y轴坐标
int m,n;

bool dfs( int p, int q, int step )
{
	int i,newx,newy;
	if( step == m*n )  return true;
	for( i=0; i<8; i++ )
	{
		newy=p+dir[i][0];newx=q+dir[i][1];    
		//y轴和x轴坐标,注意搜索的顺序，因为多个路径时
		//是输出按照字典序排的路径，按照A,B...Z的顺序搜索
		if( !visit[newy][newx] && newy>=0 && newy<m && newx>=0 && newx<n )
		{
			visit[newy][newx]=true;                    //标记为已经访问过
			y[step]=newy;x[step]=newx;                 //记录路径坐标
			if( dfs( newy, newx, step+1 ) )
				return true;
			visit[newy][newx]=false;
			//如果没有找到，标记为没有访问过，通过别的路径能够再次访问
		}
	}
	return false;
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	for( i=1; i<=t; i++ )
	{
		if( i!=1 ) printf("\n");
		scanf("%d%d",&m,&n);
		printf("Scenario #%d:\n",i);
		memset(visit,false,sizeof(visit));
		x[0]=0;y[0]=0;
		visit[0][0]=true;
		if( !dfs( 0, 0, 1 ) )         //随便取一点开始搜索，一般取[0,0]
			printf("impossible");   //没有找到
		else 
			for( j=0; j<m*n; j++ )
				printf("%c%c",x[j]+'A',y[j]+'1');
		printf("\n");
	}
	return 0;
}