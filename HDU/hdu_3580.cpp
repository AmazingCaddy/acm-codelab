#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 53;
const double inf = 1e20;
const double eps = 1e-8;
const double pi = acos( -1.0 );
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

char M[maxn][maxn];
int n, num[30], vis[30];

bool In( int x, int y )
{
	if( x < 0 || x >= n || y < 0 || y >= n )
		return false;
	return true;
}

bool check( char c, int dx1, int dy1, int dx2, int dy2 )
{
	int signx = ( dx1 > dx2 ? -1 : 1 );
	int signy = ( dy1 > dy2 ? -1 : 1 );
	if( dx1 == dx2 ) signx = 0;
	if( dy1 == dy2 ) signy = 0;
	int x = dx1, y = dy1;
	while( 1 )
	{
		if( M[x][y] != c )
			return false;
		if( x == dx2 && y == dy2 )break;
		x += signx;
		y += signy;
	}
	return true;
}

void Count( int x, int y )
{
	int dx1, dx2, dy1, dy2;
	for( int i = 0; i < 8; i++ )
	{
		dx1 = dx2 = x, dy1 = dy2 = y;
		for( int j = 0; j < n; j++ )
		{
			dx1 += dx[i];
			dy1 += dy[i];
			dx2 += dx[(i+2)%8];
			dy2 += dy[(i+2)%8];
			if( !In( dx1, dy1 ) || !In( dx2, dy2 ) )
				break;
			if( check( M[x][y], dx1, dy1, dx2, dy2 ) )
				num[M[x][y]-'A']++;
			else break;
		}
	}
}

int main(int argc, char *argv[])
{
	int cas;
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d",&n);
		for( int i = 0; i < n; i++ )
			scanf("%s",M[i]);
		memset( vis, 0, sizeof( vis ) );
		memset( num, 0, sizeof( num ) );
		//cout<<"OK"<<endl; return 0;
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				vis[M[i][j]-'A'] = 1;
				Count( i, j );
			}
		}
		printf("Case %d:\n",t);
		for( int i = 0; i < 26; i++ )
		{
			if( vis[i] )
				printf("%c %d\n",i+'A', num[i]);
		}
	}
	return 0;
}
