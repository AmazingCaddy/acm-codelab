#include <stdio.h>
#include <stdlib.h>

#define maxn 1005

int u[maxn], v[maxn];
int res_u[maxn << 1], res_i[maxn], res_d[maxn];
int n, m;
int len_u, len_i, len_d;

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

void set_union(int a[], int b[], int res[]) {
	len_u = 0;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] == b[j]) {
			res[len_u ++] = a[i];
			i ++;
			j ++;
		} else if (a[i] < b[j]) {
			res[len_u ++] = a[i];
			i ++;
		} else {
			res[len_u ++] = b[j];
			j ++;
		}
	}
	while (i < n) {
		res[len_u ++] = a[i ++];
	}
	while (j < m) {
		res[len_u ++] = b[j ++];
	}
}

void set_intersection(int a[], int b[], int res[]) {
	len_i = 0;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] == b[j]) {
			res[len_i ++] = a[i];
			i ++;
			j ++;
		} else if (a[i] < b[j]) {
			//res[len_u ++] = a[i];
			i ++;
		} else {
			//res[len_u ++] = b[j];
			j ++;
		}
	}
}

void set_difference(int a[], int b[], int res[]) {
	len_d = 0;
	for (int i = 0; i < n; i ++) {
		int flag = 0;
		for (int j = 0; j < m; j ++) {
			if (a[i] == b[j]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		res[len_d ++] = a[i];
	}
}

void set_print(int v[], int len) {
	printf ("{");
	for (int i = 0; i < len; i ++) {
		if (i) {
			printf (",");
		}
		printf ("%d", v[i]);
	}
	printf ("}\n");
}

int main(int argc, char const *argv[]) {
	while (scanf ("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i ++) {
			scanf ("%d", &u[i]);
		}
		for (int j = 0; j < m; j ++) {
			scanf ("%d", &v[j]);
		}
		qsort(u, n, sizeof(int), cmp);
		qsort(v, m, sizeof(int), cmp);
		set_intersection(u, v, res_i);
		set_union(u, v, res_u);
		set_difference(u, v, res_d);
		set_print(res_i, len_i);
		set_print(res_u, len_u);
		set_print(res_d, len_d);
	}
	return 0;
}