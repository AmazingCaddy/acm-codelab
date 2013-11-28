#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;
struct node
{
	int x, y;
};
const int maxn = 1005;
const int maxm = 85;
const int dx[ ] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[ ] = { 0, 1, 0, -1, 1, 1, -1, -1 };
char g[ maxn ][ maxm ];
bool vis[ maxn ][ maxn ];
int h, w;

void bfs( int p, int q )
{
	node tmp;
	queue<node> que;
	tmp.x = p, tmp.y = q;
	que.push( tmp );
	vis[ p ][ q ] = true;
	int sum = 0;
	while( !que.empty( ) )
	{
		tmp = que.front();
		que.pop( );
		int x = tmp.x, y = tmp.y;
		for( int i = 0; i < 8; i++ )
		{
			int nx = x + dx[ i ], ny = y + dy[ i ];
			if( nx >= 0 && nx < h && ny >= 0 && ny < w )
			{
				if( !vis[ nx ][ ny ] )
				{
					vis[ nx ][ ny ] = true;
					if( g[ nx ][ ny ] == '*')
					{
						sum ++;
						tmp.x = nx, tmp.y = ny;
						que.push( tmp );
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	scanf("%d%d",&w,&h);
	for( int i = 0; i < h; i++ )
		scanf("%s",g[i]);
	memset( vis, false, sizeof( vis ) );
	int ans = 0;
	for( int i = 0; i < h; i++ )
	{
		for( int j = 0; j < w; j++ )
		{
			if( !vis[ i ][ j ] && g[ i ][ j ] == '*' )
			{
				ans++;
				bfs( i, j );
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
