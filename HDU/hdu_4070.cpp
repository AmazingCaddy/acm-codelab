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

const int maxn = 100005;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct node {
	int d, t;
}cell[ maxn ];

bool cmp( const node &a, const node &b ) {
	return a.t > b.t;
}

int main(int argc, char *argv[]){
	int cas, n;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ ) {
			scanf( "%d%d", &cell[ i ].d, &cell[ i ].t );
		}
		sort( cell, cell + n, cmp );
		int T = 0, ans = 0;
		for( int i = 0; i < n; i++ ) {
			T += cell[ i ].d;
			if( T + cell[ i ].t > ans ) {
				ans = T + cell[ i ].t;
			}
		}
		printf( "Case %d: %d\n", t , ans );
	}
	return 0;
}
