// 最小割定理是一个二分图中很重要的定理－－－
// 一个二分图中的最大匹配数等于这个图中的最小点覆盖数。
// 最小点覆盖：假如选了一个点就相当于覆盖了以它为端点的所有边，
// 你需要选择最少的点来覆盖所有的边 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 2505;
int g[ maxn ][ maxn ];
int vis[ maxn ], match[ maxn ];
int tx[ 55 ][ 55 ], ty[ 55 ][ 55 ];
char s[ 55 ][ 55 ];
int n, m, nx, ny;

int dfs( int from )
{
	for( int i = 1; i <= ny; i++ )
	{
		if( g[ from ][ i ] && !vis[ i ] )
		{
			vis[ i ] = 1;
			if( match[ i ] == -1 || dfs( match[ i ] ) )
			{
				match[ i ] = from;
				return 1;
			}
		}
	}
	return 0;
}

int Hungray( )
{
	int sum = 0;
	memset( match, -1, sizeof( match ) );
	for( int i = 1; i <= nx; i++ )
	{
		memset( vis, 0, sizeof( vis ) );
		if( dfs( i ) ) sum++;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	scanf("%d%d", &n, &m);
	for( int i = 1; i <= n; i++ )
		scanf("%s",s[i]+1);
	nx = ny = 0;
	for( int i = 1; i <= n; i++ )
	{
		int j = 1;
		while( j <= m )
		{
			if( s[i][j] == '*' )
			{
				nx++;
				while( s[i][j] == '*' ) tx[i][j] = nx, j++;
			}
			else j++;
		}
	}
	for( int j = 1; j <= m; j++ )
	{
		int i = 1;
		while( i <= n ) 
		{
			if( s[i][j] == '*' )
			{
				ny++;
				while( s[i][j] == '*' ) ty[i][j] = ny, i++;
			}
			else i++;
		}
	}
	for( int i = 1; i <= n; i++ )
	{
		for( int j = 1; j <= m; j++ )
		{
			if( s[i][j] == '*' )
				g[ tx[i][j] ][ ty[i][j] ] = 1;
		}
	}
	int ans = Hungray( );
	printf("%d\n",ans);
	return 0;
}
