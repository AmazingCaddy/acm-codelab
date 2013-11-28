#include<iostream>
#define MAXN 15
using namespace std;
int main( )
{
	int P[MAXN][MAXN];
	int i,j,n,r;
	for( i=1; i<=12; i++ )
		P[i][0]=1;
	for( i=1; i<=12; i++ )
		for( j=1; j<=i; j++ )
			P[i][j]=P[i][j-1]*(i-j+1);
	while( scanf("%d%d",&n,&r) != EOF )
	{
		if( r==0 )printf("1\n");
		else printf("%d\n",P[n][r]/r);
	}
	return 0;
}