/*
 *	time:	2013-12-18 19:51
 *	author:	AmazingCaddy
 *	solve:	make a answer table
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int maxn = 1000000 + 200;

int vis[maxn];

int get_solve(int n) {
	int sum = n;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void init() {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i <= 1000000; i ++) {
		vis[get_solve(i)] = 1;
	}
}

int main (int argc, char *argv[]) {
	init();
	for (int i = 0; i <= 1000000; i ++) {
		if (!vis[i]) {
			printf ("%d\n", i);
		}
	}
	return 0;
}