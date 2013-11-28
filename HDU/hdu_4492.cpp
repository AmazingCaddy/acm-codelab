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

const int maxn = 128;

int mod (int x, int n) {
    return (x % n + n) % n;
}

int main(int argc, char *argv[]) {
    int cas;
    scanf ("%d", &cas);
    for (int t = 1; t <= cas; t ++) {
        int D, N, index, offset, len;
        char str[maxn];
        char ans[maxn << 3];
        scanf ("%d%*c", &D);
        gets (str);
        len = strlen (str);
        scanf ("%d", &N);
        index = 0;
        for (int i = 0; i < N; i ++) {
            scanf ("%d", &offset);
            index = mod(index + offset, len);
            ans[i] = str[index];
        }
        ans[N] = '\0';
        printf ("%d %s\n", D, ans);
    }
    return 0;
}