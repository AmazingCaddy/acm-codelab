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
using namespace std;
typedef long long ll;

struct node {
    int d, p;
    node () {}
    node (int _d, int _p) : d (_d), p (_p) {}
    bool operator < (const node & a) const {
        return p > a.p;
    }
};

bool cmp1 (const int &a, const int &b) {
    return a > b;
}

bool cmp2 (const node &a, const node &b) {
    return a.d > b.d;
}

const int maxn = 100020;
int rabbit[maxn];
node jian[maxn];

int main(int argc, char *argv[]) {
    /*
    heap.push (node (1, 2));
    heap.push (node (2, 3));
    while (!heap.empty()) {
        node tmp = heap.top ();
        heap.pop ();
        cout << tmp.p << "\n";
    }
    */
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i ++) {
            scanf ("%d", &rabbit[i]);
        }
        for (int i = 0; i < m; i ++) {
            scanf ("%d", &jian[i].d);
        }
        for (int i = 0; i < m; i ++) {
            scanf ("%d", &jian[i].p);
        }
        sort (rabbit, rabbit + n, cmp1);
        sort (jian, jian + m, cmp2);
        /*
        cout << "rabbit:\n"; 
        for (int i = 0; i < n; i ++) {
            cout << rabbit[i] << " ";
        }
        cout << "\n";
        */
        priority_queue<node> heap;
        ll ans = 0;
        for (int i = 0, j = 0; i < n; i ++) {
            while (j < m) {
                if (rabbit[i] <= jian[j].d) {
                    heap.push (jian[j]);
                    j ++;
                } else {
                    break;
                }
            }
            if (heap.empty()) {
                ans = -1;
                break;
            }
            node tmp = heap.top ();
            heap.pop ();
            ans += tmp.p;
        }
        if (ans == -1) {
            printf ("No\n");
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}