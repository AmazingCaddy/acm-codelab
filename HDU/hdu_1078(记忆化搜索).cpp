/*
	author : AmazingCaddy
	time : 2011-06-02 16:31:15 
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

const int maxn = 104;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[ ] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int sum[ maxn ][ maxn ], g[ maxn ][ maxn ];
int n, k;

int Max( int a, int b ) { return ( a > b ? a : b ); }

int DFS( int ii, int jj )
{
	if( sum[ ii ][ jj ] != -1 ) return sum[ ii ][ jj ];
	int res = 0;
	for( int i = 1; i <= k; i++ )
	{
		for( int j = 0; j < 4; j++ )
		{
			int x = ii + i * dx[ j ];
			int y = jj + i * dy[ j ];
			if( x < n && x >= 0 && y < n && y >= 0 && g[ x ][ y ] > g[ ii ][ jj ] )
				res = Max( res, DFS( x, y ) );
		}
	}
	return sum[ ii ][ jj ] = res + g[ ii ][ jj ];
}

int main(int argc, char *argv[])
{
	while( 1 )
	{
		scanf( "%d%d", &n, &k );
		if( n == -1 && k == -1 ) break;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				scanf( "%d", &g[ i ][ j ] );
		memset( sum, -1, sizeof( sum ) );
		int ans = DFS( 0, 0 );
		printf( "%d\n", ans );
	}
	return 0;
}
