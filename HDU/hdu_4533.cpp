#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;

const int maxn = 20020;
const int maxm = 200020;

ll sqr[maxm], lea[maxm], zero[maxm], ans[maxm];

void set_seg (int x, int y, int flag) {
    //cout << "x = " << x << ",y = " << y << endl; 
    int min_num = min (x, y), max_num = max (x, y);
    sqr[0] += (1 * flag);
    sqr[min_num] -= (1 * flag);
    lea[min_num] += (min_num * flag);
    lea[max_num] -= (min_num * flag);
    zero[max_num] += ((ll) min_num * max_num * flag);
}

int main(int argc, char *argv[]) {
    int cas, x1, x2, y1, y2;
    scanf ("%d", &cas);
    for (int t = 1; t <= cas; t ++) {
        int n;
        scanf ("%d", &n);
        memset (sqr, 0, sizeof (sqr));
        memset (lea, 0, sizeof (lea));
        memset (zero, 0, sizeof (zero));
        for (int i = 0; i < n; i ++) {
            scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
            set_seg (x2, y2, 1);
            set_seg (x1, y2, -1);
            set_seg (x2, y1, -1);
            set_seg (x1, y1, 1);
        }
        ll A = 0, B = 0, C = 0;
        for (int i = 0; i < maxm; i ++) {
            A += sqr[i];
            B += lea[i];
            C += zero[i];
            ans[i] = A * i * i + B * i + C;
        }
        int w, x;
        scanf ("%d", &w);
        for (int i = 0; i < w; i ++) {
            scanf ("%d", &x);
            printf ("%I64d\n", ans[x]);
        }
    }
    return 0;
}