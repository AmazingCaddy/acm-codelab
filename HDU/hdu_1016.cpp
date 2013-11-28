/*
	author: AmazingCaddy
	time: 
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
const int maxn = 104;
int vis[ maxn ];
int buf[ maxn ];
int num[ maxn ];
int mk[ maxn ];
int n;

void prime( )
{
	memset( vis, 0, sizeof( vis ) );
	int i, j, k;
	for( vis[ 0 ] = vis[ 1 ] = 1, i = 2, k = 4; i < maxn; i++, k += i + i - 1 )
		if( !vis[ i ] && k < maxn )
			for( j = k; j < maxn; j += i ) vis[ j ] = 1;
}
void init( )
{
	prime( );
	for( int i = 0; i < 21; i++ )
		num[ i ] = i + 1;
}

void DFS( int dep )
{
	if( dep == n )
	{	
		if( !vis[ buf[ dep - 1 ] + buf[ 0 ] ] )
		{
			for( int i = 0; i < dep; i++ )
			{
				if( i ) printf( " " );
				printf( "%d", buf[ i ] );
			}
			printf( "\n" );
		
		}
		return ;
	}
	for( int i = 1; i < n; i++ )
	{
		if( !mk[ i ] && !vis[ num[ i ] + buf[ dep - 1 ] ] )
		{
			mk[ i ] = 1;
			buf[ dep ] = num[ i ];
			DFS( dep + 1 );
			mk[ i ] = 0;
		}
	}
}

int main(int argc, char *argv[])
{
	init( );
	int k = 1;
	while( scanf( "%d", &n ) != EOF )
	{
		printf( "Case %d:\n", k++ );
		memset( mk, 0, sizeof( mk ) );
		buf[ 0 ] = 1;
		DFS( 1 );
		printf( "\n" );
	}
	return 0;
}
