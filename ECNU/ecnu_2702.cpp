#include<iostream>
using namespace std;
 
const int MAXN = 200000+10 ; 
int tree[4*MAXN];
class segment_tree
{
	int h,w,res;
public:
	void build ( int b, int e , int v )
	{
		if ( b==e )
		{
			tree[v]=w;
			return ;
		}
		int m=(b+e)>>1;
		build(b,m,2*v);
		build(m+1,e,2*v+1);
		tree[v]=w;
	}
	segment_tree( int _h , int _w )
	{
		h=_h;
		w=_w;
		build(1,h,1);
	}
	int update ( int b, int e , int v , int len )
	{
		if ( tree[v]<len )
			return tree[v];
		if ( b==e )
		{
			res=b;
			tree[v]-=len;
			return tree[v];
		}
		int t1,t2,m=(b+e)>>1;
		if ( tree[2*v]>=len )
		{
			t1=update(b,m,2*v,len);
			t2=tree[2*v+1];
		}
		else
		{
			t1=tree[2*v];
			t2=update(m+1,e,2*v+1,len);
		}
		return tree[v]=max(t1,t2);
	}
	int find( int len )
	{
		res=-1;
		update(1,h,1,len);
		return res;
	}
};
 
int main ( )
{
	int w,h,n,i,len,res;
	while ( scanf("%d%d%d",&h,&w,&n)!=EOF )
	{
		h=h>n?n:h;
		segment_tree t(h,w);
		for ( i=0 ; i<n ; i++ )
		{
			scanf("%d",&len);
			res=t.find(len);
			printf("%d\n",res);
		}
	}
}