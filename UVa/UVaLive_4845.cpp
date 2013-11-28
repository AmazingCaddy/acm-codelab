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
#include <set>
using namespace std;
typedef long long ll;

const int maxn = 10004;
char str[ 10 ][ 10 ];
char pass[ 10 ][ 10 ];
set< int > hash;
int ans[ maxn ];
//char ansstr[ maxn ][ 6 ];
int len;
int tmp[ ] = { 456976, 17576, 676, 26, 1 };

void DFS( int dep, int sum ) {
	if( dep == 5 ) {
		hash.insert( sum );
		return;
	}
	for( int i = 0; i < 6; i++ ) {
		DFS( dep + 1, sum + ( str[ i ][ dep ] - 'A' ) * tmp[ dep ] );
	}
}

void dfs( int dep, int sum ) {
	if( dep == 5 ) {
		if( hash.find( sum ) != hash.end( ) ) {
			ans[ len++ ] = sum;
		}
		return;
	}
	for( int i = 0; i < 6; i++ ) {
		dfs( dep + 1, sum + ( pass[ i ][ dep ] - 'A' ) * tmp[ dep ] );
	}
}

void print( int n, int dep ) {
	if( dep == 5 ) {
		return;
	}
	print( n / 26, dep + 1 );
	printf( "%c", ( n % 26 + 'A' ) );
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int cas, k;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &k );
		for( int i = 0; i < 6; i++ ) {
			scanf( "%s", str[ i ] );
		}
		for( int i = 0; i < 6; i++ ) {
			scanf( "%s", pass[ i ] );
		}
		hash.clear( );
		DFS( 0, 0 );
		len = 0;
		dfs( 0, 0 );
		sort( ans, ans + len );
		len = unique( ans, ans + len ) - ans;
		if( len < k ) {
			puts( "NO" );
			continue;
		}
		print( ans[ k - 1 ], 0 );
		printf( "\n" );
	}
	return 0;
}
