#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 103;
const int inf = 100000000;
int dp[maxn][maxn], path[maxn][maxn];
char ch[maxn];

void print( int i, int j )
{
	if( i > j ) return;
	if( i == j )
	{
		if( ch[i] == '(' || ch[j] == ')' ) printf("()");
		else printf("[]");
	}
	else if( path[i][j] == -1 )
	{
		printf("%c",ch[i]);
		print( i + 1, j - 1 );
		printf("%c",ch[j]);
	}
	else
	{	
		print( i, path[i][j] );
		print( path[i][j] + 1, j );
	}
}

int main(int argc, char *argv[])
{
	scanf("%s",ch);
	int len = strlen( ch );
	memset( dp, 0, sizeof( dp ) );
	for( int i = 0; i < len; i++ )dp[i][i] = 1;
	for( int i = 1; i < len; i++ )
	{
		for( int j = 0; j < len - i; j++ )
		{
			int k = j + i;
			dp[j][k] = inf;
			// S形如(S’)或者[S’]: dp[j][k] = min( dp[j][k], dp[j+1,k-1] );
			if( ch[j] == '(' && ch[k] == ')' || ch[j] == '[' && ch[k] == ']' )
				if( dp[j][k] > dp[j+1][k-1] ) dp[j][k] = dp[j+1][k-1], path[j][k] = -1;
			//长度大于1: dp[j][k] = min( dp[j][k], dp[j,p]+d[p+1,k] ) { j <= p <= k-1 }
			for( int p = j; p < k; p++ )
			{
				if( dp[j][k] > dp[j][p] + dp[p+1][k] )
				{
					dp[j][k] = dp[j][p] + dp[p+1][k];
					path[j][k] = p;
				}
			}
		}
	}
	print( 0, len - 1 );
	printf("\n");
	return 0;
}
