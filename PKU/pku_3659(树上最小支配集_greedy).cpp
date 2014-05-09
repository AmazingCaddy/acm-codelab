/*
	author: AmazingCaddy
	time: 2011/5/10  14:43
	题意: 给出一棵树(无向图),让你在上面选点放塔, 
	塔覆盖范围为当前点和相邻的点,用最小的塔覆盖所有点
	
	做法: 求树上的最小支配集
	先前序遍历一次对结点进行标志,然后从n到1进行O(n)贪心.
	每次选取还没覆盖的点,在该点的父亲结点放塔.
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
int vis[ maxn ], id[ maxn ], f[ maxn ], set[ maxn ];
int head[ maxn ], e[ maxn << 1 ], next[ maxn << 1 ];
int len;

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

int num;

void DFS( int u )
{
	vis[ u ] = 1;
	id[ u ] = num++;
	for( int i = head[ u ]; i ; i = next[ i ] )
	{
		int v = e[ i ];
		if( !vis[ v ] )
		{
			DFS( v );
			f[ id[ v ] ] = id[ u ];
		}
	}
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
	num = 1;
	memset( f, 0, sizeof( f ) );
	memset( vis, 0, sizeof( vis ) );
	DFS( 1 );
	memset( set, 0, sizeof( set ) );
	memset( vis, 0, sizeof( vis ) );

	int ans = 0;
	for( int i = n; i>= 1; i-- )
	{
		if( !vis[ i ] )
		{
			if( !set[ f[ i ] ] )
			{
				ans++;
				set[ f[ i ] ] = 1;
			}
			vis[ i ] = 1;
			vis[ f[ i ] ] = 1;
			vis[ f[ f[ i ] ] ] = 1;
		}
	}

	printf( "%d\n", ans );
	return 0;
}
