/*
	author: AmazingCaddy
	time:	2011/9/4	19:14
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

//typedef __int64 ll;
typedef long long ll;

const int maxn = 1004;

//int g[ maxn ][ maxn ];
int sum[ maxn ][ maxn ];
int np[ maxn ][ 2 ];
int X[ maxn ], Y[ maxn ];

void init( int n, int & xlen, int & ylen ) {
	sort( X, X + n );
	sort( Y, Y + n );
	xlen = unique( X, X + n ) - X;
	ylen = unique( Y, Y + n ) - Y;
	memset( sum, 0, sizeof( sum ) );
	for( int i = 0; i < n; i++ ) {
		int x = lower_bound( X, X + xlen, np[ i ][ 0 ] ) - X;
		int y = lower_bound( Y, Y + ylen, np[ i ][ 1 ] ) - Y;
		sum[ y + 1 ][ x + 1 ] = 1;
	}
	for( int i = 1; i <= ylen; i++ ) {
		int tmp = 0;
		for( int j = 1; j <= xlen; j++ ) {
			tmp += sum[ i ][ j ];
			sum[ i ][ j ] = sum[ i - 1 ][ j ] + tmp;
		}
	}
}

int main(int argc, char *argv[]) {
	int n, r;
	while( scanf( "%d%d", &n, &r ) != EOF ) {
		for( int i = 0; i < n; i++ ) {
			scanf( "%d%d", &np[ i ][ 0 ], &np[ i ][ 1 ] );
			X[ i ] = np[ i ][ 0 ];
			Y[ i ] = np[ i ][ 1 ];
		}
		int xlen, ylen;
		init( n, xlen, ylen );
		int ans = 0;
		for( int i = 1; i <= ylen; i++ ) {
			int y = upper_bound( Y, Y + ylen, Y[ i - 1 ] + r ) - Y;
			for( int j = 1; j <= xlen; j++ ) {
				int x = upper_bound( X, X + xlen, X[ j - 1 ] + r ) - X;
				int tmp = sum[ y ][ x ] - sum[ i - 1 ][ x ] - sum[ y ][ j - 1 ] + sum[ i - 1 ][ j - 1 ];
				ans = max( ans, tmp );
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}
