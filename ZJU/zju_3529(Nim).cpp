/*
	author: AmazingCaddy
	time:	
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 5000005;

int vis[ maxn ];
//int p[ maxn ], 
//int num[ maxn ];
//int plen;

void prime( ) {
	memset( vis, 0, sizeof( vis ) );
//	plen = 0;
	for( ll i = 2, k = 4; i < maxn; ++i, k += i + i - 1 ) {
		if( !vis[ i ] ) {
			//p[ plen++ ] = i;
			if( k < maxn ) {
				for( ll j = k; j < maxn; j += i ) {
					vis[ j ] = i;
				}
			}
		}
	}
	for( int i = 2; i < maxn; i++ ) {
		if( vis[ i ] == 0 ) {
			vis[ i ] = 1;
		}
		else {
			int tmp = vis[ i ];
			vis[ i ] = vis[ i / tmp ] + 1;
		}
	}
	/*
	for( int i = 2; i < 100; i++ ) {
		printf( "%d: %d\n", i, vis[ i ] );
	}
	*/
}

int num[ 100004 ];

int main(int argc, char *argv[]){
	prime( );
	int cas = 1;
	int n, x;
	while( scanf( "%d", &n ) != EOF ) {
		int sum = 0;
		for( int i = 1; i <= n; i++ ) {
			scanf( "%d", &x );
			num[ i ] = vis[ x ];
			sum ^= num[ i ];
		}
		printf( "Test #%d: ", cas++ );
		if( sum == 0 ) {
			printf( "Bob\n" );
		}
		else {
			for( int i = 1; i <= n; i++ ) {
				if( ( sum ^ num[ i ] ) < num[ i ] ) {
					printf( "Alice %d\n", i );
					break;
				}
			}
		}
	}
	return 0;
}
