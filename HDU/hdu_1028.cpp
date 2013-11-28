/*
	author: AmazingCaddy
	time: 2011/4/28  21:48
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
const int maxn = 128;
ll dp[ maxn ];

void init( )
{
	memset( dp, 0, sizeof( dp ) );
	dp[ 0 ] = 1;
	for( int i = 1; i <= 120; i++ )
		for( int j = i; j <= 120; j++ )
			dp[ j ] += dp[ j - i ];
}

int main(int argc, char *argv[])
{
	int n;
	init( );
	while( scanf( "%d", &n ) != EOF )
	{
		printf( "%I64d\n", dp[ n ] );
	}
	return 0;
}
