/*
	author: AmazingCaddy
	time: 2011/3/29  21:58
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef __int64 ll;
const int maxn = 1000005;
int cnt[ maxn ];

int main(int argc, char *argv[])
{
	int cas, x, y, n, d;
	ll ans;
	scanf( "%d", &cas );
	while( cas-- )
	{
		memset( cnt, 0, sizeof( cnt ) );
		scanf( "%d %d", &d, &n );
		y = 0; cnt[ 0 ] = 1;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &x );
			cnt[ y = ( y + x ) % d ] ++;
		}
		ans = 0;
		for( int i = 0; i < d; i++ )
			if( cnt[ i ] >= 2 )
				ans = ans + (ll)cnt[ i ] * ( cnt[ i ] - 1 ) / 2;
		printf( "%d\n", ans );
	}
	return 0;
}
