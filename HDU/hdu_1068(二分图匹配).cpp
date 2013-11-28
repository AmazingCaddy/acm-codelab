/*
	author: AmazingCaddy
	time: 2011/5/22  13:37
	二分图的最大独立集 = 节点数 - 最大匹配数
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int maxn = 1004;
int g[ maxn ][ maxn ];
int vis[ maxn ], match[ maxn ];
int n, m;

int dfs( int from )
{
	for( int i = 1; i <= m; i++ )
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
	for( int i = 1; i <= n; i++ )
	{
		memset( vis, 0, sizeof( vis ) );
		if( dfs( i ) ) sum ++;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int u, v, cnt;
	while( scanf( "%d", &n ) != EOF )
	{
		m = n;
		memset( g, 0, sizeof( g ) );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d: (%d)", &u, &cnt );
			u++;
			for( int j = 0; j < cnt; j++ )
			{
				scanf( "%d", &v );
				v++;
				g[ u ][ v ] = g[ v ][ u ] = 1;
			}
		}
		int ans = n - Hungray( ) / 2;
		printf( "%d\n", ans );
	}
	return 0;
}
