/*
	author: AmazingCaddy
	time: 2011/3/12  15:34
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

typedef __int64 ll;

const int maxn = 1300000;
int vis[ maxn ], p[ maxn / 10 ];
int plen;

void prime( )
{
	ll i, j, k;
	memset( vis, 0, sizeof( vis ) );
	for( vis[ 1 ] = 1, plen = 0, i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			p[ plen++ ] = i;
			if( k < maxn ) for( j = k; j < maxn; j += i ) vis[ j ] = 1;
		}
	}
}

int main(int argc, char *argv[])
{
	prime( );
	int n;
	while( scanf( "%d", &n ) && n )
	{
		if( !vis[ n ] ) printf( "0\n" );
		else
		{
			int pid = lower_bound( p, p + plen, n ) - p;
			printf( "%d\n", p[ pid ] - p[ pid - 1 ] );
		}
	}
	return 0;
}
