/*
	author: AmazingCaddy
	time:	2011-09-23 18:21:20 
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
typedef long long ll;
const int maxn = 10;
int g[ maxn ][ maxn ];
int n;

string strs[ maxn ];
int num[ maxn ];
int lens[ maxn ];

int getlcs( const string & str1, const string & str2 ) {
	int cnt = 0;
	int sz1 = str1.size( ), sz2 = str2.size( );
	int minlen = min( sz1, sz2 );
	for( int i = minlen; i >= 1; i-- ) {
		int flag = 0;
		for( int j = sz1 - i, k = 0; j < sz1 && k < i; j++, k++ ) {
			if( str1[ j ] != str2[ k ] ) {
				flag = 1;
				break;
			}
		}
		if( !flag ) {
			cnt = i;
			break;
		}
	}
	return cnt;
}

void init( ) {
	for( int i = 0; i < n; i++ ) {
		lens[ i ] = strs[ i ].size( );
	}
}

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ ) {
			cin >> strs[ i ];
		}
		init( );
		for( int i = 0; i < n; i++ ) {
			num[ i ] = i;
		}
		int ans = 0x3fffffff;
		do {
			string tmpstr = strs[ num[ 0 ] ];
			for( int i = 1; i < n; i++ ) {
				int tmp = getlcs( tmpstr, strs[ num[ i ] ] );
				tmpstr = tmpstr + string( strs[ num[ i ] ], tmp, lens[ num[ i ] ] - tmp );
			}
			if( tmpstr.size( ) < ans ) {
				ans = tmpstr.size( );
			}
		}while( next_permutation( num, num + n ) );
		printf( "Case %d: %d\n", t, ans );
	}
	return 0;
}

