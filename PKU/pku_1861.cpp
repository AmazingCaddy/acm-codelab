#include<iostream>
#include<cstdlib>
using namespace std;
#define N 1001
#define M 15001
struct NODE
{
	int value;
	int x,y;
	bool flag;
};
 
NODE s[M];
int father[N], rank[N];
bool visit[N];
 
int compare( const void *a, const void *b )
{
	NODE *p=(NODE*)a,*q=(NODE*)b;
	return p->value-q->value;
}
 
void init_set( int n )
{
	int i=0;
	for( i=0; i<n; i++ )
	{
		father[i]=i;
		rank[i]=1;
		visit[i]=false;
	}
}
 
int find_root( int p )
{
	if( father[p] != p ) 
		father[p] = find_root(father[p]);
	return father[p];
}
 
void union_set( int p, int q )
{
	int a, b;
	a = find_root(p);
	b = find_root(q);
	if( rank[a] > rank[b] )
		father[b] = a;
	else if( rank[a] < rank[b] ) 
		father[a] = b;
	else
		father[b] = a, rank[a]++;
}
 
int main( )
{
	int n,m,p,q,i,count,max;
	scanf("%d%d",&n,&m);
	for( i=0; i<m; i++ )
	{
		scanf("%d%d%d",&s[i].x , &s[i].y , &s[i].value);
		s[i].flag=false;
	}
	qsort( s, m, sizeof(NODE), compare );
	init_set( n );
	count=0;max=0;
	for( i=0; i<m && count<n-1; i++ )
	{
		p=s[i].x;q=s[i].y;
		if( !visit[p] || !visit[q] )
		{
			union_set( p, q );
			visit[p]=visit[q]=true;
			count++;
			s[i].flag=true;
			if( s[i].value>max )max=s[i].value;
		}
		else if ( find_root(p) != find_root(q) )
		{
			union_set( p, q );
			visit[p]=visit[q]=true;
			count++;
			s[i].flag=true;
			if( s[i].value>max )max=s[i].value;
		}
	}
	printf("%d\n%d\n",max,count);
	count=0;
	for( i=0; i<m && count<n-1; i++ )
		if( s[i].flag )
		{
			printf("%d %d\n",s[i].x,s[i].y);
			count++;
		}
	return 0;
}


//#include<iostream>
//using namespace std;
//#define MAXN 1001
//#define MAX 1000005
//#define M 15001
//struct node
//{
//	int x,y;
//	bool flag;
//};
//int cost[MAXN][MAXN];
//
//int prim( int n, int u )
//{
//	int lowcost[MAXN],closest[MAXN];
//	int i,j,k,min,sum;
//	for( i=1; i<=n; i++ )
//	{
//		lowcost[i]=cost[u][i];
//		closest[i]=u;
//	}
//	sum=0;k=0;
//	for( i=1; i<n; i++ )
//	{
//		min=MAX;
//		for( j=1; j<=n; j++ )		
//		{
//			if( lowcost[j]!=0 && lowcost[j]<=min )
//			{
//				min=lowcost[j];
//				k=j;
//			}
//		}
//		lowcost[k]=0;
//		sum++;
//		for( j=1; j<=n; j++ )
//		{
//			if( cost[k][j]!=0 && cost[k][j]<lowcost[j] )
//			{
//				lowcost[j]=cost[k][j];
//				closest[j]=k;
//			}
//		}
//	}
//	return sum;
//}
// 
// 
//int main( )
//{
//	int n,i,j,value;
//	node v[M];
//	memset( cost, -1, sizeof(cost) );
//	for( i=1; i<=n; i++ )
//	{
//		scanf("%d%d%d",&v[i].x,&v[i].y,value);
//		v[i].flag=false;
//		cost[v[i].x][v[i].y]=value;
//	}
//	for( i=1; i<=n; i++ )
//		cost[i][i]=0;
//	printf("%d\n%d\n",prim( n, 1 ),
//
//	return 0;
//}