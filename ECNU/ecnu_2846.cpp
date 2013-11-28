/*
	author: AmazingCaddy
	time:	2012/1/18	13:54
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

const int maxn = 105;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int a[ maxn ], b[ maxn ], c[ maxn ];

int main(int argc, char *argv[]){
	int n;
	a[ 2 ] = 1;
	b[ 2 ] = 1;
	c[ 2 ] = 2;
	for ( int i = 3; i < 25; i++ ) {
		a[ i ] = c[ i - 1 ];
		b[ i ] = a[ i - 1 ] + b[ i - 1 ];
		c[ i ] = b[ i - 1 ] + c[ i - 1 ];
	}
	while (scanf("%d", &n) && n != -1) {
		if (n < 3) {
			printf("%d\n", 1 << n);
		} else {
			printf("%d\n", a[n] + b[n] + c[n]);
		}
	}
	return 0;
}
