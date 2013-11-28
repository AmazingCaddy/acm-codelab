#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
// c[i,j]=0                         if( i=0 || j=0 )
// c[i,j]=c[i-1,j-1]+1              if( i,j>0 && xi==yi )
// c[i,j]=max( c[i,j-1],c[i-1,j])   if( i,j>0 && xi!=yi )
int m[6][6] = { { 0, 0, 0, 0, 0, 0     }, 
				{ 0, 5, -1, -2, -1, -3 }, 
				{ 0, -1, 5, -3, -2, -4 }, 
				{ 0, -2, -3, 5, -2, -2 }, 
				{ 0, -1, -2, -2, 5, -1 },
				{ 0, -3, -4, -2, -1, 0 } };

const int maxn = 103;
int dp[maxn][maxn];

int max( int a, int b ) { return ( a > b ? a : b ); }

int d( char x, char y )
{
	int i, j;
	switch( x )
	{
		case 'A': i = 1; break;
		case 'C': i = 2; break;
		case 'G': i = 3; break;
		case 'T': i = 4; break;
		case '-': i = 5; break;
	}
	switch( y )
	{
		case 'A': j = 1; break;
		case 'C': j = 2; break;
		case 'G': j = 3; break;
		case 'T': j = 4; break;
		case '-': j = 5; break;
	}
	return m[i][j];
}

int main(int argc, char *argv[])
{
	int t, n, m;
	char a[maxn], b[maxn];
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		scanf("%s",a);
		scanf("%d",&m);
		scanf("%s",b);
		memset( dp, 0, sizeof( dp ) );
		dp[0][0] = 0;
		for( int i = 1; i <= n; i++ )
			dp[i][0] = dp[i-1][0] + d( a[i-1], '-' );
		for( int j = 1; j <= m; j++ )
			dp[0][j] = dp[0][j-1] + d( '-', b[j-1] );
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= m; j++ )
			{
				dp[i][j] = max(  dp[i][j-1] + d( '-', b[j-1] ),
					dp[i-1][j] + d( a[i-1], '-' ) );
				dp[i][j] = max( dp[i][j], dp[i-1][j-1] + d( a[i-1], b[j-1] ) );
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
