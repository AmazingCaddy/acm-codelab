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

const int maxn = 10005;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

char buf[ maxn ];

bool check( int st, int ed ) {
	int flag = ( buf[ st ] == '|' ? 1 : -1 );
	for( int i = st + 1; i <= ed; i++ ) {
		if( flag == 1 && buf[ i ] == '-' || flag == -1 && buf[ i ] == '|' ) {
			flag = -flag;
		}
		else {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]){
	while( gets( buf ) ) {
//		scanf( "%s", buf );
		int len = strlen( buf );
		int ans = 0;
		for( int i = 0; i < len; i++ ) {
			for( int j = i; j < len; j++ ) {
				if( check( i, j ) ) {
					ans = max( ans, j - i + 1 );
				}
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}
