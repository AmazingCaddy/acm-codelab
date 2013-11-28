//#include<iostream>
//using namespace std;
//
//#define MAXN 32010
//int c[MAXN*4];
//
//void createtree ( )
//{
//	memset(c,0,sizeof(c));
//}
//int insert ( int b , int e , int l , int r , int v )
//{
//	if ( l>e || r<b )
//		return c[v];
//	if ( b>=l && e<=r )
//		return ++c[v];
//	int mid=(b+e)>>1;
//	int t1=insert(b,mid,l,r,2*v);
//	int t2=insert(mid+1,e,l,r,2*v+1);
//	return c[v]=t1+t2;
//}
//int query ( int b , int e, int l, int r , int v )
//{
//	if ( l>e || r<b )
//		return 0;
//	if ( b>=l && e<=r )
//		return c[v];
//	int mid=(b+e)>>1;
//	int t1=query(b,mid,l,r,2*v);
//	int t2=query(mid+1,e,l,r,2*v+1);
//	return t1+t2;
//}
//
//int main ( )
//{
//	int ti[15010],n,x,y;
//	while ( scanf("%d",&n)!=EOF )
//	{
//		memset(ti,0,sizeof(ti));
//		createtree();
//		for ( int i=0 ; i<n ; i++ )
//		{
//			scanf("%d%d",&x,&y);
//			int t=query(0,32000,0,x,1);
//			ti[t]++;
//			insert(0,32000,x,x,1);
//		}
//		for ( int i=0 ; i<n ; i++ )
//			printf("%d\n",ti[i]);
//	}
//}

#include<iostream>
#define MAXN 32010
#define MAX 15010
using namespace std;
struct node
{
	int l,r,mark;
}tree[MAXN*4];

void make_tree( int l, int r, int v )
{	
	int mid=(l+r)>>1;
	tree[v].l=l,tree[v].r=r,tree[v].mark=0;
	if( l!=r )
	{
		make_tree( l, mid, v<<1 );
		make_tree( mid+1, r, (v<<1)+1 );
	}
}

void update( int l, int r, int v )
{
	int mid=(tree[v].l+tree[v].r)>>1;
	if( l==tree[v].l && tree[v].r==r )
	{
		tree[v].mark++;
		return ;
	}
	if( r<=mid ) update( l, r, v<<1 );
	else if( l>mid ) update( l, r, (v<<1)+1 );
	else 
	{
		update( l, mid, v<<1 );
		update( mid+1, r, (v<<1)+1 );
	}
	tree[v].mark=tree[v<<1].mark+tree[(v<<1)+1].mark;
}

int query( int l, int r, int v )
{
	int mid=(tree[v].l+tree[v].r)>>1;
	if( tree[v].l==l && tree[v].r==r )
		return tree[v].mark;
	if( r<=mid ) return query( l, r, v<<1 );
	else if( l>mid ) return query( l, r, (v<<1)+1 );
	else return query( l, mid, v<<1 )+query( mid+1, r, (v<<1)+1 );
}

int main( )
{
	int n,x,y,i;
	int range[MAX];
	while( scanf("%d",&n) !=EOF )
	{
		memset( range, 0, sizeof(range) );
		make_tree( 0, 32000, 1 );
		for( i=0; i<n; i++ )
		{
			scanf("%d%d",&x,&y);
			int t=query( 0, x, 1 );
			range[t]++;
			update( x, x, 1 );
		}
		for( i=0; i<n; i++ )
			printf("%d\n",range[i]);
	}
	return 0;
}