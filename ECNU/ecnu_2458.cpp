//  ���ȶԸ��������н�����ɢ��ͳ�ƣ�����ͬ������ѹ����һ���ڵ㣬
//  Ȼ��ͳ�Ƴ����ѹ����Ľڵ���ԭ�����������յ��λ�ã��Լ����ֵĴ����ȡ�
//  ��ȻҲҪ��¼ԭ��������ɢ����������е�λ�á�
//  ֮����ǲ�ѯ���ȷ�˵[a,b]
//  1.���a,b����ͬһ���飬��ô���䳤�Ⱦ���������Ҫ�Ĵ� b-a+1;
//  2.���a,b������1��˵�������䱻�м�ض��ˣ�ֻҪ�ֱ��о���������䣬
//  ȡ��ֵ����Max(c-a+1,b-c) ---����c���м��---
//  3.���a,b���������1����ȡ����������о���ȡ��ֵ��Ȼ�������߶�����
//  ����м���������ֵ����ղŵ��Ǹ����Ƚϣ�ȡ�����ֵ���ɡ�
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
	if( hash[a]==hash[b] )  //����ͬһ����
		return b-a+1;        
	if( hash[a]+1==hash[b] )  //��������
		return max( p[hash[a]].right-a+1, b-p[hash[b]].left+1 );
	//���е��������䣬ȥ����ͷ�ģ���ѯʣ�µ����ֵ���ٸ���ͷ�ıȽϴ�С
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