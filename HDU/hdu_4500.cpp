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

const int maxn = 110;
int mp[maxn][maxn];
int sc[maxn][maxn];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int inf = 0x3f3f3f3f;
int D (int x) {
}
int main(int argc, char *argv[]) {
    int cas, N, M;
    while (1) {
        scanf ("%d%d", &N, &M);
        if (N == 0 && M == 0) {
            break;
        }
        memset (mp, 0, sizeof (mp));
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= M; j ++) {
                scanf ("%d", &mp[i][j]);
            }
        }
        int max_ans = -inf, ii = 0, jj = 0;
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= M; j ++) {
                int ans = 0;
                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (mp[i][j] * mp[nx][ny] < 0) {
                        ans += abs (mp[nx][ny]);
                    } else {
                        ans -= abs (mp[nx][ny]);
                    }
                }
                if (ans > max_ans) {
                    max_ans = ans;
                    ii = i;
                    jj = j;
                }
            }
        }
        printf ("%d %d %d\n", ii, jj, max_ans);
    }
    return 0;
}