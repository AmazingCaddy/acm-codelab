#include<stdio.h>
#define N 100003
int max( int x, int y )
{
	return x>=y?x:y;
}
int main( )
{
	int i,n,maxn,sum;
	int a[N];
	while( scanf("%d",&n) != EOF )
	{
		
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		maxn=a[0];sum=a[0];
		for( i=1; i<n; i++ )
		{
			if( sum<0 ){ maxn=max( maxn, a[i] ); sum=a[i]; }
			else 
			{
				sum=sum+a[i];
				maxn=max( sum, maxn );
			}
		}
		printf("%d\n",maxn);
	}
	return 0;
}