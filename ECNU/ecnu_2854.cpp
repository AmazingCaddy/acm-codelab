#include <stdio.h>
#include <iostream>
using namespace std;

const int maxn = 40;
int dp[maxn];

int main (int argc, char *argv[]) {
	int n, m;
	//freopen("in.txt", "r", stdin);
	while (scanf ("%d%d", &n, &m) && n != -1 && m != -1) {
		for (int i = 0; i < m; i ++) {
			dp[i] = 0;
		}
		dp[m] = 1;
		for (int i = m; i < n; i ++) {
			dp[i + 1] = 2 * dp[i] + (1 << (i - m)) - dp[i - m];
		}
		printf ("%d\n", dp[n]);
	}
	return 0;
}