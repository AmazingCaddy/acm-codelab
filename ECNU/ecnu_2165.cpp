#include<iostream>
#define MAXN 505
#define INF 1000000000
using namespace std;
int g[MAXN][MAXN],md[MAXN][MAXN];
int dis[MAXN],pre[MAXN];
bool vis[MAXN],mark[MAXN][MAXN];
int n,m;
int max( int a, int b )
{
	return ( a > b ? a : b );
}
int min( int a, int b )
{
	return ( a > b ? b : a );
}

void prim( )
{
	int i,j,p,Min,res1,res2;
	for( i=1; i<=n; i++ )
	{
		dis[i]=g[1][i],vis[i]=false,pre[i]=1;
		for( j=i; j<=n; j++ )
			mark[i][j]=mark[j][i]=false,md[i][j]=md[j][i]=0;
	}
	vis[1]=true;
	res1=0;
	for( i=1; i<n; i++ )
	{
		Min=INF,p=-1;
		for( j=1; j<=n; j++ )
			if( !vis[j] && dis[j]<Min )
				Min=dis[j],p=j;
		if( p==-1 )
		{
			res1=-1;
			break;
		}
		mark[p][pre[p]]=mark[pre[p]][p]=true;
		md[p][pre[p]]=md[pre[p]][p]=Min;
		res1+=Min;
		for( j=1; j<=n; j++ )
		{
			if( dis[j]>g[p][j] )
				dis[j]=g[p][j],pre[j]=p;
			if( vis[j] )
				//md[p][j]=md[j][p]=max( md[p][pre[p]], md[j][pre[p]] );
			  md[p][j]=md[j][p]=max( g[p][pre[p]], md[j][pre[p]] );
		}
		vis[p]=true;
	}
	res2=INF;
	if( res1 != -1 )
		for( i=1; i<=n; i++ )
			for( j=i+1; j<=n; j++ )
				if( !( dis[j]==INF || mark[i][j] ) )
					res2=min( res2, res1+g[i][j]-md[i][j] );
	if( res2==INF ) res2=-1;
	printf("%d %d\n",res1, res2);
}

int main( )
{
	int u,v,l;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		int i,j;
		for( i=1; i<=n; i++ )
			for( j=i; j<=n; j++ )
				g[i][j]=g[j][i]=INF;	
		for( i=0; i<m; i++ )
		{
			scanf("%d%d%d",&u,&v,&l);
			g[u][v]=g[v][u]=min( g[u][v], l );
		}
		prim( );
	}
}