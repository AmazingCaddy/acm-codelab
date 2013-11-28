#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 103;

int g[ maxn ][ maxn * 3 ];
int match[ maxn ], vis[ maxn ];
int n, m;

int dfs( int from )
{
	for( int i = 1; i <= m; i++ )
	{
		if( g[ from ][ i ] && ! vis[ i ] )
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

int hungray( )
{
	int sum = 0;
	memset( match, -1, sizeof( match ) );
	for( int i = 1; i <= n; i++ )
	{
		memset( vis, 0, sizeof( vis ) );
		if( dfs( i ) ) sum ++;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int cas, x, y;
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf("%d%d",&n,&m);
		memset( g, 0, sizeof( g ) );
		for( int i = 1; i <= n; i++ )
		{
			scanf("%d",&x);
			for( int j = 0; j < x; j++ )
			{
				scanf("%d",&y);
				g[ i ][ y ] = 1;
			}
		}
		int sum = hungray( );
		if( sum == n )printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
