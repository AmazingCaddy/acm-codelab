/*
	author: AmazingCaddy
	time: 2011/5/10  18:03
	dp[ 0 ][ i ]
	dp[ 1 ][ i ]
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

const int maxn = 6004;

int head[ maxn ], next[ maxn ], e[ maxn ];
int val[ maxn ], vis[ maxn ];
int dp[ 2 ][ maxn ];
int len;

int Max( int a, int b ) { return ( a > b ? a : b ); }
void init( )
{
	len = 0;
	memset( head, 0, sizeof( head ) );
	memset( vis, 0, sizeof( vis ) );
}

void addedge( int u, int v )
{
	next[ ++len ] = head[ u ];
	head[ u ] = len;
	e[ len ] = v;
}

void DFS( int u )
{
	if( head[ u ] == 0 )
	{
		dp[ 0 ][ u ] = 0;			// ²»È¡
		dp[ 1 ][ u ] = val[ u ];	// È¡
		return;
	}
	int sum[ 2 ] = { 0 };
	for( int i = head[ u ]; i; i = next[ i ] )
	{
		int v = e[ i ];
		DFS( v );
		sum[ 0 ] += Max( dp[ 0 ][ v ], dp[ 1 ][ v ] );
		sum[ 1 ] += dp[ 0 ][ v ];
	}
	dp[ 0 ][ u ] = sum[ 0 ];
	dp[ 1 ][ u ] = sum[ 1 ] + val[ u ];
}

int main(int argc, char *argv[])
{
	int n, L, K;
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 1; i <= n; i++ )
			scanf( "%d", &val[ i ] );
		init( );
		while( scanf( "%d%d", &L, &K ) && ( L || K ) )
		{
			addedge( K, L );
			vis[ L ] = 1;
		}
		int root = 0;
		for( int i = 1; i <= n; i++ )
			if( !vis[ i ] ){ root = i; break; }
		DFS( root );
		printf( "%d\n", Max( dp[ 0 ][ root ], dp[ 1 ][ root ] ) );
	}
	return 0;
}
