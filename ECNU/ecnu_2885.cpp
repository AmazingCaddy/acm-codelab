/*
	author: AmazingCaddy
	time: 2011/3/27  13:09
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
using namespace std;

const int maxn = 760;
const int dx[ ] = { 0, 1, 0, -1 };
const int dy[ ] = { 1, 0, -1, 0 };

int g[ maxn ][ maxn ];
int n;

int check( int i, int j )
{
	return ( i >= 0 && i < n && j >= 0 && j < n );
}

void solve( )
{
	int nx, ny;
	memset( g, 0, sizeof( g ) );
	int m = n * n + 1, k = 1;
	int j = 0;
	nx = 0, ny = -1;
	while( k < m )
	{
		nx += dx[ j ];
		ny += dy[ j ];
		while( check( nx, ny ) && !g[ nx ][ ny ] )
		{
			g[ nx ][ ny ] = k++;
			nx += dx[ j ];
			ny += dy[ j ];
		}
		nx -= dx[ j ];
		ny -= dy[ j ];
		j = ( j + 1 ) % 4;
	}
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			if( j ) printf( " " );
			printf( "%d", g[ i ][ j ] );
		}
		printf( "\n" );
	}
}

int main(int argc, char *argv[])
{
	scanf( "%d", &n );
	solve( );
	return 0;
}
