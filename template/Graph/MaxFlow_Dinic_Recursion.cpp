// pku 1273
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 205;
const int maxm = 205;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;

struct edge {
	int v, next;
	ll f;
};

int total;
int head[maxn];
edge e[maxm << 1];

int dis[maxn];
int que[maxn];

void init () {
	total = 0;
	memset (head, -1, sizeof(head));
}

void add (int u, int v, int f) {
	e[total].v = v;
	e[total].f = f;
	e[total].next = head[u];
	head[u] = total;
	total ++;
}

void addedge (int u, int v, int f) {
	add (u, v, f);
	add (v, u, 0);
}

bool bfs (int s, int t) {
	memset (dis, -1, sizeof(dis));
	int l = 0, r = 1;
	que[l] = s;
	dis[s] = 0;
	while (l < r) {
		int u = que[l ++];
		for (int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if (e[i].f && dis[v] == -1) {
				dis[v] = dis[u] + 1;
				que[r ++] = v;
			}
		}
	}
	return dis[t] != -1;
}

ll dfs (int u, int t, ll limit = inf) {
	if (u == t) {
		return limit;
	}
	ll flow = 0;
	for (int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if (e[i].f && dis[u] + 1 == dis[v]) {
			ll f = dfs(v, t, min(limit - flow, e[i].f));
			if (f > 0) {
				e[i].f -= f;
				e[i ^ 1].f += f;
				flow += f;
				if (flow == limit) {
					break;
				}
			} else {
				dis[v] = -1;
			}
		}
	}
	return flow;
}

ll dinic (int s, int t) {
	ll ans = 0;
	while (bfs(s, t)) {
//		cout << "bfs ok\n";
		ans += dfs(s, t, inf);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	int u, v, f;
	while (scanf ("%d%d", &m, &n) != EOF) {
		init();
		for (int i = 0; i < m; i ++) {
			scanf ("%d%d%d", &u, &v, &f);
			addedge(u, v, f);
		}
		cout << dinic(1, n) << "\n";
	}
	return 0;
}