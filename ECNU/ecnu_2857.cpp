// 经典dp 类似于最长公共子序列
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 503;
int dp[ maxn ][ maxn ];
char a[ maxn ], b[ maxn ];

int Min( int a, int b ) { return ( a < b ? a : b ); }

int main(int argc, char *argv[])
{
	int cas;
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf( "%s%s", a + 1, b + 1 );
		int n = strlen( a + 1 ), m = strlen( b + 1 );
		memset( dp, 0, sizeof( dp ) );
		for( int i = 1; i <= n; i++ )
			dp[ i ][ 0 ] = i;
		for( int j = 1; j <= m; j++ )
			dp[ 0 ][ j ] = j;
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= m; j++ )
			{
				if( a[ i ] == b[ j ] )
					dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ];
				else
					dp[ i ][ j ] = Min( Min( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] ),
						dp[ i - 1 ][ j - 1 ] ) + 1;
			}
		}
		printf("%d\n",dp[ n ][ m ] );
	}
	return 0;
}
