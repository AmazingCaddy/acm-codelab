/*
	author: AmazingCaddy
	time: 2011/3/27  15:46
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
const int maxn = 20005;
int vis[ maxn ], p[ maxn ];
int plen;

void prime( )
{
	int i, j, k;
	memset( vis, 0, sizeof( vis ) );
	for( vis[ 0 ] = vis[ 1 ] = 1, i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			if( k < maxn ) for( j = k; j < maxn; j += i ) vis[ j ] = 1;
		}
	}
}

void solve( int n, int &a, int &b )
{
	a = b = n / 2;
	while( vis[ a ] || vis[ b ] ) a--, b++;
}

int main(int argc, char *argv[])
{
	int n, a, b;
	prime( );
	while( scanf( "%d", &n ) != EOF )
	{
		solve( n, a, b );
		printf( "%d %d\n", a, b );
	}
	return 0;
}
