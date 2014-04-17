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

int dis[maxn];	// 距离标号
int que[maxn];	// 用于bfs搜索
int now[maxn];	// now记录头指针访问到哪儿了，下次直接从now开始 
int sta[maxn];	// 栈用于模拟递归，存边

void init () {
	total = 0;
	memset (head, -1, sizeof(head));
}

void add (int u, int v, ll f) {
	e[total].v = v;
	e[total].f = f;
	e[total].next = head[u];
	head[u] = total;
	total ++;
}

void addedge (int u, int v, ll f) {
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

ll dinic_aug (int s, int t) {
	memcpy(now, head, sizeof(head));
	ll flow = 0;
	int u = s, v;	// u为当前结点
	int top = 0;
	while (1) {
		if (u == t) {
			// 找最小的增广 lct记录最小的一条边的位置 
			ll f = inf;
			int lct;
			for (int i = 0; i < top; i ++) {
				if (f > e[sta[i]].f) {
					f = e[sta[i]].f;
					lct = i;
				}
			}
			for (int i = 0; i < top; i ++) {
				e[sta[i]].f -= f;
				e[sta[i] ^ 1].f += f;
			}
			flow += f;
			top = lct;
			u = e[sta[top] ^ 1].v;	// 当前结点修改为 最小边的起点
		}
		for (int i = now[u]; i != -1; now[u] = i = e[i].next) {
			v = e[i].v;
			if (e[i].f && dis[v] == dis[u] + 1) {
				break;
			}
		}
		if (now[u] != -1) {	// 当前结点的下一条边存在
			sta[top ++] = now[u];
			u = v;
		} else {
			if (top == 0) {	// 当前结点无未遍历的下一条边且栈空，DFS找不到下一条增广路
				break;
			}
			dis[u] = -1;	// 当前结点不在增广路中，剔除该点
			u = e[sta[-- top] ^ 1].v;	//退栈 回朔，继续查找 
		}
	}
	return flow;
}

ll dinic (int s, int t) {
	ll ans = 0;
	while (bfs(s, t)) {
		// cout << "bfs ok\n";
		ans += dinic_aug(s, t);
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