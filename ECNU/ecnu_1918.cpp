#include<stdio.h>
#define N 256
int b[N],n;
void f( int a[], int p )
{
	int i;
	if( p==n )
	{
		printf("%d",a[0]);
		for( i=1; i<n; i++ )
			printf(" %d",a[i]);
		printf("\n");
	}
	else 
	{
		for( i=0; i<p; i++ )
		{
			b[2*i]=(a[i]+a[i+p])/2;
			b[2*i+1]=(a[i]-a[i+p])/2;
		}
		for( i=0; i<2*p; i++ )
			a[i]=b[i];
		f( a, 2*p );
	}
}
int main()
{
	int i;
	int a[N];
	while( scanf("%d",&n) && n!=0 )
	{
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		f( a, 1 );
	}
	return 0;
}