/*
 *	time:	2013-12-18 20:44
 *	author:	AmazingCaddy
 *	solve:	gcd
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main (int argc, char *argv[]) {
	int n, m;
	while (scanf ("%d%d", &n, &m) && n != -1 && m != -1) {
		if (gcd(n, m) == 1) {
			printf ("YES\n");
		} else {
			printf ("POOR Haha\n");
		}
	}
	return 0;
}
