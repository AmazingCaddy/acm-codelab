#include <stdio.h>
#include <stdlib.h>
#define maxn 104

int a[maxn], b[maxn], c[maxn];
int ans[maxn];

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int check(int num, int a[], int n) {
	int i;
	for (i = 0; i < n; i ++) {
		if (a[i] == num) {
			return 1;
		}
	}
	return 0;
}

int main (int argv, char *argc[]) {
	int cas, i, j;
	int alen, blen, clen;
	scanf ("%d", &cas);
	for (int t = 0; t < cas; t ++) {
		scanf ("%d%d%d", &alen, &blen, &clen);
		for (i = 0; i < alen; i ++) {
			scanf ("%d", &a[i]);
		}
		for (i = 0; i < blen; i ++) {
			scanf ("%d", &b[i]);
		}
		for (i = 0; i < clen; i ++) {
			scanf ("%d", &c[i]);
		}
		int anslen = 0;
		for (i = 0; i < alen; i ++) {
			if (check(a[i], b, blen) && check(a[i], c, clen)) {
				ans [anslen ++] = a[i];
			}
		}
		qsort(ans, anslen, sizeof(int), cmp);
		printf ("case #%d:\n", t);
		for (i = 0; i < anslen; i ++) {
			if (i) {
				printf (" ");
			}
			printf ("%d", ans[i]);
		}
		if (anslen == 0) {
			printf ("-1");
		}
		printf ("\n");
	}
	return 0;
}