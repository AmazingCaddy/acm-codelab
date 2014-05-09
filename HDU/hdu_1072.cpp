/*
	author : AmazingCaddy
	time : 2011-06-01 13:50:56 
	Tim[ x ][ y ][ tim ] 记录倒计时为 tim 时，走到( x, y ) 处
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
#define lowbit(x) ((x)&(-(x)))

const int maxn = 14;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[ ] = { 0, -1, 0, 1, -1, -1, 1, 1 };

struct node
{
	int x, y;
	int step;
	int tim;
};

int g[ maxn ][ maxn ];
int Tim[ maxn ][ maxn ][ 7 ];
int n, m;
int ans;

void BFS( int stx, int sty, int edx, int edy )
{
	queue<node> que;
	node tmp;
	tmp.x = stx, tmp.y = sty;
	tmp.step = 0, tmp.tim = 6;
	que.push( tmp );
	Tim[ stx ][ sty ][ 6 ] = 1;
	while( !que.empty( ) )
	{
		tmp = que.front( );
		que.pop( );
		if( tmp.tim == 1 ) continue;
		
		int x = tmp.x, y = tmp.y, step = tmp.step, tim = tmp.tim;
		for( int i = 0; i < 4; i++ )
		{
			int nx = x + dx[ i ], ny = y + dy[ i ];
			if( nx >= 0 && nx < n && ny >= 0 && ny < m && !Tim[ nx ][ ny ][ tim - 1 ] )
			{
				if( g[ nx ][ ny ] == 1 || g[ nx ][ ny ] == 2 )
				{
					tmp.x = nx;
					tmp.y = ny;
					tmp.step = step + 1;
					tmp.tim = tim - 1;
					Tim[ nx ][ ny ][ tim - 1 ] = 0;
					que.push( tmp );
				}
				else if( g[ nx ][ ny ] == 3 )
				{
					ans = step + 1;
					return;
				}
				else if( g[ nx ][ ny ] == 4 )
				{
					if( !Tim[ nx ][ ny ][ 6 ] )
					{
						tmp.x = nx;
						tmp.y = ny;
						tmp.step = step + 1;
						tmp.tim = 6;
						Tim[ nx ][ ny ][ 6 ] = 1;
						que.push( tmp );
					}					
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int cas;
	int stx, sty, edx, edy;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d%d", &n, &m );
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < m; j++ )
			{
				scanf( "%d", &g[ i ][ j ] );
				if( g[ i ][ j ] == 2 )
				{
					stx = i;
					sty = j;
				}
				if( g[ i ][ j ] == 3 )
				{
					edx = i;
					edy = j;
				}
			}
		}
		ans = inf;
		memset( Tim, 0, sizeof( Tim ) );
		BFS( stx, sty, edx, edy );
		if( ans == inf ) ans = -1;
		printf( "%d\n", ans );
	}
	return 0;
}
