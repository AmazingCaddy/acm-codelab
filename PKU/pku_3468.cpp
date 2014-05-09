#include<iostream>
#define MAXN 100005
using namespace std;
struct node
{
	int l,r;
	__int64 total;//记录整个区间的改变量
	__int64 val;  //记录区间及子区间的该变量
	__int64 sum;  //记录区间的初始量
}tree[MAXN*4];
int a[MAXN];

void make_tree( int l, int r, int v )
{
	int mid=(l+r)>>1;
	tree[v].l=l,tree[v].r=r,tree[v].total=tree[v].val=0;
	if( l!=r )
	{
		make_tree( l, mid, v<<1 );
		make_tree( mid+1, r, (v<<1)+1 );
		tree[v].sum=tree[v<<1].sum+tree[(v<<1)+1].sum;
	}
	else tree[v].sum=a[l];
}

void update( int l, int r, int val, int v )
{
	int mid=(tree[v].l+tree[v].r)>>1;
	tree[v].total+=val*(r-l+1);
	if( l==tree[v].l && r==tree[v].r )
	{
		tree[v].val+=val;
		return ;
	}
	if( r<=mid ) update( l, r, val, v<<1 );
	else if( l>mid ) update( l, r, val, (v<<1)+1 );
	else 
	{
		update( l, mid, val, v<<1 );
		update( mid+1, r, val, (v<<1)+1 );
	}
}

__int64 total( int l, int r, int v )
{
	__int64 sum=0;
	int mid=(tree[v].l+tree[v].r)>>1;
	if( tree[v].l==l && tree[v].r==r )
		sum+=tree[v].total+tree[v].sum;
	else 
	{
		sum+=tree[v].val*(r-l+1);
		if( r<=mid ) sum+=total( l, r, v<<1 );
		else if( l>mid ) sum+=total( l, r, (v<<1)+1 );
		else 
		{
			sum+=total( l, mid, v<<1 );
			sum+=total( mid+1, r, (v<<1)+1 );
		}
	}
	return sum;
}

int main( )
{
	int n,q,i,x,y,val;
	char ch;
	while( scanf("%d%d",&n,&q) != EOF )
	{
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		make_tree( 0, n-1, 1 );
		getchar( );
		for( i=0; i<q; i++ )
		{
			scanf("%c",&ch);
			if( ch=='Q' )
			{
				scanf("%d%d",&x,&y);
				printf("%I64d\n",total( x-1, y-1, 1 ));
			}
			if( ch=='C' )
			{
				scanf("%d%d%d",&x,&y,&val);
				update( x-1, y-1, val, 1 );
			}
			getchar( );
		}
	}
	return 0;
}