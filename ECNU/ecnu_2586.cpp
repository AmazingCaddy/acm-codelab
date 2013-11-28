#include<iostream>
using namespace std;
#define S 1000000
#define M 1000000
int father[M], rank[M];
typedef struct fri
{
	int x,y;
}FRI;

FRI fri[M];

void init_set( int n )
{
	int i;
	for( i = 0; i < n; i++)
		father[i] = i, rank[i] = 0; 
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
		father[b] = a, rank[a] ++;
}

int main( )
{
	int i,p,q;
	int s,m,n;
	scanf("%d%d%d",&s,&m,&n);
	init_set( s );
	for( i=0; i<m; i++ )
	{
		scanf("%d%d",&fri[i].x,&fri[i].y);
		union_set( fri[i].x, fri[i].y );
	}

	for( i=0; i<n; i++ )
	{
		scanf("%d%d",&p,&q);
		if( find_root(p) == find_root(q) )printf("1\n");
		else printf("0\n");
	}
	return 0;
}
