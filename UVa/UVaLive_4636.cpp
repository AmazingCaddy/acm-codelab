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

int main(int argc, char *argv[]){
//	freopen( "in.txt", "r", stdin );
	int w, d, h;
	int cnt[ 30 ];
	while( 1 ) {
		scanf( "%d%d", &w, &d );
		if( w == 0 && d == 0 ) {
			break;
		}
		memset( cnt, 0, sizeof( cnt ) );
		int sum = 0;
		for( int i = 0; i < w; i++ ) {
			scanf( "%d", &h );
			sum += h;
			cnt[ h ] ++;
		}
		for( int i = 0; i < d; i++ ) {
			scanf( "%d", &h );
			if( cnt[ h ] ) {
				cnt[ h ] --;
			}
			else {
				sum += h;
			}
		}
		printf( "%d\n", sum );
	}
	return 0;
}
