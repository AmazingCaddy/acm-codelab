/*
 *	time:	2013-12-18 19:28
 *	author:	AmazingCaddy
 *	solve:	manacher algorithm, p[i] = min(max_id - i, p[id * 2 - 1]);
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int maxn = 110020;

char buffer[maxn], str[maxn << 1];
int p[maxn << 1];

int manacher() {
	int len = 0;
	str[len ++] = '$';
	for (int i = 0; buffer[i]; i ++) {
		str[len ++] = '#';
		str[len ++] = buffer[i];
	}
	str[len ++] = '#';
	int max_id = 0, id = 0, ans = 0;
	for (int i = 1; i < len; i ++) {
		if (max_id > i) {
			p[i] = min(max_id - i, p[id * 2 - i]);
		} else {
			p[i] = 1;
		}
		while (str[i - p[i]] == str[i + p[i]]) {
			p[i] ++;
		}
		if (i + p[i] > max_id) {
			max_id = i + p[i];
			id = i;
		}
		ans = max(ans, p[i]);
	}
	return ans - 1;
}

int main (int argc, char *argv[]) {
	while (scanf ("%s", buffer) != EOF) {
		printf ("%d\n", manacher());
	}
	return 0;
}