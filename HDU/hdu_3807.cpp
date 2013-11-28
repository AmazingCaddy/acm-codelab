/*
	author: AmazingCaddy
	time: 2011/3/27  14:07
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
const int maxn = 25;

int cnt[ maxn ];

int main(int argc, char *argv[])
{
	int cas, n, x, A, B;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d", &n );
		memset( cnt, 0, sizeof( cnt ) );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &x );
			cnt[ x ]++;
		}
		scanf( "%d%d", &A, &B );
		int l, r, flag = 0;
		for( int i = 1; i <= n; i++ )
		{
			if( cnt[ i ] >= i - A && cnt[ i ] <= i + B )
			{
				if( flag ) printf( " " );
				else flag = 1;
				printf( "%d", i );
			}
		}
		if( !flag ) printf( "impossible" );
		printf( "\n" );
	}
	return 0;
}
