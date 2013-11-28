#include <iostream>
using namespace std;
#define MAXN 205
#define MAX_VALUE -1
int capacity[MAXN][MAXN],res_capacity[MAXN][MAXN],min_capacity[MAXN];
int parent[MAXN],queue[MAXN];
int source,sink,first,last,n,m,max_flow;
bool visit[MAXN];

int minn( int a, int b )
{
	if ( a>b ) return b;
	else return a;
}

bool BFS( int source )
{
	int i;
	for( i=1; i<=sink; i++ )
	{
		visit[i]=false;
		min_capacity[i]=MAX_VALUE;
	}
	first=last=0;
	queue[last++]=source;
	visit[source]=true;

	while ( first!=last )
	{
		int v=queue[first++];
		for ( int u =1; u<=sink; u++ )
			if ( visit[u]==false && res_capacity[v][u]>0 ) //标记是否访问过，防止形成环图
			{
				if( min_capacity[v]==-1 )
					min_capacity[u]=res_capacity[v][u];
				else min_capacity[u]=minn(min_capacity[v],res_capacity[v][u]);
				parent[u]=v;    //记录u的父节点
				visit[u]=true;
				if ( u == sink ) return true;
				queue[last++]=u;
			}
	}
	return false;
}

void maxFlow( )
{
	int i,j;
	int max_flow;
	max_flow=0;
	for ( i=1; i<=sink; i++ )
		for( j=1; j<=sink; j++ )
			res_capacity[i][j]=capacity[i][j];  //初始化，开始时剩余流量就是总的容量

	while( BFS(source) )    //能够找到一条路径
	{
		max_flow+=min_capacity[sink];
		int v=sink,u;
		while ( v!=source )
		{
			u=parent[v];
			res_capacity[u][v]-=min_capacity[sink];
			res_capacity[v][u]+=min_capacity[sink];
			v=u;
		}
	}
	printf("%d\n",max_flow);
}

int main( )
{
	int i,x,y,z;

	memset(capacity,0,sizeof(capacity));

	scanf("%d%d",&n,&m);
	for( i=0; i<n; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		capacity[x][y]+=z;
	}
	source=1;sink=m;
	maxFlow( );
	return 0;
}