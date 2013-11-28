#include<stdio.h>
#define N 10
#define M 9973
int n;
void f( int a[][N] ,int b[][N] )
{
	int i,j,k;
	int c[N][N];
	for( i=0; i<n; i++ )
	{   
		for( j=0; j<n; j++ )
		{
			c[i][j]=0;
			for( k=0; k<n; k++ )
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
	for( i=0; i<n; i++ )
		for( j=0; j<n; j++ )
			a[i][j]=c[i][j]%M;	
}

int main()
{
	int a[N][N],I[N][N];
	int c,t,i,j,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		for( i=0; i<n; i++ )
		{
			for( j=0; j<n; j++ )
			{
				scanf("%d",&a[i][j]);
				if( i==j )I[i][j]=1;
				else I[i][j]=0;
			}
		}
		while( 1 )
		{
			if( c & 1 )
				f( I, a );
			f( a, a );
			c>>=1;
			if( c==0 )break;
		}
		sum=0;
		for( i=0; i<n; i++ )
			sum+=I[i][i];
		printf("%d\n",sum%M);
	}
	return 0;
}