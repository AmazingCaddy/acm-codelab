#include<iostream>
#include<cstdlib>
using namespace std;
#define M 15000
typedef struct 
{
	int value;
	int x,y;
}NODE;
 
NODE s[M];
int father[M], rank[M];
 
int compare( const void *a, const void *b )
{
	NODE *p=(NODE*)a,*q=(NODE*)b;
	return p->value-q->value;
}
 
void init( int n )
{
	int i=0;
	for( i=0; i<n; i++ )
	{
		father[i]=i;
		rank[i]=0;
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
		father[b] = a, rank[a] ++;
}
 
int main()
{
	int n,m,res,p,q,i,count;
	scanf("%d%d",&n,&m);
	for( i=0; i<m; i++ )
		scanf("%d%d%d",&s[i].x , &s[i].y , &s[i].value);
 
	qsort(s,m,sizeof(NODE),compare);
	init( m );
 
	res=0;count=0;
 
	for( i=0; i<m && count<n-1; i++ )
	{
		p=s[i].x;q=s[i].y;
		if ( find_root(p) != find_root(q) )
		{
			union_set( p, q );
			count++;
			res+=s[i].value;
		}
	}
	printf("%d\n",res);
	return 0;
}