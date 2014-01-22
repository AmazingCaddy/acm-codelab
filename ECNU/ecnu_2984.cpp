#include <stdio.h>

int main (int argc, char *argv[]) {
	int cas;
	scanf ("%d", &cas);
	for (int t = 0; t < cas; t ++) {
		int n, total;
		scanf ("%d%d", &n, &total);
		printf ("case #%d:\n", t);
		int ans = 0;
		for (int i = 0; i <= n; i ++) {
			for (int j = 0; j <= n - i; j ++) {
				int k = n - i - j;
				if (i * 3 + j * 2 + k == total) {
					ans ++;
					printf ("%d %d %d\n", i, j, k);
				}
			}
		}
		if (!ans) {
			printf ("-1\n");
		}
	}
	return 0;
}