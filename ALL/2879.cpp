#include <cstdio>
#include <stdlib.h>
int p[1000];
int q[1000];
int r[1000];
int p_r[1000];
int max_n(int x, int y) {
	int ret = 0;
	int min_ = p_r[x];
	int max_ = -1;
	int comp = p_r[x];
	for (int i = x; i <= y; i++) {
		int ck = 1;
		if (comp > p_r[i]) {
			if (ret != 0)
				ret -= min_;
			ret += comp;
			ck = 0;
		}
		if (p_r[i] < min_)
			min_ = p_r[i];
		if (i == y &&ck) {
			if (ret != 0) ret -= min_;
			ret += p_r[i];
		}
		comp = p_r[i];
	}
	return ret;
}
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &q[i]);
		r[i] = p[i] - q[i];
		p_r[i] = abs(r[i]);
	}
	int st = 0;
	int comp = r[0];
	int ret = 0;
	for (i = 1; i < n; i++) {
		if (comp*r[i] < 0) {
			ret+=max_n(st, i - 1);
			st = i;
			comp = r[i];
		}
		if (i == n - 1) {
			ret += max_n(st, i);
		}
	}
	printf("%d", ret);
}