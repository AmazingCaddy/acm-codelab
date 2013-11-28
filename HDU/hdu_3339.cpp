#include<iostream>
#define MAXN 102
#define INF 100000000
using namespace std;
int map[MAXN][MAXN];
int val[MAXN],dis[MAXN],dp[MAXN*MAXN];
struct node
{
	int dis,pow;
};
node p[MAXN];
int maxn( int a, int b )
{
	return a>b?a:b;
}
int minn( int a, int b )
{
	return a>b?b:a;
}
void dijkstra( int n )
{
	bool vis[MAXN];
	int i,j,k,min;
	for( i=0; i<=n; i++ )
	{
		dis[i]=map[0][i];
		vis[i]=false;
	}
	vis[0]=true;
	for( i=1; i<=n; i++ )
	{
		k=0,min=INF;
		for( j=0; j<=n; j++ )
			if( !vis[j] && dis[j]<min )
				min=dis[j],k=j;
		if( k==0 )continue;
		vis[k]=true;
		for( j=0; j<=n; j++ )
			if( !vis[j] && dis[k]+map[k][j]<dis[j] )
				dis[j]=dis[k]+map[k][j];
	}
}
int main( )
{
	int t,n,m,x,y,oil,i,j,sum,min,P;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		for( i=0; i<=n; i++ )
		{
			map[i][i]=0;
			for( j=i+1; j<=n; j++ )
				map[i][j]=map[j][i]=INF;
		}
		for( i=0; i<m; i++ )
		{
			scanf("%d%d%d",&x,&y,&oil);
			map[x][y]=minn( oil, map[x][y] );
			map[y][x]=map[x][y];
		}
		dijkstra( n );
		P=0;
		for( i=1; i<=n; i++ )
		{
			scanf("%d",&p[i].pow);
			P+=p[i].pow;
			p[i].dis=dis[i];
		}
		for( i=0; i<=P; i++ )
			dp[i]=INF;
		dp[0]=0;
		for( i=1; i<=n; i++ )
			if( p[i].dis != INF )
				for( j=P; j>=p[i].pow; j-- )
					dp[j]=minn( dp[j-p[i].pow]+p[i].dis, dp[j] );
		min=INF;
		for( i=P/2+1; i<=P; i++ )
			if( dp[i] && dp[i]<min )
				min=dp[i];
		if( min==INF )printf("impossible\n");
		else printf("%d\n",min);
	}
	return 0;
}