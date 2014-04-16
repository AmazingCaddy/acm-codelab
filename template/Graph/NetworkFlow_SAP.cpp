// sap最大流
// hdu 3879
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
const int ma = 2000000000;
const int INF = 2000000000;
const int maxn = 55010;
const int maxm = 310010;

struct edge {
	//c是容量,f是流量,bot是下界
	int c, f, bot, u, v, next;
} et[maxm];

int eh[maxn], tot;

void add (int u, int v, int c, int bb) {
	et[tot].u = u;
	et[tot].v = v;
	et[tot].c = c;
	et[tot].f = 0;
	et[tot].bot = bb;
	et[tot].next = eh[u];
	eh[u] = tot ++;
}

//u->v 上界是c 下界是bb
void addedge (int u, int v, int c, int bb) {
	add(u, v, c - bb, bb);
	add(v, u, 0, 0);
}

int low[maxn];	// 存储压入到节点i的流量
int dis[maxn];	// 距离标号
int pre[maxn];	// 记录增广的路径
int cur[maxn];	// 当前弧优化
int gap[maxn];	// gap优化 gap[i]存储距离标号为i的点的个数

int sap_gap (int n, int s, int t) {
	int i, j, k, u, v, now;
	memset(dis, 0, sizeof(dis));
	memset(low, 0, sizeof(low));
	memset(gap, 0, sizeof(gap));
	for (u = 0; u <= n; u ++) {
		// 初始化 设置当前弧 为该点的第一条边
		cur[u] = eh[u];
	}
	int flow = 0;
	u = s;
	low[s] = INF;
	gap[0] = n;
	while (dis[s] < n) {
		// 从当前弧开始找
		for (now = cur[u]; now != -1; now = et[now].next) {
			if (et[now].c > et[now].f && dis[u] == dis[v = et[now].v] + 1) {
				break;
			}
		}
		// 更新当前弧
		cur[u] = now;
		if (now >= 0) {
			// 存在允许弧
			pre[v] = now;
			low[v] = et[now].c - et[now].f;
			if (low[v] > low[u]) {
				low[v] = low[u];
			}
			u = v;
			if (u == t) {
				// 找到一条增广路，更新残留网络
				for (; u != s; u = et[pre[u] ^ 1].v) {
					et[pre[u]].f += low[t];
					et[pre[u] ^ 1].f -= low[t];
				}
				// 把新增的流量累加到总流量中
				flow += low[t];
				// 重新设置源点的流量为INF
				low[s] = INF;
			}
		} else {
			// 不存在允许弧，需要进行调整
			if (-- gap[dis[u]] == 0) {
				// 出现断层，可以直接跳出
				break;
			}
			// 重新设置当前弧
			cur[u] = eh[u];
			// 调整距离标号
			dis[u] = n;
			for (now = eh[u]; now != -1; now = et[now].next) {
				if (et[now].c > et[now].f && dis[u] > dis[et[now].v] + 1) {
					dis[u] = dis[et[now].v] + 1;
				}
			}
			// 距离调整之后，gap数组也要做相应的调整
			gap[dis[u]] ++;
			// 如果不是源点，返回到上一层的点
			if (u != s) {
				u = et[pre[u] ^ 1].v;
			}
		}
	}
	return flow;
}

int main (int argv, char const * argc[]) {
	int i, j, t, m, n, u, v, r, s;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i <= n + m + 2; i ++) {
			eh[i] = -1;
		}
		tot = 0;
		s = 0;
		for (i = 1; i <= n; i ++) {
			scanf("%d", &t);
			addedge(m + i, m + n + 1, t, 0);
		}
		for (int k = 1; k <= m; k ++) {
			scanf("%d%d%d", &i, &j, &t);
			s += t;
			addedge(0, k, t, 0);
			addedge(k, m + i, ma, 0);
			addedge(k, m + j, ma, 0);
		}
		t = sap_gap(n + m + 2, 0, n + m + 1);
		printf("%d\n", s - t);
	}
	return 0;
}
