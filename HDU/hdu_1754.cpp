#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 200010;
struct node
{
	int l, r;
	int max, mark;
};
node tree[maxn<<2];
int a[maxn];
int max( int a, int b ) { return ( a > b ? a : b ); }

void make_tree( int l, int r, int v )
{
	tree[v].l = l, tree[v].r = r, tree[v].mark = 0;
	if( l != r )
	{
		int mid = ( l + r ) >> 1;
		make_tree( l, mid, v << 1 );
		make_tree( mid + 1, r, ( v << 1 ) + 1 );
		tree[v].max = max( tree[v<<1].max, tree[(v<<1)+1].max );
	}
	else tree[v].max = a[l];
}

void update( int l, int r, int v, int val )
{
	if( tree[v].l == l && tree[v].r == r )
	{
		tree[v].mark += val;
		tree[v].max += tree[v].mark;
		int tt = tree[v].mark;
		tree[v].mark = 0;
		if( tree[v].l == tree[v].r ) return;
		tree[v<<1].mark += tt;
		tree[(v<<1)+1].mark += tt;
		return ;
	}
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	if( r <= mid )
		update( l, r, v << 1, val );
	else if( l > mid )
		update( l, r, ( v << 1 ) + 1, val );
	else
	{
		update( l, mid, v << 1, val );
		update( mid + 1, r, ( v << 1 ) + 1, val );
	}
	tree[v].max = max( tree[v<<1].max, tree[(v<<1)+1].max );
}

int query( int l, int r, int v )
{
	if( tree[v].mark != 0 )
	{
		tree[v].max += tree[v].mark;
		int tt = tree[v].mark;
		tree[v].mark = 0;
		if( tree[v].l == tree[v].r ) return tree[v].max;
		tree[v<<1].mark += tt;
		tree[(v<<1)+1].mark += tt;
	}
	if( tree[v].l == l && tree[v].r == r ) return tree[v].max;
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	if( r <= mid )
		return query( l, r, v << 1 );
	else if( l > mid )
		return query( l, r, ( v << 1 ) + 1 );
	else
		return max( query( l, mid, v << 1 ), query( mid + 1, r, ( v << 1 ) + 1 ) );
}

int main(int argc, char *argv[])
{
	int n, m, l, r;
	char ch;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		make_tree( 0, n - 1, 1 );
		for( int i = 0; i < m; i++ )
		{
			scanf("\n%c %d %d",&ch,&l,&r);
			if( ch == 'Q' )
				printf("%d\n",query( l-1, r-1, 1 ));
			else
			{
				update( l-1, l-1, 1, r - a[l-1] );
				a[l-1] = r;
			}
		}
	}
	return 0;
}
