#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;
const int maxn = 110;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int inf = 0x3f3f3f3f;

int dp[maxn][maxn][6];
int a[maxn], b[maxn], val[maxn];
int main(int argc, char *argv[]) {
    int N, V1, V2, K;
    while (scanf ("%d%d%d%d", &N, &V1, &V2, &K) != EOF) {
        for (int i = 0; i < N; i ++) {
            scanf ("%d%d%d", &a[i], &b[i], &val[i]);
        }
        memset (dp, 0, sizeof (dp));
        int ans = 0;
        for (int p = 0; p < N; p ++) {
            for (int k = K; k >= 0; k --) {
                for (int i = V1; i >= 0; i --) {                    
                    for (int j = V2; j >= 0; j --) {
                        int tmp = dp[i][j][k], tmp1 = -1, tmp2 = -1, tmp3 = -1;
                        if (i >= a[p]) {
                            tmp1 = dp[i - a[p]][j][k] + val[p];
                            //dp[i][j][k] = max (tmp, dp[i - a[p]][j][k] + val[p]);
                            //cout << "i >= a[p]" << dp[i][j][k] << endl;
                        }
                        if (j >= b[p]) {
                            tmp2 = dp[i][j - b[p]][k] + val[p];
                            //dp[i][j][k] = max (tmp, dp[i][j - b[p]][k] + val[p]);
                        }
                        if (k >= 1) {
                            tmp3 = dp[i][j][k - 1] + val[p];
                            //dp[i][j][k] = max (tmp, dp[i][j][k - 1] + val[p]);
                        }
                        dp[i][j][k] = max (max (tmp, tmp1), max (tmp2, tmp3));
                        if (ans < dp[i][j][k]) {
                            ans = dp[i][j][k];
                        }
                    }
                }
            }
            //cout << ans << endl;
            /*
            for (int k = 0; k <= K; k ++) {
                for (int i = 0; i <= V1; i ++) {
                    for (int)
                }
            }
            */
        }
        printf ("%d\n", ans);
    }
    return 0;
}