/*
    author: AmazingCaddy
    time: 26/05/2011 21:01:37 
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

const int maxn = 20;

const int dx[ ] = { 0, 0, 1, 1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 1, 0, 0, -1, 1, 1, -1 };

int h[ maxn ][ maxn ];
int v[ maxn ][ maxn ];

int check( int p, int q, int n )
{
	int st[ 4 ][ 2 ];
	st[ 0 ][ 0 ] = p;		 st[ 0 ][ 1 ] = q;
	st[ 1 ][ 0 ] = p + n;	 st[ 1 ][ 1 ] = q;
	st[ 2 ][ 0 ] = p;		 st[ 2 ][ 1 ] = q;
	st[ 3 ][ 0 ] = p;		 st[ 3 ][ 1 ] = q + n;
	for( int i = 0; i < 4; i++ )
	{
		int x = st[ i ][ 0 ], y = st[ i ][ 1 ];
		if( i < 2 )
		{
			for( int j = 0; j < n; j++ )
			{
				if( !h[ x ][ y ] ) return 0;
				y++;
			}
		}
		else
		{
			for( int j = 0; j < n; j++ )
			{
				if( !v[ y ][ x ] ) return 0;
				x++;
			}
		}
	}
	return 1;
}

int main( int ac, char * av[ ] )
{
	//freopen( "te.txt", "r", stdin );
	int n, m, t = 1;
	char ch[ 10 ];
	int x, y;
	while( scanf( "%d%d", &n, &m ) != EOF )
	{
		if( t > 1 ) printf( "\n**********************************\n\n" );
		memset( h, 0, sizeof( h ) );
		memset( v, 0, sizeof( v ) );
		for( int i = 0; i < m; i++ )
		{
			scanf( "%s%d%d", ch, &x, &y );
			if( ch[ 0 ] == 'H' ) h[ x ][ y ] = 1;
			else v[ x ][ y ] = 1;
		}
		printf( "Problem #%d\n\n", t++ );
		int flag = 0;
		for( int i = 1; i < n; i++ )
		{
			int cnt = 0;
			for( int j = 1; j <= n - i; j++ )
			{
				for( int k = 1; k <= n - i; k++ )
				{
					if( check( j, k, i ) ) cnt++;
				}
			}
			if( cnt ) 
			{
				flag = 1;
				printf( "%d square (s) of size %d\n", cnt, i );
			}
		}
		if( !flag ) printf( "No completed squares can be found.\n" );
	}
	return 0;
}
