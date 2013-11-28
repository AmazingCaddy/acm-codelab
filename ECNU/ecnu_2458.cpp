//  首先对给出的序列进行离散化统计，将相同的数字压缩成一个节点，
//  然后统计出这个压缩后的节点在原序列中起点和终点的位置，以及出现的次数等。
//  当然也要记录原数字在离散化后的序列中的位置。
//  之后就是查询，比方说[a,b]
//  1.如果a,b属于同一个组，那么区间长度就是我们想要的答案 b-a+1;
//  2.如果a,b组号相差1，说明该区间被中间截断了，只要分别研究两侧的区间，
//  取大值即可Max(c-a+1,b-c) ---其中c是中间点---
//  3.如果a,b组号相差大于1，先取出两侧进行研究，取大值，然后再用线段树，
//  算出中间区间的最大值，与刚才的那个数比较，取出最大值即可。
//
#include<iostream>
#define MAXN 100005
using namespace std;
struct node
{
	int l,r,count;
};
struct line
{
	int left,right,count;
};
node tree[MAXN*3];
line p[MAXN];
int hash[MAXN];
int num[MAXN];
int max( int a, int b )
{
	return a>b?a:b;
}
int inti( int n )
{
	int t=1,i;
	p[t].left=1,p[t].right=1,p[t].count=1;
	for( i=2; i<=n; i++ )
	{
		if( num[i-1]==num[i] ) p[t].count++;
		else 
		{
			p[t].right=p[t].count+p[t].left-1;
			t++;
			p[t].left=p[t-1].right+1;
			p[t].count=1;
		}
		hash[i]=t;
	}
	p[t].right=p[t].count+p[t].left-1;
	return t;
}

void make_tree( int l, int r, int v )
{
	int mid=(l+r)>>1;
	tree[v].l=l,tree[v].r=r;
	if( l!=r )
	{
		make_tree( l, mid, v<<1 );
		make_tree( mid+1, r, (v<<1)+1 );
		tree[v].count=max( tree[v<<1].count, tree[(v<<1)+1].count );
	}
	else tree[v].count=p[l].count;
}

int query ( int l, int r, int v )
{
	int mid=(tree[v].l+tree[v].r)>>1;
	if( tree[v].l==l && tree[v].r==r )
		return tree[v].count;
	if( mid>=r ) return query( l, r, v<<1 );
	if( mid<l ) return query( l, r, (v<<1)+1 );
	return max( query( l, mid ,v<<1 ), query( mid+1, r, (v<<1)+1 ) );
}

int compute( int a, int b )
{
	int MAX;
	if( hash[a]==hash[b] )  //处于同一区间
		return b-a+1;        
	if( hash[a]+1==hash[b] )  //相邻区间
		return max( p[hash[a]].right-a+1, b-p[hash[b]].left+1 );
	//还有第三个区间，去除两头的，查询剩下的最大值，再跟两头的比较大小
	MAX=max( p[hash[a]].right-a+1, b-p[hash[b]].left+1 );
	return max( query( hash[a]+1, hash[b]-1, 1 ), MAX );
}

int main( )
{
	int i,a,b,n,q,x;
	while( scanf("%d",&n) && n )
	{
		scanf("%d",&q);
		for( i=1; i<=n; i++ )
			scanf("%d",&num[i]);
		x=inti( n );
		make_tree( 1, x, 1 );
		for( i=0; i<q; i++ )
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",compute( a, b ));
		}
	}
	return 0;
}