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
const int maxn = 1010;
const int maxm = 110;

const int inf = 0x3f3f3f3f;

struct NODE {
    int s, e, c;
    NODE () {}
    NODE (int _s, int _e, int _c) : s (_s), e (_e), c (_c) {}
};
NODE job[maxn];

int dp[maxm];

bool cmp (const NODE & a, const NODE & b) {
    return a.e < b.e;
}

int main(int argc, char *argv[]) {
    int cas;
    scanf ("%d", &cas);
    for (int t = 0; t < cas; t ++) {
        int m, n;
        scanf ("%d%d", &m, &n);
        int k = 0;
        for (int i = 0; i < n; i ++) {
            int s, e, c;
            scanf ("%d%d%d", &s, &e, &c);
            if (s > m || e > m) {
                continue;
            }
            if (s > e || e < 1) {
                continue;
            }
            job[k ++] = NODE (s, e, c);
        }
        n = k;
        sort (job, job + n, cmp);
        /*
        for (int i = 0; i < n; i ++) {
            printf ("%d %d %d\n", job[i].s, job[i].e, job[i].c);
        }
        */
        memset (dp, 0, sizeof (dp));
        for (int i = 0, j = 0; i <= m && j < n; ) {
            if (job[j].e <= i) {
                dp[i] = max (dp[i], dp[job[j].s - 1] + job[j].c);
                //cout << "job[j].e <= i: " << i << " " << dp[i] << endl;
                j ++;
            } else {
                i ++;
                dp[i] = dp[i - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; i ++) {
            //cout << dp[i] << endl;
            ans = max (ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}