/*
	author : AmazingCaddy
	time : 2011-06-01 15:17:39 
	×´Ì¬Ñ¹ËõDP
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
#define lowbit(x) ((x)&(-(x)))

const int maxn = 1 << 16;
const int inf = 0x3fffffff;

int dp[ maxn ], day[ maxn ], pre[ maxn ];
char str[ 16 ][ 105 ];
int D[ 16 ], C[ 16 ];

void print( int n, int m )
{
	if( n == 0 ) return;
	print( n ^ ( 1 << m ), pre[ n ^ ( 1 << m ) ] );
	printf( "%s\n", str[ m ] );
}

int main(int argc, char *argv[])
{
	int cas, n;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
			scanf( "%s%d%d", str[ i ], &D[ i ], &C[ i ] );
		int len = 1 << n;
		for( int i = 0; i < len; i++ ) dp[ i ] = inf;
		dp[ 0 ] = 0;
		day[ 0 ] = 0;
		for( int i = 0; i < len; i++ )
		{
			if( dp[ i ] == inf ) continue;
			for( int j = 0; j < n; j++ )
			{
				if( !( i & ( 1 << j ) ) )
				{
					int tmp = i | ( 1 << j );
					int d = day[ i ] + C[ j ];
					if( d <= D[ j ] ) 
					{
						if( dp[ tmp ] > dp[ i ] )
						{
							dp[ tmp ] = dp[ i ];
							day[ tmp ] = d;
							pre[ tmp ] = j;
						}
					}
					else 
					{
						if( dp[ tmp ] > dp[ i ] + d - D[ j ] )
						{
							dp[ tmp ] = dp[ i ] + d - D[ j ];
							day[ tmp ] = d;
							pre[ tmp ] = j;
						}
					}
				}
			}
		}
		printf( "%d\n", dp[ len - 1 ] );
		print( len - 1, pre[ len - 1 ] );
	}
	return 0;
}
