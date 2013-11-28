#include<iostream>
#define MAXN 100005
#define lowbit(x) (x&(-x))
using namespace std;
struct edge
{
	int from,to;
	edge *next;
	edge( ):from(0),to(0),next(NULL){ }
};
edge *head[MAXN];
int se[MAXN][2],tree[MAXN];
bool vis[MAXN];
int n,m;
int cur=0;

void add_edge( int from, int to )
{
    edge *p=new edge( );
    p->from=from;
    p->to=to;
    p->next=head[from];
    head[from]=p;     //头结点存有数据
}//将边加在链表的前面，节省搜索链表尾部的时间

void DFS( int now )
{
	edge *p=head[now];
	se[now][0]=++cur;
	while( p!=NULL )
	{
		DFS( p->to );
		p=p->next;
	}
	se[now][1]=cur;
}

void update( int x, int val )
{
	while( x<=n )
	{
		tree[x]+=val;
		x+=lowbit(x);
	}
}

int query( int x )
{
	int sum=0;
	while( x>0 )
	{
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

int main( )
{
	int i,from,to,num,ans;
	char ch;
	//freopen("A.txt","w",stdout);
	while( scanf("%d",&n) != EOF )
	{
		for( i=1; i<n; i++ )
		{
			scanf("%d%d",&from,&to);
			add_edge( from, to );
		}
		DFS( 1 );
		memset( tree, 0, sizeof(tree) );
		for( i=1; i<=n; i++ )
		{
			vis[i]=true;
			update( i, 1 );
		}
		scanf("%d",&m);
		for( i=0; i<m; i++ )
		{	
			getchar( );
			scanf("%c%d",&ch,&num);
			if( ch=='C' )
			{
				if( vis[num] ) update( se[num][0], -1 );
				else update( se[num][0], 1 ); 
				vis[num]=!vis[num];
			}
			if( ch=='Q' )
			{
				ans=query( se[num][1] )-query( se[num][0]-1 );
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}