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

const int maxn = 10000010;
char num;

int main(int argc, char *argv[]) {
    int cas;
    scanf ("%d", &cas);
    for (int t = 1; t <= cas; t ++) {
        int D, base;
        scanf ("%d%d%*c", &D, &base);
        int ans = 0;
        int mod = base - 1;
        while ((num = getchar ()) != '\n') {
            ans = ans + num - '0';
            if (ans >= mod) {
                ans -= mod;
            }
        }
        printf ("%d %d\n", D, ans);
    }
    return 0;
}