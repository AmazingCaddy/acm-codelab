//  �о������ݲ�̫�����Զ���ö������߳������ȴ������Ŀ��Ը�ֵΪ����
//  ��ʾ���Կ����õ绰��˾��Ǯ�������ĸ�ֵΪ������Ȼ����ͨ������INF������󣩣���
//  Ȼ�������·��
//  �� dist[n] <= k ��ʾ���ڵ�ǰ���߷��������ڸó��ȵĲ�����k����
//  ����ȫ���ɵ绰��˾��Ǯ����С�ó��ȣ�
//  ���򣬱�ʾ�ó���̫С�ˣ���Ϊ���ȴ�Ķ���k��.�绰��˾������ô�࣬
//  ֻ�����ӳ��ȣ��Լ�����Ǯ�¡�


#include<iostream>
#include<algorithm>
#include<string>
#define MAXN 1005
#define M 10005
#define INF 1<<29
using namespace std;

int n,p,k;
int dist[MAXN],cost[MAXN][MAXN],mp[MAXN][MAXN];
int e[M],ee[M];
bool vis[MAXN];

bool dijkstra( int len )
{
	int min,i,j,u;
	for( i=1; i<=n; i++ )
	{
		for( j=1; j<=n; j++ )
		{
			if( cost[i][j]<INF )
				mp[i][j] = cost[i][j] > len ? 1 : 0;
			else mp[i][j]=INF;
		}
		vis[i]=false;
		dist[i]=INF;
	}
	dist[1]=0;
	for( i=1; i<=n; i++ )
	{
		min=INF;
		for( j=1; j<=n; j++ )
			if( !vis[j] && dist[j]<min )
				min=dist[j],u=j;
		if( u==n )break;
		vis[u]=true;
		for( j=1; j<=n; j++ )
			if( !vis[j] && dist[u]+mp[u][j] < dist[j] )
				dist[j]=dist[u]+mp[u][j];
	}
	return dist[n]<=k;
}

int main( )
{
	int i,j,cnt;
	int x,y,d,l,r,mid;
	while( scanf("%d%d%d",&n,&p,&k) != EOF )
	{
		for( i=1; i<=n; i++ )
			for( j=1; j<=n; j++ )
				cost[i][j]=INF;
		for( i=1; i<=p; i++ )
		{
			scanf("%d%d%d",&x,&y,&d);
			cost[x][y]=cost[y][x]=d;
			e[i]=d;
		}
		e[0]=0;
		sort( e, e+p+1 );
		cnt=1;
		for( i=1; i<=p; i++ )
			if( e[i]!=e[i-1] )
				ee[cnt++]=e[i];
		l=0;r=cnt-1;     //û�ж���Ļ������0���ʶ����һ��ȨֵΪ0�ıߣ���l��0��ʼ
		while( l<=r )
		{
			mid=(l+r)>>1;
			if( dijkstra(ee[mid]) ) r=mid-1;
			else l=mid+1;
		}
		if( dijkstra( ee[l] ) )printf("%d\n",ee[l]);
		else printf("-1\n");
	}
	return 0;
}