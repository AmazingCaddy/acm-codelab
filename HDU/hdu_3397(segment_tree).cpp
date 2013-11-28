#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100010;
struct node
{
	int l, r;
	int count0, max0, left0, right0;
	int count1, max1, left1, right1;
	int fill0, fill1, flag;
};
node tree[maxn<<2];
int a[maxn];
int max( int a, int b ) { return ( a > b ? a : b ); }
int min( int a, int b ) { return ( a < b ? a : b ); }

void update( int v )
{
	int ll = v << 1, rr = v << 1 | 1;
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	
	// update 0
	tree[v].count0 = tree[ll].count0 + tree[rr].count0;
	
	tree[v].max0 = max( tree[ll].max0, tree[rr].max0 );
	tree[v].max0 = max( tree[v]. max0, tree[ll].right0 + tree[rr].left0 );

	tree[v].left0 = tree[ll].left0;
	if( tree[v].left0 == mid - tree[v].l )
		tree[v].left0 += tree[rr].left0;

	tree[v].right0 = tree[rr].right0;
	if( tree[v].right0 == tree[v].r - mid )
		tree[v].right0 += tree[ll].right0;

	// update 1
	tree[v].count1 = tree[ll].count1 + tree[rr].count1;

	tree[v].max1 = max( tree[ll].max1, tree[rr].max1 );
	tree[v].max1 = max( tree[v]. max1, tree[ll].right1 + tree[rr].left1 );

	tree[v].left1 = tree[ll].left1;
	if( tree[v].left1 == mid - tree[v].l )
		tree[v].left1 += tree[rr].left1;

	tree[v].right1 = tree[rr].right1;
	if( tree[v].right1 == tree[v].r - mid )
		tree[v].right1 += tree[ll].right1;
}

void make_tree( int v, int l, int r )
{
	tree[v].l = l, tree[v].r = r;
	tree[v].fill0 = tree[v].fill1 = tree[v].flag = 0;
	if( l + 1 == r )
	{
		tree[v].count0 = tree[v].max0 = tree[v].left0 = tree[v].right0 = 0;
		tree[v].count1 = tree[v].max1 = tree[v].left1 = tree[v].right1 = 0;
		if( a[l] ) tree[v].count1 = tree[v].max1 = tree[v].left1 = tree[v].right1 = 1;
		else tree[v].count0 = tree[v].max0 = tree[v].left0 = tree[v].right0 = 1;
		return ;
	}
	int mid = ( l + r ) >> 1;
	make_tree( v<<1, l, mid );
	make_tree( v<<1|1, mid, r );
	update( v );
}

void fill0( int v )
{
	tree[v].max0 = tree[v].left0 = tree[v].right0 = tree[v].count0 = tree[v].r - tree[v].l;
	tree[v].max1 = tree[v].left1 = tree[v].right1 = tree[v].count1 = 0;
	tree[v].fill0 = 0;
	if( tree[v].r - tree[v].l == 1 ) return ;
	tree[v<<1].fill0 = tree[v<<1|1].fill0 = 1;
	tree[v<<1].fill1 = tree[v<<1|1].fill1 = 0;
	tree[v<<1].flag = tree[v<<1|1].flag = 0;
}

void fill1( int v )
{
	tree[v].max0 = tree[v].left0 = tree[v].right0 = tree[v].count0 = 0;
	tree[v].max1 = tree[v].left1 = tree[v].right1 = tree[v].count1 = tree[v].r - tree[v].l;
	tree[v].fill1 = 0;
	if( tree[v].r - tree[v].l == 1 ) return ;
	tree[v<<1].fill0 = tree[v<<1|1].fill0 = 0;
	tree[v<<1].fill1 = tree[v<<1|1].fill1 = 1;
	tree[v<<1].flag = tree[v<<1|1].flag = 0;
}

void change( int v )
{
	swap( tree[v].count1, tree[v].count0 );
	swap( tree[v].max1, tree[v].max0 );
	swap( tree[v].left1, tree[v].left0 );
	swap( tree[v].right1, tree[v].right0 );
	tree[v].flag = 0;
	if( tree[v].r - tree[v].l == 1 ) return ;
	tree[v<<1].flag ^= 1;
	tree[v<<1|1].flag ^= 1;
}

void down( int v )
{
	if( tree[v].fill0 ) fill0( v );
	if( tree[v].fill1 ) fill1( v );
	if( tree[v].flag ) change( v );
}

void opr( int v, int l, int r, int x )
{
	down( v );
	if( tree[v].l == l && tree[v].r == r )
	{
		if( x == 0 ) tree[v].fill0 = 1;
		else if( x == 1 ) tree[v].fill1 = 1;
		else tree[v].flag ^= 1;
		down( v );
		return ;
	}
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	if( r <= mid ) opr( v<<1, l, r, x );
	else if( l >= mid ) opr( v<<1|1, l, r, x );
	else
	{
		opr( v<<1, l, mid, x );
		opr( v<<1|1, mid, r, x );
	}
	down( v<<1 );
	down( v<<1|1 );
	update( v );
}

int onenum( int v, int l, int r )
{
	down( v );
	if( tree[v].l == l && tree[v].r == r )
		return tree[v].count1;
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	if( r <= mid ) return onenum( v<<1, l, r );
	else if( l >= mid ) return onenum( v<<1|1, l, r );
	else return onenum( v<<1, l, mid ) + onenum( v<<1|1, mid, r );
}

int maxonenum( int v, int l, int r )
{
	down( v );
	if( tree[v].l == l && tree[v].r == r )
		return tree[v].max1;
	int mid = ( tree[v].l + tree[v].r ) >> 1;
	if( r <= mid ) return maxonenum( v<<1, l, r );
	else if( l >= mid ) return maxonenum( v<<1|1, l, r );
	else
	{
		int m1, m2, res;
		m1 = maxonenum( v<<1, l, mid );
		m2 = maxonenum( v<<1|1, mid, r );
		res = min( tree[v<<1].right1, mid - l ) + min( tree[v<<1|1].left1, r - mid );
		return max( max( m1, m2 ), res );
	}
}

int main()
{
	int t, n, m, i, x, l, r;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		for( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		make_tree( 1, 0, n );
		for( i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&x,&l,&r);
			if( x <= 2 ) opr( 1, l, r + 1, x );
			else if( x == 3 ) printf("%d\n",onenum( 1, l, r + 1 ) );
			else printf("%d\n",maxonenum( 1, l, r + 1 ) );
		}
	}
	return 0;
}
