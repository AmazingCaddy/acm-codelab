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
typedef long long ll;

const int maxn = 1004;
int a[ maxn ];

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int cas, n;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ ) {
			scanf( "%d", &a[ i ] );
		}
		int sum = 0;
		for( int i = 1; i < n; i++ ) {
			for( int j = 0; j < i; j++ ) {
				if( a[ j ] <= a[ i ] ) {
					sum++;
				}
			}
		}
		printf( "%d\n", sum );
	}
	return 0;
}
