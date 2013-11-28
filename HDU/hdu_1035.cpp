/*
    author: AmazingCaddy
    time: 16/05/2011 19:42:16 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 24;

const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

char g[ maxn ][ maxn ];
int step[ maxn ][ maxn ];

int DIR( char ch )
{
	switch( ch )
	{
	case 'E': return 0;
	case 'S': return 1;
	case 'W': return 2;
	case 'N': return 3;
	}
	return -1;
}

int main( int ac, char * av[ ] )
{
	int r, c, st, x, y;
	while( 1 )
	{
		scanf( "%d%d", &r, &c );
		if( r == 0 && c == 0 ) break;
		scanf( "%d", &st );
		for( int i = 1; i <= r; i++ )
			scanf( "%s", g[ i ] + 1 );
		memset( step, 0, sizeof( step ) );
		x = 1, y = st;
		step[ x ][ y ] = 1;
		int aa, bb, cnt = 1, flag;
		while( 1 )
		{
			int dir = DIR( g[ x ][ y ] );
			x += dx[ dir ];
			y += dy[ dir ];
			//printf( "dir = %d ( %d, %d )\n", dir, x, y );
			cnt++;
			if( x > r || x < 1 || y > c || y < 1 )
			{
				aa = cnt;
				flag = 1;
				break;
			}
			if( step[ x ][ y ] )
			{
				aa = step[ x ][ y ];
				bb = cnt - aa;
				flag = 0;
				break;
			}
			step[ x ][ y ] = cnt;
		}
		if( flag )
		{
			printf( "%d step(s) to exit\n", aa - 1 );
		}
		else
		{
			printf( "%d step(s) before a loop of %d step(s)\n", aa - 1, bb );
		}
	}
	return 0;
}
