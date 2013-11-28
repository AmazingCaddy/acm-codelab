#include<iostream>
#define MAXN 100000
#define NONE 0 
using namespace std;

struct node
{
	int l,r,mark;
}tree[4*MAXN];
int a[MAXN];
bool c[32];
int n,t,o,aa,bb,cc;
char s;

void make_tree( int l, int r, int v )
{
	int mid;
	tree[v].l=l;
	tree[v].r=r;
	tree[v].mark=1;
	mid=( l + r )>>1;
	if ( l != r )
	{
		make_tree( l, mid, v<<1 );
		make_tree( mid+1, r, (v<<1)+1 );
	}
}

void change( int l, int r, int color, int v )
{  
	int mid=( tree[v].l + tree[v].r )>>1;
	//if( r<tree[v].l || l>tree[v].r ) return ;
	if( l==tree[v].l && r==tree[v].r )
	{
		tree[v].mark=color;
		return ;
	}
	if( tree[v].mark!=NONE && tree[v].mark!=color )
	{
		tree[v<<1].mark=tree[v].mark;
		tree[(v<<1)+1].mark=tree[v].mark;
		tree[v].mark=NONE;
	}
	if( r<=mid ) change( l, r, color, v<<1 );
	else if( l>mid ) change( l, r, color, (v<<1)+1 );
	else 
	{
		change( l, mid, color, v<<1 );
		change( mid+1, r, color, (v<<1)+1 );
	}
}

void check( int l, int r, int v )
{
	int mid=(tree[v].l+tree[v].r)>>1;
	if( tree[v].mark>0 )
	{
		c[tree[v].mark]=true;
		return ;
	}
	if( tree[v].mark==0 /*&& tree[v].l != tree[v].r*/ )
	{
		if( r <= mid ) check( l, r, v<<1 );
		else if( l > mid ) check( l, r, (v<<1)+1 );
		else
		{  
			check( l, mid, v<<1 );
			check( mid+1, r, (v<<1)+1 );
		}
	}
}

int cnt( )
{
	int i;
	int s=0;
	for( i=1; i<32; i++ )
		if(c[i])s++;
	return s;
}

int main( )
{   
	scanf("%d%d%d",&n,&t,&o);
	getchar( );
	make_tree( 1, n, 1 );
	while( o-- )
	{  
		scanf("%c",&s);
		getchar( );
		if( s=='C' )
		{  
			scanf("%d%d%d",&aa,&bb,&cc);
			getchar( );
			if( aa<=bb ) change( aa, bb, cc, 1 );
			else change( bb, aa, cc, 1 );
		}
		else 
		{   
			scanf("%d%d",&aa,&bb);
			getchar( );
			memset( c, false, sizeof(c) );
			if( aa <= bb ) check( aa, bb, 1 );
			else check( bb, aa, 1 );
			printf("%d\n",cnt( ));
		}
	}
	return 0;
}
