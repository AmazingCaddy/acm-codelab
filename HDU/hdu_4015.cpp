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

const int maxn = 10005;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int main(int argc, char *argv[]){
	int m, k;
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d", &m, &k );
		double ans = 1.0 / ( k + m * k + 1 );
		printf( "Case #%d: %.8lf\n", t, ans );
	}
	return 0;
}
