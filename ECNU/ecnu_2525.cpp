// eoj 2525 light switching
#include <cstdio>
#include <iostream>
const int maxn = 100010;
using namespace std;
struct node {
	int l, r, light;
	bool flag;
};

node tree[maxn << 2];
void make_tree (int l, int r, int v) {
	tree[v].l = l, tree[v].r = r;
	tree[v].light = 0, tree[v].flag = false;
	if (l + 1 != r) {
		int mid = (l + r) >> 1;
		make_tree (l, mid, v << 1);
		make_tree (mid, r, v << 1 | 1);
	}
}

void _update (int v) {
//	cout << "v = " << v << "\n";
	tree[v].flag = ! tree[v].flag;
	tree[v].light = tree[v].r - tree[v].l - tree[v].light;
}

void push_down (int v, int l, int r) {
	if (tree[v].flag) {
		tree[v].flag = false;
		_update (v << 1);
		_update (v << 1 | 1);
	}
}

void push_up (int v, int l, int r) {
	tree[v].light = tree[v << 1].light + tree[v << 1 | 1].light;
}

void update (int l, int r, int v) {
	if (tree[v].l == l && tree[v].r == r) {
		tree[v].flag = !tree[v].flag;
		tree[v].light = tree[v].r - tree[v].l - tree[v].light;
		return;
	}
	push_down (v, l, r);
	int mid = (tree[v].r + tree[v].l) >> 1;
	if (l >= mid) {
		update (l, r, v << 1 | 1);
	} else if (r <= mid) {
		update (l, r, v << 1);
	} else {
		update (l, mid, v << 1);
		update (mid, r, v << 1 | 1);
	}
	push_up (v, l, r);
}
 
int query (int l, int r, int v) {
	if (tree[v].l == l && tree[v].r == r) {
		return tree[v].light;
	}
	push_down (v, l, r);
	int mid = (tree[v].l + tree[v].r) >> 1;
	int temp;
	if (l >= mid) {
		temp = query (l, r, v << 1 | 1);
	} else if (r <= mid) {
		temp = query (l, r, v << 1);
	} else {
		temp = query (l, mid, v << 1) + query (mid, r, v << 1 | 1);
	}
	return temp;
}

int main(int argc, char *argv[]) {
	int n, m, op, a, b;
	while (scanf ("%d%d", &n, &m) != EOF) {
		make_tree (0, n, 1);
		for (int i = 0; i < m; i ++) {
			scanf ("%d%d%d", &op, &a, &b);
			if (op == 0) {
				update (a - 1, b, 1);
			} else {
				printf("%d\n", query (a - 1, b, 1));
			}
		}
	}
	return 0;
}