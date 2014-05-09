/*
	author: AmazingCaddy
	time: 2011/4/3  18:28
	dp[ i ] 记录前i个字符要删除的最小个数
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
const int maxn = 1003;
const int inf = 1 << 30;
int dp[ maxn ];
int W, L;
char buf[ maxn ];
char text[ 605 ][ 30 ];
int len[ 605 ];

void gao( int pos, int k )
{
	int cnt = 0, flag = 0;
	for( int i = pos; i < L; i++ )
	{
		if( buf[ i ] == text[ k ][ cnt ] ) cnt++;
		if( cnt >= len[ k ] ) { flag = i; break; }
	}
	if( cnt == len[ k ] )
	{
		int p = flag - pos + 1;
		if( dp[ pos ] + p - len[ k ] < dp[ pos + p ] )
			dp[ pos + p ] = dp[ pos ] + p - len[ k ];
	}
}

int main(int argc, char *argv[])
{
	scanf( "%d %d", &W, &L );
	scanf( "%s", buf );
	for( int i = 0; i < W; i++ )
	{
		scanf( "%s", text[ i ] );
		len[ i ] = strlen( text[ i ] );
	}
	for( int i = 0; i <= L; i++ )
		dp[ i ] = inf;

	dp[ 0 ] = 0;
	for( int i = 0; i < L; i++ )
	{
		for( int j = 0; j < W; j++ )
		{
			if( text[ j ][ 0 ] == buf[ i ] )
			{
				if( i + len[ j ] <= L ) gao( i, j );
			}
			if( dp[ i ] + 1 < dp[ i + 1 ] ) dp[ i + 1 ] = dp[ i ] + 1;
		}
	}
	printf( "%d\n", dp[ L ] );
	return 0;
}
