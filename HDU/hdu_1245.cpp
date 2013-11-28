#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 103;
const double inf = 1e10;
const double eps = 1e-8;
const int INF = 1000000000;
int n;
double d;

struct node {
    double dis;
    int pathnum;

    node & operator =(const node & b) {
        dis = b.dis;
        pathnum = b.pathnum;
        return *this;
    }
};
node a[maxn][maxn], b[maxn][maxn];

struct point {
    double x, y;
} p[maxn];

int dblcmp(double x) {
    return x < -eps ? -1 : x > eps;
}

double minn(double x, double y) {
    return ( x < y ? x : y);
}

int Min(int a, int b) {
    return a < b ? a : b;
}

double toline(point p) {
    return minn(minn(fabs(p.x - 50), fabs(p.x + 50)), minn(fabs(p.y + 50), fabs(p.y - 50)));
}

double mindis(point p) {
    double t = sqrt(p.x * p.x + p.y * p.y);
    if (t > 7.5) return t - 7.5;
    return 0;
}

double Dis(point a, point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Floyd() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            b[i][j] = a[i][j];
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (b[i][k].dis + b[k][j].dis < b[i][j].dis)
                    b[i][j].dis = b[i][k].dis + b[k][j].dis,
                        b[i][j].pathnum = b[i][k].pathnum + b[k][j].pathnum;
                else if (b[i][k].dis + b[k][j].dis == b[i][j].dis)
                    b[i][j].pathnum = Min(b[i][j].pathnum, b[i][k].pathnum + b[k][j].pathnum);
}

int main() {
    while (scanf("%d%lf", &n, &d) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        p[0].x = 0, p[0].y = 0;
        for (int i = 0; i <= n; i++) {
            double t = mindis(p[i]);
            if (t > d) {
                a[0][i].dis = a[i][0].dis = inf;
                a[i][0].pathnum = a[0][i].pathnum = 0;
            } else if (t > 0) {
                a[0][i].dis = a[i][0].dis = t;
                a[i][0].pathnum = a[0][i].pathnum = 1;
            } else {
                a[i][0].dis = a[0][i].dis = 0;
                a[i][0].pathnum = a[0][i].pathnum = 0;
            }
            a[i][i].dis = 0;
            a[i][i].pathnum = 0;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (Dis(p[i], p[j]) > d)
                    a[i][j].dis = a[j][i].dis = inf, a[i][j].pathnum = a[j][i].pathnum = INF;
                else a[i][j].dis = a[j][i].dis = Dis(p[i], p[j]), a[i][j].pathnum = a[j][i].pathnum = 1;
        /*
        for( int i = 0; i <= n; i++ )
        {
            for( int j = 0; j <= n; j++ )
                printf("%.4lf ",a[i][j].dis);
            printf("\n");
        }
         */
        Floyd();
        //for (int i = 1; i <= n; i++)
            //printf("%.4lf %d\n", b[0][i].dis, b[0][i].pathnum);
        double ans = inf;
        int k = -1;
        for (int i = 1; i <= n; i++) {
            double t = toline(p[i]);
            if (t <= d) {
                if (b[0][i].dis + t < ans) {
                    k = i;
                    ans = b[0][i].dis + t;
                } else if (b[0][i].dis + t == ans) {
                    if (b[0][i].pathnum < b[0][k].pathnum)
                        k = i;
                }
            }
        }
        if (k == -1)printf("can't be saved\n");
        else printf("%.2lf %d\n", ans, b[0][k].pathnum + 1);
    }
    return 0;
}
