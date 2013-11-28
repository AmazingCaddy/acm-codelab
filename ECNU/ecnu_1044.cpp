#include<iostream>
#include<queue>
#include<vector>
#define MAXN 100001
#define INF 99999999
using namespace std;
struct node
{
	int u;
	int d;
};
vector<node> adj[MAXN];
int dis[MAXN];
bool inque[MAXN];
queue<int> que;

void SPFA( int v, int n )
{
	int i,x,t;
	memset( inque, false, sizeof(inque) );
	for( i=0; i<n; i++ )
		dis[i]=INF;
	que.push( v );
	inque[v]=true;
	dis[v]=0;
	while( !que.empty( ) )
	{
		x=que.front( );
		que.pop( );
		inque[x]=false;
		for( i=0; i<adj[x].size( ); i++ )
		{
			if( dis[x]+adj[x][i].d<dis[t=(adj[x][i].u)] )
			{
				dis[t]=dis[x]+adj[x][i].d; 
				if( !inque[t] )
				{
					que.push( t );
					inque[t]=true;
				}
			}
		}
	}
}

int main( )
{
	int i,j,x,y,m,n,c1,c2;
	node t;
	while( scanf("%d",&n) != EOF )
	{
		for( i=0; i<n; i++ )
		{
			scanf("%d%d",&x,&m);
			for( j=0; j<m; j++ )
			{
				scanf("%d",&y);
				t.d=1,t.u=y;
				adj[x].push_back( t );
			}
		}
		scanf("%d%d",&c1,&c2);
		SPFA( c1, n );
		printf("%d %d %d\n",c1,c2,dis[c2]-1);
		for( i=0; i<n; i++ )
			adj[i].clear( );
	}
	return 0;
}