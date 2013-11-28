#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 100010;
vector<int> adj[maxn];
int n, m, s;
int f[maxn], r[maxn], dis[maxn];
void init_set( int n )
{
	int i;
	for( i = 0; i < n; i++ )
		f[i] = i, r[i] = 1;
}

int find_root( int p )
{
	if( f[p] != p )
		f[p] = find_root( f[p] );
	return f[p];
}

void union_set( int p, int q )
{
	int a, b;
	a = find_root( p );
	b = find_root( q );
	if( r[a] > r[b] )
		f[b] = a;
	else if( r[a] < r[b] ) 
		f[a] = b;
	else
		f[b] = a, r[a] ++;
}

int BIPARTITE( )/*在BFS的基础上稍作修改，从顶点编号0开始广搜,是二部图返回1,否则返回0*/
{
	int i, j;
	memset( dis, -1, sizeof( dis ) );/*初始化顶点未访问 */
	dis[0] = 0;
	queue<int> que;
	que.push( 0 );
	while( !que.empty( ) )
	{
		int x = que.front( );
		que.pop( );
		for( int i = 0; i < adj[x].size( ); i++ )
		{
			int y = adj[x][i];
			int d = abs( dis[x] - dis[y] );
			if( dis[y] != -1 && d % 2 == 0 )
				return 1;
			else if( dis[y] == -1 )
			{
				que.push( y );
				dis[y] = dis[x] + 1;
			}
		}
	}
	return 0;
}

int main( )
{
	int t, u, v;
	scanf("%d",&t);
	for( int p = 1; p <= t; p++ )
	{
		scanf("%d%d%d",&n,&m,&s);
		int sum = n;
		init_set( n );
		for( int i = 0; i < n; i++ )
			adj[i].clear( );
		for( int i = 0; i < m; i++ )
		{
			scanf("%d%d",&u,&v);
			if( find_root( u ) != find_root( v ) )
			{
				union_set( u, v );
				sum --;
			}
			adj[u].push_back( v );
			adj[v].push_back( u );
		}
		if( sum != 1 )
			printf("Case %d: NO\n",p);
		else
		{
			int cnt = BIPARTITE( );
			if( cnt == 0 ) printf("Case %d: NO\n",p);
			else printf("Case %d: YES\n",p);
		}
	}
	return 0;
}
