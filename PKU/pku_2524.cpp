#include<iostream>
#define MAXN 50001
using namespace std;
int father[MAXN],rank[MAXN];
int num;
void inti_set( int n )
{
	int i;
	for( i=1; i<=n; i++ )
		father[i]=i,rank[i]=1;
}

int find_root( int p )
{
	if( father[p]!=p )
		father[p]=find_root( father[p] );
	return father[p];
}

void union_set( int p, int q )
{
	int a, b;
	a = find_root( p );
	b = find_root( q );
	if( a==b ) return;
	num--;
	if( rank[a] > rank[b] )
		father[b] = a;
	else if( rank[a] < rank[b] ) 
		father[a] = b;
	else
		father[b] = a, rank[a]++;
}

int main( )
{
	int n,m,i,p,q,c;
	c=0;
	while( scanf("%d%d",&n,&m) && !( n==0 && m==0 ) )
	{
		c++;
		inti_set( n );
		num=n;
		for( i=0; i<m; i++ )
		{
			scanf("%d%d",&p,&q);
			union_set( p, q );
		}
		printf("Case %d: %d\n",c,num);
	}
	return 0;
}