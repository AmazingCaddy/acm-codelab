#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct node 
{
	int s,t;
	char op[3];
};
struct segment
{
	int l,r;
	int left,right; // 记录区间两端的高度
	int flag;       // 记录整段区间被下压的次数
	int count;      // 记录区间中处于高度0的条数
};

const int maxn = 21000;
node a[maxn];
segment tree[maxn<<3];
int lisan[maxn<<1]; 

void make_tree( int v, int l, int r )
{
	int mid;
	tree[v].l = l, tree[v].r = r;
	tree[v].flag = tree[v].left = tree[v].right = 0;
	tree[v].count = 1;
	if( l + 1 != r )
	{
		mid = ( l + r ) >> 1;
		make_tree( v<<1, l, mid );
		make_tree( ( v<<1 ) + 1, mid, r );
	}
}

void update( int v, int s, int t, int c )
{
	int mid;
	if( lisan[tree[v].l] == s && lisan[tree[v].r] == t )
	{
		tree[v].flag += c;
		tree[v].left += c;
		tree[v].right += c;
		if( tree[v].flag )    // 如果区间高度不是0，说明被下压，没有0线段
			tree[v].count = 0; 
		else                  // 叶子节点 
			if( tree[v].l + 1 == tree[v].r ) 
				tree[v].count = 1;
			else                  // 一般节点
				tree[v].count = tree[v<<1].count + tree[(v<<1)+1].count -
				( tree[v<<1].right == 0 && tree[(v<<1)+1].left == 0 );
		return ;
	}
	mid = ( tree[v].l + tree[v].r ) >> 1;
	if( lisan[mid] >= t ) update( v<<1, s, t, c );
	else if( lisan[mid] <= s ) update( (v<<1)+1, s, t, c );
	else 
	{
		update( v<<1, s, lisan[mid], c );
		update( (v<<1)+1, lisan[mid], t, c );
	}
	tree[v].left = tree[v<<1].left + tree[v].flag;
	tree[v].right = tree[(v<<1)+1].right + tree[v].flag;
	if( tree[v].flag ) tree[v].count = 0;
	else 
		tree[v].count = tree[v<<1].count + tree[(v<<1)+1].count -
		( tree[v<<1].right == 0 && tree[(v<<1)+1].left == 0 );
}

void init( int n, int m )
{
	int i,len=0;
	lisan[len++] = 0;
	lisan[len++] = n;
	for( i = 0; i < m; i++ )
	{
		scanf("%s%d%d",a[i].op,&a[i].s,&a[i].t);
		a[i].t++;
		lisan[len++] = a[i].s;
		lisan[len++] = a[i].t;
	}
	sort( lisan, lisan + len );
	len = unique( lisan, lisan + len ) - lisan;
	make_tree( 1, 0, len-1 );
}

int main( )
{
	int i,t,n,m,k = 1;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		init( n, m );
		printf("Case #%d:\n",k++);
		for( i = 0; i < m; i++ )
		{
			update( 1, a[i].s, a[i].t, ( a[i].op[0] == 'p' ? 1 : -1 ) );
			printf("%d\n",tree[1].count);
		}
	}
	return 0;
}
