#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[10000][3];
const int p=9997;
int main()
{
	int i,j,t,m,n,u,v;
	memset( g, 0, sizeof( g ) );
	g[3][0]=2;
	g[3][1]=3;
	g[3][2]=2;
	g[1][0]=2;
	g[2][0]=4;
	g[0][0]=0;
	for( i = 4; i <= 10000; i++ )
	{
		g[i][0] = ( g[i-1][0] + g[i-1][2] ) % p;
		g[i][1] = ( g[i-1][1] + g[i-1][0] ) % p;
		g[i][2] = g[i-1][1] % p;
	}
	while( scanf("%d",&n) && ( n != -1 ) )
	{
		printf("%d\n",(g[n][0]+g[n][1]+g[n][2] )%p );
	}
	return 0;
}
