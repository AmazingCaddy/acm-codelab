/*
	author: AmazingCaddy
	time: 2011/5/9  19:04
	dp0[ i ] 表示在i节点放一个士兵守住整个子树所需士兵数
	dp1[ i ] 表示守住以i为根节点的子树所需的士兵数
	
	leaf node k : dp0[ k ] = 1, dp1[ k ] = 0
	non-leaf node i :
	dp0[ i ] = 1 + sigma( dp1[ j ] ) j是i的子节点
	dp1[ i ] = Min( dp0[ i ], sigma( dp0[ j ] ) ) j是i子节点
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

const int maxn = 1504;

vector<int> g[ maxn ];
int vis[ maxn ];
int dp0[ maxn ], dp1[ maxn ];

int Min( int a, int b ) { return ( a < b ? a : b ); }

void DFS( int u )
{
	int sz = g[ u ].size( );
	if( sz == 0 )
	{
		dp0[ u ] = 1;
		dp1[ u ] = 0;
		return ;
	}
	int sum0 = 0, sum1 = 0;
	for( int i = 0; i < sz; i++ )
	{
		DFS( g[ u ][ i ] );
		sum0 += dp1[ g[ u ][ i ] ];
		sum1 += dp0[ g[ u ][ i ] ];
	}
	dp0[ u ] = 1 + sum0;
	dp1[ u ] = Min( dp0[ u ], sum1 );
}

int main(int argc, char *argv[])
{
	int n, m, a, b;
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 0; i < n; i++ )
			g[ i ].clear( );
		memset( vis, 0, sizeof( vis ) );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d:(%d)", &a, &m );
			for( int j = 0; j < m; j++ )
			{
				scanf( "%d", &b );
				g[ a ].push_back( b );
				vis[ b ] = 1;
			}
		}
		int root = -1;
		for( int i = 0; i < n; i++ )
		{
			if( !vis[ i ] )
			{
				root = i;
				break;
			}
		}
		DFS( root );
		printf( "%d\n", dp1[ root ] );
	}
	return 0;
}
