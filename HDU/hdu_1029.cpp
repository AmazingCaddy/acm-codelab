/*
	author: AmazingCaddy
	time: 2011/4/29  20:38
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
const int maxn = 1000006;
map<int, int> mm;
int cnt[ maxn ];
int num[ maxn ];

int main(int argc, char *argv[])
{
	int n, x;
	while( scanf( "%d", &n ) != EOF )
	{
		memset( cnt, 0, sizeof( cnt ) );
		mm.clear( );
		int len = 1;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &x );
			if( mm[ x ] == 0 )
			{
				mm[ x ] = len;
				num[ len++ ] = x;
			}
			cnt[ mm[ x ] ]++;
		}
		int ans = 0, k = 0;
		for( int i = 1; i < len; i++ )
			if( ans < cnt[ i ] )
				ans = cnt[ i ], k = i;
		printf( "%d\n", num[ k ] );
	}
	return 0;
}
