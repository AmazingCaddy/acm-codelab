#include<iostream>
#include<cmath>
#include<vector>
#define MAXN 10002
using namespace std;
int ST[MAXN*2][16];
int a[MAXN*2],D[MAXN*2],E[MAXN*2],R[MAXN],degree[MAXN];
int h[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
int cnt;
vector<int> edge[MAXN];

int minn( int x, int y )
{
	return D[x]>D[y]?y:x;
}

void Init( int n )
{
	int i;
	for( i=1; i<=n; i++ )
	{
		edge[i].clear( );
		degree[i]=0;
	}
}		

void insert( int u, int v )
{
	degree[v]++;
	edge[u].push_back(v);
}

void DFS( int v, int deep )
{
	cnt++;
	D[cnt]=deep;
	R[v]=cnt;
	E[cnt]=v;
	int size=edge[v].size( );
	for( int i=0; i<size; i++ )
	{
		DFS( edge[v][i], deep+1 );
		cnt++;
		D[cnt]=deep;
		E[cnt]=v;
	}
}

void st( int n )
{
	int k=(int)(log(n*1.0)/log(2.0));
	int i,j;
	for( i=1; i<=n; i++ )
		ST[i][0]=i;
	for( j=1; j<=k; j++ )
		for( i=1; i<=n-h[j]+1; i++ )
			ST[i][j]=minn( ST[i][j-1], ST[i+h[j-1]][j-1] );
}

int RMQ( int l, int r )
{
	int k=(int)(log((r-l+1)*1.0)/log(2.0));
	int t=minn( ST[l][k], ST[r-h[k]+1][k] );
	return t;
}

int LCA( int l, int r )
{
	return E[RMQ( l, r )];
}

int main( )
{
	int i,t,n,u,v,ans;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		Init( n );
		for( i=1; i<n; i++ )
		{	
			scanf("%d%d",&u,&v);
			insert( u, v );
		}
		for( i=1; i<=n; i++ )
			if( degree[i]==0 )
			{		
				u=i;
				break;
			}
		cnt=0;
		DFS( u, 0 );
		st( 2*n+2 );
		scanf("%d%d",&u,&v);
		if( R[u]<R[v] ) ans=LCA( R[u], R[v] );
		else ans=LCA( R[v], R[u] );
		printf("%d\n",ans);
	}
	return 0;
}
