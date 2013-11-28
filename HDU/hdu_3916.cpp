/*
	author: AmazingCaddy
	time:	2011/8/6  18:39
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
typedef long long ll;

const int maxn = 10004;
const int inf = 0x3fffffff;

int a[ maxn ], b[ maxn ];

int main(int argc, char *argv[])
{
//	freopen( "data.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int cas, n;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &a[ i ] );
			b[ i ] = a[ i ];
		}
		a[ n ] = 0;
		int L = 0, R = 0, ans = n;
		while( R <= n )
		{
			while( a[ R ] <= a[ R + 1 ] && R < n ) R++;
			int delta = a[ R ] - a[ R + 1 ];
			while( a[ L ] < delta )
			{
				a[ L + 1 ] = max( 0, b[ L + 1 ] - b[ L ] );
				delta -= a[ L ];
				L++;
			}
			if( delta > 0 )
			{
				a[ L ] -= delta;
				if( R - L + 1 < ans )
					ans = R - L + 1;
			}
			R++;
		}
		printf( "%d\n", ans );
	}
	return 0;
}
