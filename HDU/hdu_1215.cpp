/*
 *	time:	2013-12-18 20:10
 *	author:	AmazingCaddy
 *	solve:	make a answer table
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int maxn = 500000 + 200;

int dp[maxn];

void fac(int n) {
	memset( dp, 0, sizeof( dp ) );
	for( int i = 1; i < n; ++i ) {
		for( int j = i; j < n; j += i ) {
			dp[ j ] += i;
		}
	}
}

int main (int argc, char *argv[]) {
	int cas, n;
	fac(maxn);
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++){
		scanf ("%d", &n);
		printf("%d\n", dp[n] - n);
	}
	return 0;
}