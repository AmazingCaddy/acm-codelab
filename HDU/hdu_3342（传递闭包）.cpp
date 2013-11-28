#include<iostream>
#define MAXN 102
using namespace std;
int a[MAXN][MAXN];
void Floyd( int n )
{
	int i,j,k;
	for( k=0; k<n; k++ )
		for( i=0; i<n; i++ )
			for( j=0; j<n; j++ )
				if( a[i][j]==0 && a[i][k]+a[k][j]==2 )
					a[i][j]=1;
}
int main( )
{
	int n,m,x,y,flag;
	int i,j;
	while( scanf("%d%d",&n,&m) )
	{
		if( n==0 && m==0 )break;
		memset( a, 0, sizeof(a) );
		for( i=0; i<m; i++ )
		{
			scanf("%d%d",&x,&y);
			a[x][y]=1;
		}
		Floyd( n );
		flag=0;
		for( i=0; i<n; i++ )
		{
			for( j=i; j<n; j++ )
			{
				if( a[i][j] && a[j][i] )
				{
					flag=1;
					break;
				}
			}
			if( flag )break;
		}
		if( i==n )printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}