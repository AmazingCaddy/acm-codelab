/*
	author: AmazingCaddy
	time:	2011/7/11  20:11
	dp[ i ][ j ]表示i条直线可以形成j个交点
	dp[ i - r ][ j ] = 1 -> dp[ i ][ j + ( i - r ) * r ] = 1
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
#include <queue>
using namespace std;

const int maxn = 24;
int dp[ maxn ][ maxn * maxn ];

int main(int argc, char *argv[])
{
	int n;
	memset( dp, 0, sizeof( dp ) );
	dp[ 0 ][ 0 ] = dp[ 1 ][ 0 ] = 1;
	for( int i = 2; i < 21; i++ )
	{
		dp[ i ][ 0 ] = 1;
		for( int r = 1; r < i; r++ )
		{
			for( int j = 0; j < 191; j++ )
			{
				if( dp[ i - r ][ j ] )
					dp[ i ][ j + ( i - r ) * r ] = 1;
			}
		}
	}
	while( scanf( "%d", &n ) != EOF )
	{
		printf( "0" );
		for( int i = 1; i <= 191; i++ )
			if( dp[ n ][ i ] ) printf( " %d", i );
		printf( "\n" );
	}
	return 0;
}
