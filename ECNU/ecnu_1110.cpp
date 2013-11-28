#include<iostream>
#define MAXN 202
#define INF -1000000000
using namespace std;
int map[MAXN][MAXN];
int d[MAXN][MAXN];
int n,m;
void Floyd( )
{
	int i,j,k;
	for( k=1; k<=n; k++ )
		for( i=1; i<=n; i++ )
			for( j=1; j<=n; j++ )
				if( map[i][k]!=INF && map[k][j]!=INF && map[i][k]+map[k][j]>map[i][j] )
					map[i][j]=map[i][k]+map[k][j];
}
int main( )
{
	int i,j,p,x,y,v;
	while( scanf("%d%d",&n,&m) !=EOF )
	{
		for( i=1; i<=n; i++ )
			for( j=1; j<=n; j++ )
				map[i][j]=INF;
		for( i=0; i<m; i++ )
		{
			scanf("%d%d%d",&x,&y,&v);
			if( map[x][y]<v )map[x][y]=v;
		}
		Floyd( );
		scanf("%d",&p);
		for( i=0; i<p; i++ )
		{
			scanf("%d%d",&x,&y);
			if( map[x][y]==INF )printf("-1\n");
			else printf("%d\n",map[x][y]);
		}
	}
	return 0;
}