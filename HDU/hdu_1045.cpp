/*
    author: AmazingCaddy
    time: 18/05/2011 18:53:40 
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

const int maxn = 10;
const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

char g[ maxn ][ maxn ];
int ans, n;

int put( int x, int y )
{
	if( g[ x ][ y ] != '.' ) return 0;
	for( int i = x - 1; i >= 0; i-- )
	{
		if( g[ i ][ y ] == 'X' ) break;
		if( g[ i ][ y ] == 'O' ) return 0;
	}
	for( int j = y - 1; j >= 0; j-- )
	{
		if( g[ x ][ j ] == 'X' ) break;
		if( g[ x ][ j ] == 'O' ) return 0;
	}
	return 1;
}

void DFS( int pos, int dep )
{
	if( pos == n * n )
	{
		if( dep > ans ) ans = dep;
		return;
	}
	int x = pos / n;
	int y = pos % n;
	if( put( x, y ) )
	{
		g[ x ][ y ] = 'O';
		DFS( pos + 1, dep + 1 );
		g[ x ][ y ] = '.';		
	}
	DFS( pos + 1, dep );
}

int main( int ac, char * av[ ] )
{
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%s", g[ i ] );
		ans = 0;
		DFS( 0, 0 );
		printf( "%d\n", ans );
	}
	return 0;
}
