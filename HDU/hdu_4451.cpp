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

const int maxn = 1024;
int p[maxn][maxn], cnt[maxn];

void init () {
    memset (p, 0, sizeof (p));
    memset (cnt, 0, sizeof (cnt));
}

int main () {
    int N, M, K, P, x, y;
    char buf1[20], buf2[20];
    while (1) {
        scanf ("%d%d%d", &N, &M, &K);
        if (N == 0 && M == 0 && K == 0) {
            break;
        }
        scanf ("%d", &P);
        init ();
        for (int i = 0; i < P; i ++) {
            scanf ("%s%d%s%d", buf1, &x, buf2, &y);
            if (buf1[0] == 'c' && buf2[0] == 'p') {
                p[x][y] = 1;
            } else if (buf1[0] == 'p' && buf2[0] == 's') {
                cnt[x] ++;
            }
        }
        int sum = 0;
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= M; j ++) {
                if (!p[i][j]) {
                    sum += (K - cnt[j]);
                }
            }
        }
        printf ("%d\n", sum);
    }
    return 0;
}