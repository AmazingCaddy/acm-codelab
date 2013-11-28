#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct NODE
{
	int v;
	int val;
	NODE *next;
}T[10000];

const int maxn = 1003;
const int inf = 2000000000;
NODE * adj[maxn];
int len;
int vis[maxn];

int minn( int a, int b ) { return ( a < b ? a : b ); }

void init( )
{
	len = 0;
	for( int i = 0; i < maxn; i++ )
		adj[i] = NULL;
}

NODE * NewNode( )
{
	len++;
	T[len].v = 0;
	T[len].next = NULL;
	return & T[len];
}

void add_edge( int u, NODE * a )
{
	a -> next = adj[u];
	adj[u] = a;
}

int DFS( int u, int v  ) // u -> v
{
	int Ret = 0, t ;
	NODE *p = adj[v];
	int f = 0 ;
	while( p )
	{
		if( u != p -> v )
		{
			f = 1; 
			t = DFS( v, p -> v );
			Ret += minn( p -> val, t );
		}
		p = p -> next;
	}
	if( !f ) Ret = inf ;
	return Ret;
}

int main(int argc, char *argv[])
{
	int m, root, u, v, val, ans;
	NODE *p;
	while( scanf("%d%d",&m,&root) && ( m + root ) )
	{
		init( );
		for( int i = 1; i < m; i++ )
		{
			scanf("%d%d%d",&u,&v,&val);
			p = NewNode( );
			p -> val = val;
			p -> v = v;
			add_edge( u, p );
			p = NewNode( );
			p -> val = val;
			p -> v = u;
			add_edge( v, p );
		}
		ans = DFS( -1, root );
		if( m == 1 ) ans = 0;
		printf("%d\n",ans);
	}
	return 0;
}
