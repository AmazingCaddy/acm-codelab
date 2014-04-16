// 最小费用最大流，增加S，T，容量为2
// pku 2135
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <ctime>

using namespace std;

const int maxn = 2005;
const int maxm = 100005;
const int inf = 0x2f2f2f2f;

int n, m;
int d[maxn], q[65537], v[maxn], pre[maxn], preh[maxn];
int vpt[maxm], next[maxm], head[maxm], flow[maxm], cost[maxm];
int l = 1;

void add (int a, int b, int f, int c) {
	vpt[++ l] = b;
	next[l] = head[a];
	head[a] = l;
	flow[l] = f;
	cost[l] = c;
	vpt[++ l] = a;
	next[l] = head[b];
	head[b] = l;
	flow[l] = 0;
	cost[l] = -c;
}

int spfa (int n, int s, int t) {
	int i, l, r;
	for (i = 0; i < n; ++ i)
		d[i] = inf, v[i] = 0;
	d[q[l = 0] = s] = 0;
	r = 1;
	while (l ^ r) {
		int x = q[l ++];
		l &= 65535;
		v[x] = 0;
		for (i = head[x]; i; i = next[i]) {
			int y = vpt[i];
			if (flow[i] > 0 && d[x] + cost[i] < d[y]) {
				d[y] = d[x] + cost[i];
				pre[y] = x;
				preh[y] = i;
				if (!v[y])
					q[r ++] = y, v[y] = 1, r &= 65535;
			}
		}
	}
	return d[t];
}

int mincostmaxflow (int n, int s, int t, int &f_ans) {
	int ans = 0, i, f;
	f_ans = 0;
	while (true) {
		f = spfa(n, s, t);
		if (f == inf)
			break;
		ans += f;
		f = inf;
		for (i = t; i != s; i = pre[i])
			f = min(f, flow[preh[i]]);
		f_ans += f;
		for (i = t; i != s; i = pre[i])
			flow[preh[i]] -= f, flow[preh[i] ^ 1] += f;
	}
	return ans;
}

void init (int n) {
	l = 1;
	int i;
	for (i = 0; i < n; ++ i)
		head[i] = 0;
}

int main () {
	int i, j, t, m, n, u, v, r, s, a, b, c;
	while (scanf("%d%d", &n, &m) != EOF) {
		init(n + 2);
		add(0, 1, 2, 0);
		add(n, n + 1, 2, 0);
		while (m --) {
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, 1, c);
			add(b, a, 1, c);
		}
		s = mincostmaxflow(n + 2, 0, n + 1, t);
		printf("%d\n", s);
	}
	return 0;
}
