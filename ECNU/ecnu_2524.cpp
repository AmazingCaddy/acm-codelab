// 题目描述：n头奶牛，晚上陪他们说话，给出每头奶牛需要花费的时间，然后给出P条路（稀疏图），
// 所要花费的时间，需要做的是去掉尽可能多的路，但仍要保证图的连通性，并且求出从某个起点，
// 出发照顾完每头牛后回到起点所要花费的最少时间，每路过一头奶牛都要和他说话，
// 也就是说每头牛可能要和他说多次话。关键是如何把问题与最小生成树联系起来。
// 我想到的是扩展路径，把路的长度加上和奶牛（相当与结点）说话的时间。
// 正确性是可以证明的：首先，要去掉尽可能多的点，所以最后留下的必然是棵树，不可能有环。
// 对于一棵树，从某点（以该点为根）出发，遍历所以的结点以后回到根结点，每条边必然需要走两遍，
// 且在一条边所连接的结点上都会有一次停留（与奶牛说话）。
// 所以建图的时候只要把边的权值赋成原来的权值乘以2加上边连接的两个结点的值，
// 再做一次最小生成树就可以了，注意还要加上根节点的值，因为一出来的时候正好在根上，
// 这一次是多出来的,由于根是任意的，所以取最小的。由于是稀疏图，用Kruskal+并查集比较方便。


#include<iostream>
#include<algorithm>
#define MAXN 100002
#define INF 999999999
using namespace std;
struct edge
{
	int x,y;
	int val;
	bool operator<( const edge &b )
	{
		return val<b.val;
	}
};
edge e[MAXN];
int father[MAXN],rank[MAXN];
int a[10002];
void init_set( int n )
{
	int i=0;
	for( i=0; i<n; i++ )
	{
		father[i]=i;
		rank[i]=1;
	}
}

int find_root( int x )
{
	if( father[x]!=x )
		father[x]=find_root( father[x] );
	return father[x];
}

void union_set( int p, int q )
{
	int a,b;
	a = find_root(p);
	b = find_root(q);
	if( rank[a] > rank[b] )
		father[b] = a;
	else if( rank[a] < rank[b] ) 
		father[a]=b;
	else
		father[b]=a, rank[a]++;
}

int main( )
{
	int i,j,n,m,x,y,val,min;
	scanf("%d%d",&n,&m);
	min=INF;
	for( i=1; i<=n; i++ )
	{
		scanf("%d",&a[i]);
		if( a[i]<min )min=a[i];
	}
	for( i=0; i<m; i++ )
	{
		scanf("%d%d%d",&x,&y,&val);
		e[i].x=x,e[i].y=y;
		e[i].val=val*2+a[x]+a[y];
	}
	sort( e, e+m );
	init_set( n );
	for( i=0, j=n-1; i<m && j; i++ )
	{
		x=find_root( e[i].x );
		y=find_root( e[i].y );
		if( x!=y )
		{
			union_set( e[i].x, e[i].y );
			min+=e[i].val;
			j--;
		}
	}
	printf("%d\n",min);
	return 0;
}