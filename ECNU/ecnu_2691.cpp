#include<iostream>
#define MAXN 10000
using namespace std;
int father[MAXN],rank[MAXN],value[MAXN];
bool root[MAXN];

void inti_set( int n )
{
	int i;
	for( i=0; i<n; i++ )
		father[i]=i,rank[i]=1,root[i]=true;
}

int find_root( int p )
{
	if( father[p]!=p )
		father[p]=find_root( father[p] );
	return father[p];
}

void union_set( int x, int y )
{
	int a, b;
	a = find_root( x );
	b = find_root( y );
	if( a!=b )
	{
		if( rank[a] > rank[b] )
			father[b]=a,value[a]+=value[b],root[b]=false;
		else if( rank[a] < rank[b] ) 
			father[a]=b,value[b]+=value[a],root[a]=false;
		else
			father[b]=a,rank[a]++,value[a]+=value[b],root[b]=false;
	}
}

int main()
{
	int n,m,x,y,i,j;
	bool flag;
	double d,d1;
	while( scanf("%d%d",&n,&m) !=EOF )
	{
		inti_set( n );
		for( i=0; i<n; i++ )
			scanf("%d",&value[i]);
		for( i=0; i<m; i++ )
		{
			scanf("%d%d",&x,&y);
			union_set( x, y );
		}
		for( i=0; i<n; i++ )
			if( root[i] && value[i]!=0  )
				break;
		if( i==n )printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}		