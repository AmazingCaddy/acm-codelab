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
#include <queue>
using namespace std;

typedef __int64 ll;

const int maxn = 1002000;
int vis[ maxn ], p[ maxn ];
int plen;

void prime( )
{
	ll i, j, k;
	plen = 1;
	p[ 0 ] = -10000;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			p[ plen++ ] = i;
			if( k < maxn )
				for( j = k; j < maxn; j += i )
					vis[ j ] = 1;
		}
	}
}

int main(int argc, char *argv[])
{
	//freopen( "1842#1.in", "r", stdin );
	//freopen( "out", "w", stdout );
	prime( );
	//for( int i = 1; i < 100; i++ )
	//	printf( "%d\n", p[ i ] );
	int cas, k, ans;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &k );
		int len = lower_bound( p, p + plen, k ) - p;
		if( p[ len ] == k ) ans = k;
		else 
		{
			if( k - p[ len - 1 ] <= p[ len ] - k )
				ans = p[ len - 1 ];
			else ans = p[ len ];
		}
		printf( "%d\n", ans );
	}
	return 0;
}
