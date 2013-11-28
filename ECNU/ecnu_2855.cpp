#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;
 
const int maxn = 105;
const int dx[ ] = { -1, 0, 1, 0 };
const int dy[ ] = { 0, 1, 0, -1 };
const int f[ ] = { 0, 1, 1, 2, 3, 1 };
const int len = 6;
 
int H, W, T;
char g[ maxn ][ maxn ];
 
bool is_legal( int x, int y )
{
	if( x < 0 || x >= H || y < 0 || y >= W )
		return false;
	return true;
}
 
int main(int argc, char *argv[])
{
	scanf("%d%d%d",&H,&W,&T);
	for( int i = 0; i < H; i++ )
		scanf("%s",g[i]);
	int p, q;
	int x = 0, y = 0, sum = 0;
	for( int i = 0; i <= T; i++ )
	{
		if( g[ x ][ y ] != '.' )
		{
			sum += g[ x ][ y ] - '0';
			//printf("x = %d, y = %d  g[x][y] = %c\n",x,y,g[x][y]);
		}
		q = i % len;
		p = f[ q ];
		//printf("p = %d\n",p);
		while( 1 )
		{
			if( is_legal( x + dx[ p ], y + dy[ p ] ) )
				break;
			else p = ( p + 1 ) % 4;
		}
		x = x + dx[ p ], y = y + dy[ p ];
	}
	printf("%d\n",sum);
	return 0;
}
