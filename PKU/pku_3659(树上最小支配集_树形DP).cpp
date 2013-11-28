/*
	author: AmazingCaddy
	time: 2011/5/10  14:43
	题意: 给出一棵树(无向图),让你在上面选点放塔, 
	塔覆盖范围为当前点和相邻的点,用最小的塔覆盖所有点
	
	做法: 求树上的最小支配集 树形DP
	dp[ i ][ 0 ], 表示该点不放塔, 且被祖先结点覆盖
	dp[ i ][ 1 ], 表示该点不放塔, 不被祖先覆盖
	dp[ i ][ 2 ], 放塔

	u为i的子结点dp[ i ][ 0 ] = sum( min( dp[ u ][ 1 ], dp[ u ][ 2 ] ) );
	dp[ i ][ 2 ] = sum( min( dp[ u ][ 0 ], dp[ u ][ 2 ] ) ) + 1;
	dp[ i ][ 1 ] 如果其子节点中至少有一个点是放塔, 即存在 dp[ u ][ 2 ] <= dp[ u ][ 1 ] 
	那么 dp[ i ][ 1 ] = sum( min( dp[ u ][ 1 ], dp[ u ][ 2 ] ) );
	否则 枚举其中一个子结点, 在该结点放塔( dp[ u ][ 2 ] ),其他仍保持dp[ u ][ 1 ]状态
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

const int maxn = 10004;
const int inf  = 10000000;

int vis[ maxn ], id[ maxn ], f[ maxn ], set[ maxn ];
int head[ maxn ], e[ maxn << 1 ], next[ maxn << 1 ];
int len;
int dp[ maxn ][ 3 ];

void init( )
{
	len = 0;
	memset( head, 0, sizeof( head ) );
}

void add( int u, int v )
{
	next[ ++len ] = head[ u ];
	head[ u ] = len;
	e[ len ] = v;
}

int Min( int a, int b ) { return ( a < b ? a : b ); }

void DFS( int u )
{
	vis[ u ] = 1;
	if( head[ u ] == 0 )
	{
		dp[ u ][ 0 ] = 0;
		dp[ u ][ 1 ] = inf;
		dp[ u ][ 2 ] = 1;
		return;
	}
	int sum[ 3 ] = { 0 }, off = inf;
	for( int i = head[ u ]; i ; i = next[ i ] )
	{
		int v = e[ i ];
		if( !vis[ v ] )
		{
			DFS( v );
			sum[ 0 ] += Min( dp[ v ][ 1 ], dp[ v ][ 2 ] );
			sum[ 2 ] += Min( dp[ v ][ 0 ], dp[ v ][ 2 ] );
			off = Min( off, dp[ v ][ 2 ] - dp[ v ][ 1 ] );
			// 最后off <= 0 则存在 dp[ v ][ 2 ] <= dp[ v ][ 1 ]
		}
	}
	dp[ u ][ 0 ] = sum[ 0 ];
	dp[ u ][ 1 ] = sum[ 0 ];
	dp[ u ][ 2 ] = sum[ 2 ] + 1;
	if( off > 0 ) dp[ u ][ 1 ] = sum[ 0 ] + off;
}

int main(int argc, char *argv[])
{
	int u, v, n;
	scanf( "%d", &n );
	init( );
	for( int i = 1; i < n; i++ )
	{
		scanf( "%d%d", &u, &v );
		add( u, v );
		add( v, u );
	}
	DFS( 1 );
	printf( "%d\n", Min( dp[ 1 ][ 1 ], dp[ 1 ][ 2 ] ) );
	return 0;
}
