#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1000020;
const int inf = 1000000;
struct node
{
	int t, mark;
}tree[maxn*3];

int max( int a, int b ) { return a > b ? a : b; }
void make_tree( int v, int l, int r )
{
	int mid = ( l + r ) >> 1;
	tree[v].mark = 0;
	tree[v].t = 0;
	if( l != r )
	{
		make_tree( v<<1, l, mid );
		make_tree( v<<1|1, mid + 1, r );
	}
}

void push_down( int v, int l, int r )
{
	int tt = tree[v].mark;
	tree[v].mark = 0;
	if( l == r ) return;
	tree[v<<1].t += tt;
	tree[v<<1|1].t += tt;	
	tree[v<<1].mark += tt;
	tree[v<<1|1].mark += tt;	
}

void push_up( int v, int l, int r )
{
	if( l == r ) return;
	tree[v].t = max( tree[v<<1].t, tree[v<<1|1].t );
}

void update( int v, int l, int r, int s, int e, int val )
{
	push_down( v, l, r );
	if( l == s && r == e )
	{
		tree[v].t += val;
		tree[v].mark += val;
		return ;
	}
	int mid = ( l + r ) >> 1;
	if( e <= mid ) update( v<<1, l, mid, s, e, val );
	else if( s > mid ) update( v<<1|1, mid + 1, r, s, e, val );
	else
	{
		update( v<<1, l, mid, s, mid, val );
		update( v<<1|1, mid + 1, r, mid + 1, e, val );
	}
	push_up( v, l, r );
}

int query( int v, int l, int r, int s, int e )
{
	push_down( v, l, r );
	if( l == s && r == e )
	{
		push_up( v, l, r );
		return tree[v].t;
	}
	int mid = ( l + r ) >> 1;
	int l1 = 0, l2 = 0;
	if( e <= mid ) l1 = query( v<<1, l, mid, s, e );
	else if( s > mid ) l2 = query( v<<1|1, mid + 1, r, s, e );
	else
	{
		l1 = query( v<<1, l, mid, s, mid );
		l2 = query( v<<1|1, mid + 1, r, mid + 1, e );
	}
	push_up( v, l, r );
	return max( l1, l2 );
}


int main( )
{
	int k, n, cas, x, y;
	//freopen("F.in","r",stdin);
	//freopen("F.txt","w",stdout);
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d%d",&k,&n);
		make_tree( 1, 1, inf );
		printf("Case %d:\n",t);
		for( int i = 1; i <= n; i++ )
		{
			scanf("%d%d",&x,&y);
			y--;
			int p = query( 1, 1, inf, x, y );
			if( p < k )
			{
				printf("%d ",i);
				update( 1, 1, inf, x, y, 1 );
			}
		}
		printf("\n\n");
	}
	return 0;
}
