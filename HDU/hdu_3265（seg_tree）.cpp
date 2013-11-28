#include<iostream>
#include<algorithm>
#define MAXN 400003
using namespace std;
struct line
{
	int x;
	int y1,y2;
	int flag;
	bool operator<( const line &a )
	{
		return x<a.x;
	}
};

struct segment_tree
{
	int L,R;
	int len;
	int cover;
};

segment_tree tree[MAXN*4];
line yline[MAXN*2];
int y[MAXN*2],ty[MAXN];
int len;

int bin_search( int k )
{
	int l=0,r=len,mid;
	while( l <= r )
	{
		mid = ( l + r ) >> 1;
		if( y[mid] == k ) return mid;
		else if( y[mid] < k ) l = mid + 1;
		else r = mid - 1;
	}
}
void make_tree( int v, int l, int r )
{
	int mid;
	tree[v].L = l, tree[v].R = r, tree[v].len = 0, tree[v].cover = 0;
	mid = ( l + r ) >> 1;
	if( r - l > 1 )
	{
		make_tree( v << 1, l, mid );
		make_tree( ( v << 1 ) + 1, mid, r );
	}
}

void getlen( int v )
{
	if( tree[v].cover > 0 )
		tree[v].len = y[tree[v].R] - y[tree[v].L];
	else if( tree[v].R - tree[v].L == 1 )
		tree[v].len=0;
	else tree[v].len = tree[v<<1].len + tree[(v<<1)+1].len;
}

void update( int v, int l, int r, int flag )
{
	int mid;
	if( tree[v].L == l && tree[v].R == r )
	{
		tree[v].cover += flag;
		getlen( v );
		return ;
	}
	mid = ( tree[v].L + tree[v].R ) >> 1;
	if( mid >= r ) update( v << 1, l, r, flag );
	else if( mid <= l )update( ( v << 1 ) + 1, l, r, flag );
	else 
	{
		update( v << 1, l, mid, flag );
		update( ( v << 1 ) + 1, mid, r, flag );
	}
	getlen( v );
}

int main( )
{
	int n,i,t0,t1,t2,t3,t4,t5,t6,t7,left,right;
	int x1,x2,x3,x4,y1,y2,y3,y4;
	__int64 ans;
	while( scanf("%d",&n) && n )
	{
		//n = n << 2;
		for( i=0; i<n; i++ )
		{
			scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
			t0=i<<3,t1=(i<<3)+1,t2=(i<<3)+2,t3=(i<<3)+3;
			t4=(i<<3)+4;t5=(i<<3)+5,t6=(i<<3)+6,t7=(i<<3)+7;
			
			yline[t0].x=x1,yline[t0].y1=y1,yline[t0].y2=y2,yline[t0].flag=1;
			yline[t1].x=x3,yline[t1].y1=y1,yline[t1].y2=y2,yline[t1].flag=-1;

			yline[t2].x=x3,yline[t2].y1=y1,yline[t2].y2=y3,yline[t2].flag=1;
			yline[t3].x=x4,yline[t3].y1=y1,yline[t3].y2=y3,yline[t3].flag=-1;

			yline[t4].x=x3,yline[t4].y1=y4,yline[t4].y2=y2,yline[t4].flag=1;
			yline[t5].x=x4,yline[t5].y1=y4,yline[t5].y2=y2,yline[t5].flag=-1;

			yline[t6].x=x4,yline[t6].y1=y1,yline[t6].y2=y2,yline[t6].flag=1;
			yline[t7].x=x2,yline[t7].y1=y1,yline[t7].y2=y2,yline[t7].flag=-1;

			t0=i<<2,t1=(i<<2)+1,t2=(i<<2)+2,t3=(i<<2)+3;
			ty[t0]=y1,ty[t1]=y2,ty[t2]=y3,ty[t3]=y4;
		}
		n = n << 2;
		sort( ty, ty+n );

		len=1;
		y[0]=ty[0];
		for( i=1; i<n; i++ )
			if( ty[i] != ty[i-1] )
				y[len++] = ty[i];

		len--;
		n = n << 1;

		sort( yline, yline+n );
		make_tree( 1, 0, len );

		left = bin_search( yline[0].y1 );
		right = bin_search( yline[0].y2 );

		update( 1, left, right, yline[0].flag );
		ans = 0;
		for( i = 1; i < n; i++ )
		{
			ans += (__int64)tree[1].len * ( yline[i].x - yline[i-1].x );
			left = bin_search( yline[i].y1 );
			right = bin_search( yline[i].y2 );
			if( left != right )  //有线段长度为0的情况
				update( 1, left, right, yline[i].flag );
		}
		printf("%I64d\n",ans);
	}
	return 0;
}