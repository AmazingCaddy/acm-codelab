#include<iostream>
#define MAXN 100005
using namespace std;
struct node
{
	int l,r;
};
node tree[MAXN*3];
int key[MAXN],sortseq[25][MAXN];
void make_tree( int v, int l, int r, int deep )
{
	int mid,i,j,k;
	tree[v].l=l,tree[v].r=r;
	if( l==r )
	{
		sortseq[deep][l]=key[l];
		return;
	}
	mid=(l+r)>>1;
	make_tree( v<<1, l, mid, deep+1 );
	make_tree( (v<<1)+1, mid+1, r, deep+1 );
	i=l,j=mid+1,k=l;
	while( i<=mid && j<=r )
	{
		if( sortseq[deep+1][i]<sortseq[deep+1][j] )
			sortseq[deep][k++]=sortseq[deep+1][i++];
		else sortseq[deep][k++]=sortseq[deep+1][j++];
	}
	if( i==mid+1 )
		while( j<=r )
			sortseq[deep][k++]=sortseq[deep+1][j++];
	else 
		while( i<=mid )
			sortseq[deep][k++]=sortseq[deep+1][i++];
}
int query( int v, int l, int r, int val,int deep )
{
	int x,y,mid,res;
	if( tree[v].l==l && tree[v].r==r )
	{
		if( val<=sortseq[deep][tree[v].l] )return 0;
		else if( val>sortseq[deep][tree[v].r] )return (r-l+1);
		else 
		{
			x=tree[v].l,y=tree[v].r;
			while( x<=y )
			{
				mid=(x+y)>>1;
				if( sortseq[deep][mid]<val )x=mid+1;
				else y=mid-1;
			}
			return x-tree[v].l;
		}
	}
	else 
	{
		res=0;
		mid=(tree[v].l+tree[v].r)>>1;
		if( r<=mid )res+=query( v<<1, l, r, val, deep+1 );
		else if( l>mid )res+=query( (v<<1)+1, l, r, val, deep+1 );
		else 
		{
			res+=query( v<<1, l, mid, val, deep+1 );
			res+=query( (v<<1)+1, mid+1, r, val, deep+1 );
		}
	}
	return res;
}
int main( )
{
	int i,n,m,l,r,k,x,y,mid,pos;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		for( i=1; i<=n; i++ )
			scanf("%d",&key[i]);
		make_tree( 1, 1, n, 1 );
		for( i=0; i<m; i++ )
		{
			scanf("%d%d%d",&l,&r,&k);
			x=1,y=n;
			k--;
			while( x<y )//这个二分为什么这么写，没有弄懂
			{
				mid=( x+y+1 )>>1;
				pos=query( 1, l, r, sortseq[1][mid], 1 );
				if( pos<=k )x=mid;
				else y=mid-1;
			}
			printf("%d\n",sortseq[1][x]);
		}
	}
	return 0;
}