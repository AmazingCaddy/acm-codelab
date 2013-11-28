/*
	author: AmazingCaddy
	time:	
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
typedef long long ll;
const int maxn = 1004;
int vis[ maxn ], dp[ maxn ];
const char * name[ ] = { "aekdycoin", "abcdxyzk" };

void solve( int n, int m ) {
	if( n < m ) {
		printf( "%s\n", name[ 1 ] );
		return;
	}
	for( int i = 0; i < m; i++ ) {
		dp[ i ] = 0;
	}
	dp[ m ] = 1;
	for( int i = m + 1; i <= n; i++ ) {
		memset( vis, 0, sizeof( vis ) );
		for( int j = 0; j + m <= i; j++ ) {
			vis[ dp[ j ] ^ dp[ i - m - j ] ] = 1;
		}
		for( int j = 0; j < maxn; j++ ) {
			if( !vis[ j ] ) {
				dp[ i ] = j;
				break;
			}
		}
	}
	printf( "%s\n", name[ dp[ n - m ] ? 1 : 0 ] );
}

int main(int argc, char *argv[]) {
	int cas, n, m;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d", &n, &m );
		printf( "Case #%d: ", t );
		solve( n, m );
	}
	return 0;
}
