//构造传递闭包，度为n-1的点可以确定位置

#include<iostream>
#define MAXN 102
using namespace std;
int c[MAXN][MAXN];
int main( )
{
	int n,m,a,b,ans,total;
	int i,j,k;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		memset( c, 0, sizeof(c) );
		for( i=0; i<m; i++ )
		{
			scanf("%d%d",&a,&b);
			c[a][b]=1;
		}
		for( k=1; k<=n; k++ )
			for( i=1; i<=n; i++ )
				for( j=1; j<=n; j++ )
					if( c[i][k]+c[k][j]==2 )
						c[i][j]=1;
		ans=0;
		for( i=1; i<=n; i++ )
		{
			total=0;
			for( j=1; j<=n; j++ )
				if( c[i][j] || c[j][i] )total++;
			if( total==n-1 )ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}