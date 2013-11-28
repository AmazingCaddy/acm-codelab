#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 1003;
int dp[ maxn ][ maxn ];

int main(int argc, char *argv[])
{
	int H, W, cas;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d%d" , &H, &W );
		memset( dp, 0, sizeof( dp ) );
		int ans = 0;
		for( int i = 0; i < H; i++ )
			for( int j = 0; j < W; j++ )
				if( ( i < 2 || !dp[ i - 2 ][ j ] ) &&
					( j < 2 || !dp[ i ][ j - 2 ] ) )
					dp[ i ][ j ] = 1, ans++;
		printf( "%d\n", ans );
	}
	return 0;
}
