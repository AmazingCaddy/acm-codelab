Connections between cities

Description

After World War X, a lot of cities have been seriously damaged, and we need to rebuild those cities. However, some materials needed can only be produced in certain places. So we need to transport these materials from city to city. For most of roads had been totally destroyed during the war, there might be no path between two cities. And no circle exists in the given graph.
Now, your task comes. After giving you the condition of the roads, we want to know if there exists a path between any two cities. If the answer is yes, output the shortest path between them.
Input

Input consists of multiple problem instances.For each instance, first line contains three integers n, m and c, 2<=n<=10000, 0<=m<10000, 1<=c<=1000000. n represents the number of cities numbered from 1 to n. Following m lines, each line has three integers i, j and k, represent a road between city i and city j, with length k. Last c lines, two integers i, j each line, indicates a query of city i and city j.

Output

For each problem instance, one line for each query. If no path between two cities, output “Not connected”, otherwise output the length of the shortest path between them.

Hint

Huge input, scanf recommended.

Sample Input

5 3 2
1 3 2
2 4 3
5 2 3
1 4
4 5
 

Sample Output

Not connected
6

Source

多校联合比赛BNU站



#include<iostream>
#include<cmath>
#include<vector>
#define MAXN 10005
using namespace std;
vector<int> adj[MAXN];
int ST[MAXN*2][16];
int D[MAXN*2],E[MAXN*2],R[MAXN],dist[MAXN];
bool vis[MAXN];
int h[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
int cnt;
 
int minn( int x, int y )
{
	return D[x]>D[y]?y:x;
}
 
void Init( int n )
{
	int i;
	for( i=0; i<=n; i++ )
		adj[i].clear( );
}
 
void dfs( int v )
{
	int i;
	vis[v]=true;
	for( i=0; i<adj[v].size( ); i+=2 )
	{
		if( !vis[adj[v][i]] )
			dfs( adj[v][i] );
	}
}
 
void DFS( int v, int deep, int val )
{
	int i;
	cnt++;
	vis[v]=true;
	R[v]=cnt;
	E[cnt]=v;
	D[cnt]=deep;
	dist[v]=val;
	for( i=0; i<adj[v].size( ); i+=2 )
	{
		if( !vis[adj[v][i]] )
		{
			DFS( adj[v][i], deep+1, val+adj[v][i+1] );
			cnt++;
			D[cnt]=deep;
			E[cnt]=v;
		}
	}
}
 
void st( int n )
{
	int k=(int)(log(n*1.0)/log(2.0));
	int i,j;
	for( i=0; i<=n; i++ )
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
	int n,m,c,root;
	int i,u,v,z;
	//freopen("0.in","r",stdin);
	//freopen("2.out","w",stdout);
	while( scanf("%d%d%d",&n,&m,&c) != EOF )
	{
		for( i=0; i<m; i++ )
		{
			scanf("%d%d%d",&u,&v,&z);
			adj[u].push_back( v );
			adj[u].push_back( z );
			adj[v].push_back( u );
			adj[v].push_back( z );
		}
		memset( vis, false, sizeof(vis) );
		for( i=1; i<=n; i++ )
		{
			if( !vis[i] )
			{
				dfs( i );
				adj[0].push_back( i );
				adj[0].push_back( 0 );
			}
		}
		cnt=0;
		memset( vis, false, sizeof(vis) );
		DFS( 0, 0, 0 );
		st( 2*n+1 );
		for( i=0; i<c; i++ )
		{
			scanf("%d%d",&u,&v);
			if( R[u]>R[v] )root=LCA( R[v], R[u] );
			else root=LCA( R[u], R[v] );
			if( root==0 )printf("Not connected\n");
			else printf("%d\n",dist[u]+dist[v]-2*dist[root]);
		}
		Init( n );
	}
	return 0;
}