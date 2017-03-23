#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int memo_1[1000000];

int main() {
	int t;
	scanf_s("%d", &t);
	while (t--) {
		
		int n, m,i;
		scanf_s("%d", &n);
		for (i = 0; i < n; i++) scanf_s("%d", &memo_1[i]);
		sort(memo_1, memo_1 + n);
		scanf_s("%d", &m);
		for (i = 0; i < m; i++) {
			int a;
			scanf_s("%d", &a);
			printf("%d\n", binary_search(memo_1,memo_1+n,a));
		}
		memset(memo_1, 0, sizeof(int) * 1000000);
	}
}