/*
	author: AmazingCaddy
	time: 2011/4/11  20:22
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
const int maxn = 102;
const int inf = 100000000;
const int dx[ ] = { 0, 1, 0, -1 };
const int dy[ ] = { 1, 0, -1, 0 };

struct node
{
	int x, y;
	int time;
};

struct PATH_INFOR
{
	int x, y;
	int time;
};
PATH_INFOR path[ maxn ][ maxn ];
char maps[ maxn ][ maxn ];
int N, M;

void BFS( int p, int q )
{
	int x, y, nx, ny, time;
	queue<node> que;
	node tmp;
	tmp.x = p, tmp.y = q;
	if( maps[ p ][ q ] == '.' ) tmp.time = 0;
    else tmp.time = maps[ p ][ q ] - '0';
	que.push( tmp );
	path[ p ][ q ].time = tmp.time;
	while( !que.empty( ) )
	{
		tmp = que.front( );
		que.pop( );
		x = tmp.x, y = tmp.y, time = tmp.time;
		if( x == 0 && y == 0 )
		{
			if( time < path[ 0 ][ 0 ].time )
				path[ 0 ][ 0 ].time = time;
		}
		for( int i = 0; i < 4; i++ )
		{
			nx = x + dx[ i ];
			ny = y + dy[ i ];
			if( nx >= 0 && nx < N && ny >= 0 && ny < M )
			{
				if( maps[ nx ][ ny ] == '.' )
				{
					if( time + 1 < path[ nx ][ ny ].time )
					{
						tmp.x = nx;
						tmp.y = ny;
						tmp.time = time + 1;
						path[ nx ][ ny ].x = x;
						path[ nx ][ ny ].y = y;
						path[ nx ][ ny ].time = time + 1;
						que.push( tmp );
					}
				}
				else if( maps[ nx ][ ny ] != 'X' )
				{
					int t = maps[ nx ][ ny ] - '0' + 1;
					if( time + t < path[ nx ][ ny ].time )
					{
						tmp.x = nx;
						tmp.y = ny;
						tmp.time = time + t;
						path[ nx ][ ny ].x = x;
						path[ nx ][ ny ].y = y;
						path[ nx ][ ny ].time = time + t;
						que.push( tmp );
					}
				}
			}
		}
	}
}

void print( int i, int j, int t )
{
	int p, q, k;
    if( maps[ i ][ j ] >= '1' && maps[ i ][ j ] <= '9' )
    {
       k = maps[ i ][ j ] - '0';
        while( k-- ) printf( "%ds:FIGHT AT (%d,%d)\n", t++, i, j );
    }
    while( !( i == N - 1 && j == M - 1 ) )
    {
        if( maps[ i ][ j ] >= '1' && maps[ i ][ j ] <= '9' )
        {
            k = maps[ i ][ j ] - '0';
            while( k-- ) printf( "%ds:FIGHT AT (%d,%d)\n", t++, i, j );
            printf( "%ds:(%d,%d)->(%d,%d)\n", t++, i, j, path[ i ][ j ].x, path[ i ][ j ].y );
        }
        else
        {
			printf( "%ds:(%d,%d)->(%d,%d)\n", t++, i, j, path[ i ][ j ].x, path[ i ][ j ].y );
        }
        p = path[ i ][ j ].x;
        q = path[ i ][ j ].y;
        i = p;
        j = q;
    }
    if( maps[ i ][ j ] >= '1' && maps[ i ][ j ] <= '9' )
    {
        k = maps[ i ][ j ] - '0';
        while( k-- ) printf( "%ds:FIGHT AT (%d,%d)\n", t++, i, j );
    }
}

int main(int argc, char *argv[])
{
	while( scanf( "%d%d", &N, &M ) != EOF )
	{
		for( int i = 0; i < N; i++ )
			scanf( "%s", maps[ i ] );
		if( maps[ N - 1 ][ M - 1 ] == 'X' || maps[ 0 ][ 0 ] == 'X' )
		{
			printf( "God please help our poor hero.\nFINISH\n" );
			continue;
		}
		for( int i = 0; i < N; i++ )
		{
			for( int j = 0; j < M; j++ )
			{
				path[ i ][ j ].time = inf;
				path[ i ][ j ].x = i;
				path[ i ][ j ].y = j;
			}
		}
		BFS( N - 1, M - 1 );
		if( path[ 0 ][ 0 ].time == inf )
		{
			printf( "God please help our poor hero.\n" );
		}
		else
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",path[0][0].time);
            print( 0, 0, 1 );
		}
		printf( "FINISH\n" );
	}
	return 0;
}
