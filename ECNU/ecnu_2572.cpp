#include<stdio.h>
#include<stdlib.h>
#define N 100000
int a[N];
int compare( const void *a, const void *b )
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,i,k,temp;
	scanf("%d",&n);
	for( i=0; i<n; i++ )
		scanf("%d",&a[i]);
	
	qsort(a,n,sizeof(int),compare);

	scanf("%d",&k);
	for( i=0; i<k; i++ )
	{
		scanf("%d",&temp);
		printf("%d\n",a[temp-1]);
	}
	return 0;
}