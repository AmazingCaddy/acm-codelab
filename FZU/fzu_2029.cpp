/*
	author: AmazingCaddy
	Time: 
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 504;
const int inf = 1000000000;
const int dx[ ] = { 0, 1, 0, -1 };
const int dy[ ] = { 1, 0, -1, 0 };

struct node
{
	int x, y;
	int step;
};

struct NODE
{
	int x, y;
	NODE( ) { };
	NODE( int _x, int _y ) : x( _x ), y( _y ) { }
};

char g[ maxn ][ maxn ];
int Time[ maxn ][ maxn ];
int n, m;
vector<NODE> v[ maxn * maxn ];

void BFS( int stx, int sty )
{
	queue<node> que;
	node tmp;
	tmp.x = stx;
	tmp.y = sty;
	tmp.step = 0;
	que.push( tmp );
	Time[ stx ][ sty ] = 0;
	while( !que.empty( ) )
	{
		tmp = que.front( );
		que.pop( );
		int x = tmp.x, y = tmp.y, step = tmp.step;
		int nx, ny;
		for( int i = 0; i < 4; i++ )
		{
			nx = x + dx[ i ], ny = y + dy[ i ];
			if( nx < n && nx >= 0 && ny < m && ny >= 0 )
			{
				if( g[ nx ][ ny ] != '#' )
				{
					if( step + 1 < Time[ nx ][ ny ] )
					{
						tmp.x = nx;
						tmp.y = ny;
						tmp.step = step + 1;
						que.push( tmp );
						Time[ nx ][ ny ] = step + 1;
					}
				}
			}
		}
		int t = x * n + y;
		for( int i = 0; i < v[ t ].size( ); i++ )
		{
			nx = v[ t ][ i ].x;
			ny = v[ t ][ i ].y;
			if( step + 1 < Time[ nx ][ ny ] )
			{
				tmp.x = nx;
				tmp.y = ny;
				tmp.step = step + 1;
				Time[ nx ][ ny ] = step + 1;
				que.push( tmp );
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int stx, sty, dex, dey;
	int x, y, k, t;
	while( scanf( "%d%d", &n, &m ) != EOF )
	{
		for( int i = 0; i < maxn * maxn; i++ )
			v[ i ].clear( );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", g[ i ] );
			for( int j = 0; j < m; j++ )
			{
				if( g[ i ][ j ] == 's' ) stx = i, sty = j;
				if( g[ i ][ j ] == 't' ) dex = i, dey = j;
			}
		}
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < m; j++ )
			{
				scanf( "%d", &k );
				t = i * n + j;
				for( int p = 0; p < k; p++ )
				{
					scanf( "%d%d", &x, &y );
					x--;
					y--;
					v[ t ].push_back( NODE( x, y ) );
				}
			}
		}
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				Time[ i ][ j ] = inf;

		BFS( stx, sty );
		printf( "%d\n", Time[ dex ][ dey ] );

	}
	return 0;
}
