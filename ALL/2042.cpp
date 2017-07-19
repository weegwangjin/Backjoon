#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


vector<int> vec(1000001);
long long tree[1000001];
int n, m, k;
long long sum(int i) {
	long long ret = 0;
	while (i >= 1) {
		ret += tree[i];
		i -= (i& -i);
	}
	return ret;
}
void modify_(int i, int diff) {
	int tmp = i;
	while (i <= n) {
		tree[i] += diff;
		i += (i&-i);
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int p;
		scanf("%d", &p);
		modify_(i, p);
		vec[i] = p;

	}
	for (int i = 0; i < m+k; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 2) {
			printf("%lld\n", sum(c) - sum(b - 1));
		}
		else {
			modify_(b, c-vec[b]);
			vec[b] = c;
		}
	}
}