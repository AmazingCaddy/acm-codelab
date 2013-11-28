#include<iostream>
#define M 18
using namespace std;
bool visit[M][M];
char map[M][M];
int count=0,m,num=0,max=0;

bool fs ( int a )
{
	int i;
	for( i=1; i<m; i++ )
	{
		if( !visit[a][i] && map[a][i]=='Y' )
		{
			count++;
			visit[a][i]=true;
			if ( fs ( i ) )return true;
			visit[a][i]=false;
		}
	}
	return false;
}
		
int main()
{
	int i,j,n;
	scanf("%d",&n);
	while( n-- )
	{
		scanf("%d",&m);
		for( i=0; i<n; i++ )
			for( j=0; j<n; j++ )
				scanf("%c",&map[i][j]);


