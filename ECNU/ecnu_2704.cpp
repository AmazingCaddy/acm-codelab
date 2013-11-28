#include<iostream>
#define MAXN 100001
using namespace std;
int a[MAXN],b[MAXN];

int compare( const void *a, const void *b )
{
	return (*(int*)a)-(*(int*)b);
}

int main( )
{
	int n,m,i,j,count;
	while( scanf("%d",&n) != EOF )
	{
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for( i=0; i<m; i++ )
			scanf("%d",&b[i]);
		qsort( b, m, sizeof(int), compare );
		count=0;
		for( i=0; i<n; i++ )
			for( j=0; j<m; j++ )
			{
				if( b[j]>a[i] )break;
				if( a[i]%b[j]==0 )count++;
			}
		printf("%d\n",count);
	}
	return 0;
}