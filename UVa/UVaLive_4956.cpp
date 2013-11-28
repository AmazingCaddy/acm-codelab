/*
	author: AmazingCaddy
	time:	
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
typedef long long ll;

const int maxn = 1004;
int a[ maxn ][ maxn ], b[ maxn ][ maxn ];
int ar[ maxn ], ac[ maxn ], br[ maxn ], bc[ maxn ];
int n;

bool check( ) {
	int sum;
	for( int i = 0; i < n; i++ ) {
		sum = 0;
		for( int j = 0; j < n; j++ ) {
			sum = sum + a[ i ][ j ] * ar[ j ];
		}
		if( sum != br[ i ] ) {
			return false;
		}
	}
	for( int j = 0; j < n; j++ ) {
		sum = 0;
		for( int i = 0; i < n; i++ ) {
			sum = sum + ac[ i ] * a[ i ][ j ];
		}
		if( sum != bc[ j ] ) {
			return false;
		}
	}
	int cnt = 1000;
	while( cnt -- ) {
		int x = rand( ) % n, y = rand( ) % n;
		sum = 0;
		for( int i = 0; i < n; i++ ) {
			sum = sum + a[ x ][ i ] * a[ i ][ y ];
		}
		if( sum != b[ x ][ y ] ) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	srand( ( unsigned ) time ( NULL ) );
	while( scanf( "%d", &n ) && n ) {
		memset( ar, 0, sizeof( ar ) );
		memset( ac, 0, sizeof( ac ) );
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < n; j++ ) {
				scanf( "%d", &a[ i ][ j ] );
				ar[ i ] += a[ i ][ j ];
				ac[ j ] += a[ i ][ j ];
			}
		}
		memset( br, 0, sizeof( br ) );
		memset( bc, 0, sizeof( bc ) );
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < n; j++ ) {
				scanf( "%d", &b[ i ][ j ] );
				br[ i ] += b[ i ][ j ];
				bc[ j ] += b[ i ][ j ];
			}
		}
		if( !check( ) ) {
			printf( "NO\n" );
			continue;
		}
		printf( "YES\n" );
	}
	return 0;
}
