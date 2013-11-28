//  感觉是数据不太大，所以二分枚举这个边长。长度大于它的可以赋值为１，
//  表示可以考虑让电话公司付钱；其他的赋值为０，当然不连通的仍是INF（无穷大）；　
//  然后求最短路：
//  当 dist[n] <= k 表示对于当前布线方法，大于该长度的不超过k条，
//  可以全部由电话公司付钱，缩小该长度；
//  否则，表示该长度太小了，因为长度大的多于k条.电话公司不管这么多，
//  只能增加长度，自己多掏钱呗。


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
		l=0;r=cnt-1;     //没有额外的花费输出0，故额外加一条权值为0的边，故l从0开始
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