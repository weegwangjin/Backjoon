#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define INF 2e9
using namespace std;

int n,m;


struct indextree {
	int first;
	vector<int> tree;
	indextree(int n) {
		for (first = 1; first < n; first <<= 1) {}
		tree = vector<int>(n << 2, INF);
	}

	void update(int pos, int val) {
		pos += first;
		tree[pos] = val;
		while (pos >> 1) {
			tree[pos >> 1] = min(tree[pos], tree[pos >> 1]);
			pos = pos >> 1;
		}

	}
	int query(int i, int r) {
		int ret = INF;
		i += first;
		r += first;
		while (i <= r) {
			ret = min(ret, min(tree[r], tree[i]));
			i = (i + 1) >> 1;
			r = (r - 1) >> 1;
		}
		return ret;
	}
};

int main()
{
	cin >> n >> m;
	int tmp = n;
	int cnt = 0;
	for (; tmp != 0;) {
		cnt++;
		tmp >>= 1;
	}
	indextree it(1<<cnt);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		it.update(i, k);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", it.query(a-1, b-1));
	}
}