/*
	author: AmazingCaddy
	time:	
	solve:	
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

map< string, int > name;
char role[ 10 ][ 30 ];
char buf[ 30 ];
int num[ 10 ];
int beat[ 10 ][ 10 ];

bool check( int n ) {
	int opp[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	do {
		int my = n, your = n;
		for( int i = 0, j = 0; i < n && j < n; ) {
			if( beat[ opp[ i ] ][ num[ j ] ] ) {
				my--;
				j++;
				if( my == 0 ) {
					return false;
				}
			}
			else {
				i++;
				your--;
			}
		}
	}while( next_permutation( opp, opp + n ) );
	return true;
}

int main(int argc, char *argv[]){
//	freopen( "out.txt", "w", stdout );
	int cas, n;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &n );
		name.clear();
		for( int i = 0; i < n; i++ ) {
			scanf( "%s", buf );
			name[ buf ] = 1;
		}
		int len = 1;
		for( map< string, int >::iterator iter = name.begin(); iter != name.end(); iter++ ) {
			iter -> second = len;
			strcpy( role[ len ], iter -> first.c_str( ) );
			len++;
		}
		/*
		for( int i = 1; i <= n; i++ ) {
			printf( "%s\n", role[ i ] );
		}
		*/
		memset( beat, 0, sizeof( beat ) );
		int k;
		for( int i = 1; i <= n; i++ ) {
			scanf( "%d", &k );
			for( int j = 0; j < k; j++ ) {
				scanf( "%s", buf );
				beat[ i ][ name[ buf ] ] = 1;
			}
		}
		for( int i = 0; i < n; i++ ) {
			num[ i ] = i + 1;
		}
		printf( "Case %d: ", t );
		int flag = 0;
		do {
			if( check( n ) ) {
				printf( "Yes\n" );
				for( int i = 0; i < n; i++ ) {
					if( i ) {
						printf( " " );
					}
					printf( "%s", role[ num[ i ] ] );
				}
				printf( "\n" );
				flag = 1;
				break;
			}
		} while ( next_permutation( num, num + n ) );
		if( !flag ) {
			printf( "No\n" );
		}
	}
	return 0;
}
