#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 1005;
int beat[ maxn ][ maxn ], meet[ maxn ][ maxn ];
int win[ maxn >> 1 ];

int main(int argc, char *argv[])
{
	int n, x;
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				scanf("%d",&x);
				beat[ i ][ j ] = beat[ i + n ][ j + n ] = x;
				beat[ i + n ][ j ] = beat[ i ][ j + n ] = x;
			}
		}

		for( int i = 0; i < 2 * n; i++ )
			meet[ i ][ i + 1 ] = 1;
		for( int k = 2; k <= n; k++ )	// 表示间隔的人数
		{
			for( int i = 0; i < 2 * n - k; i++ )
			{
				int j = i + k;
				for( int p = i + 1; p < j; p++ )
				{
					if( meet[ i ][ p ] && meet[ p ][ j ] 
						&& ( beat[ i ][ p ] || beat[ j ][ p ] ) )
					{
						meet[ i ][ j ] = 1;
						break;
					}
				}
			}
		}
		int len = 0;
		for( int i = 0; i < n; i++ )
			if( meet[ i ][ i + n ] )
				win[ len++ ] = i + 1;
		printf("%d\n",len);
		for( int i = 0; i < len; i++ )
			printf("%d\n",win[ i ]);
	}
	return 0;
}
