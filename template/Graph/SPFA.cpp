// Shortest Path Faster Algorithm
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 1005;
const int maxm = 20005;
const int inf = 0x3f3f3f3f;

struct edge{
	int v, w;
	int next;
};

int total;
int head[maxn];
edge e[maxm];

int dis[maxn];
int inqueue[maxn];
int cnt[maxn];

void init(int n) {
	total = 0;
	for (int i = 0; i < n; i ++) {
		head [i] = -1;
	}
}

void addedge(int u, int v, int w) {
	e[total].v = v;
	e[total].w = w;
	e[total].next = head[u];
	head[u] = total;
	total ++;
}

int spfa (int n, int s, int t = -1) {
	for (int i = 0; i < n; i ++) {
		dis[i] = inf;
		inqueue[i] = 0;
		cnt[i] = 0;
	}
	queue<int> que;
	que.push(s);
	inqueue[s] = 1;
	cnt[s] = 1;
	dis[s] = 0;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		inqueue[u] = 0;
		for (int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if (dis[u] + e[i].w < dis[v]) {
				dis[v] = dis[u] + e[i].w;
				if (!inqueue[v]) {
					que.push(v);
					inqueue[v] = 1;
					cnt[v] ++;
					if (cnt[v] > n) {
						return -1;
					}
				}
			}
		}
	}
	if (t == -1) {
		t = n - 1;
	}
	return dis[t];
}

int main(int argc, char const *argv[]) {
	int n, m, s, t;
	int u, v, w;
	int des;
	while (scanf ("%d%d%d", &n, &m, &s) == 3) {
		init(n);
		s --;
		for (int i = 0; i < m; i ++) {
			scanf ("%d%d%d", &u, &v, &w);
			u --;
			v --;
			addedge(v, u, w);
		}
		spfa(n, s);
		scanf ("%d", &t);
		int ans = inf;
		for (int i = 0; i < t; i ++) {
			scanf ("%d", &des);
			ans = min(ans, dis[des - 1]);
		}
		if (ans == inf) {
			ans = -1;
		}
		cout << ans << "\n";
	}
	return 0;
}