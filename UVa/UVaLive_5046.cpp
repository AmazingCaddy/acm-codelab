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

const int maxn = 104;
int tile[ maxn ];

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int cas, n, m;
	scanf( "%d", &cas );
	while( cas-- ) {
		scanf( "%d%d", &m, &n );
		int dir = 0, st = 0;
		for( int i = 1; i <= m; i++ ) {
			scanf( "%d", &tile[ i ] );
			if( tile[ i ] == 2 ) {
				dir = 1;
				st = i;
			}
			else if( tile[ i ] == 3 ) {
				dir = -1;
				st = i;
			}
		}
		int x = st, cnt = 0;
		for( int i = 0; i < n; i++ ) {
			if( st + dir == m + 1 || st + dir == 0 ) {
				dir = -dir;
				i--;
				continue;
			}
			st += dir;
			if( tile[ st ] == 0 ) {
				cnt++;
			}
		}
		printf( "%d\n", cnt );
	}	
	return 0;
}
