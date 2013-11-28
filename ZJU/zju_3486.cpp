/*
	author: AmazingCaddy
	time: 2011/4/3  13:39
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
const int maxn = 10004;
int cnt[ maxn ];
int main(int argc, char *argv[])
{
	int cas, n, x;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		memset( cnt, 0, sizeof( cnt ) );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &x );
			cnt[ x ]++;
		}
		int ans = 0, ID = -1;
		for( int i = 1001; i < 10000; i++ )
			if( cnt[ i ] >= ans )
				ans = cnt[ i ], ID = i;
		printf( "%d\n", ID );
	}
	return 0;
}
