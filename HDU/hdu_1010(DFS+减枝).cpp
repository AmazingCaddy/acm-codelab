/*
	author: AmazingCaddy
	time: 2011/4/2  12:40 - 14:19
	DFS + 减枝
	剪掉的条件是，如果可走地板数目小于给定的时间，绝对不可能得救。
	还有就是狗走到门的时间必须和题目给定的时间是同奇同偶的，
	否则也不能在指定的那秒到达门，也不可能得救，剪掉这两种情况后。
	就用DFS来做。从起点出发，DFS周围的路，走过的路就标记为不可走，
	一只搜索下去，如果是一条不归路（就是活不了啦）就回溯，
	把可能的路都搜索一遍过去，看看是否有可行方案。
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
const int dx[ ] = { 0, 1, 0, -1 };
const int dy[ ] = { 1, 0, -1, 0 };
const int maxn = 10;
int n, m, s;
int srcx, srcy, dstx, dsty;
int vis[ maxn ][ maxn ];
char g[ maxn ][ maxn ];

int flag;
void DFS( int p, int q, int dep )
{
	if( p == dstx && q == dsty && dep == s )
	{
		flag = 1;
		return;
	}
	if( dep > s ) return;
	if( ( abs( p - dstx ) + abs( q - dsty ) ) % 2 != ( s - dep ) % 2 ) return;
	int nx, ny;
	for( int i = 0; i < 4; i++ )
	{
		nx = p + dx[ i ];
		ny = q + dy[ i ];
		if( p < n && p >= 0 && q < m && q >= 0 && g[ nx ][ ny ] != 'X' )
		{
			g[ nx ][ ny ] = 'X';
			DFS( nx, ny, dep + 1 );
			if( flag ) return;
			g[ nx ][ ny ] = '.';
		}
	}
}

int main(int argc, char *argv[])
{
	while( 1 )
	{
		scanf( "%d %d %d", &n, &m, &s );
		if( n == 0 && m == 0 && s == 0 ) break;

		for( int i = 0; i < n; i++ )
			scanf( "%s", g[ i ] );
		int cnt = 0;
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < m; j++ )
			{
				if( g[ i ][ j ] == '.' )cnt++;
				else if( g[ i ][ j ] == 'S' ) srcx = i, srcy = j;
				else if( g[ i ][ j ] == 'D' ) dstx = i, dsty = j, cnt++;
			}
		}
		if( cnt < s ) printf( "NO\n" );
		else 
		{
			flag = 0;
			g[ srcx ][ srcy ] = 'X';
			DFS( srcx, srcy, 0 );
			if( flag ) printf( "YES\n" );
			else printf( "NO\n" );
		}
	}
	return 0;
}

/*
3 2 3
SX
.X
.D
*/
