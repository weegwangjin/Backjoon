#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


int elem[1000001];
int rank_[1000001];
int find(int i) {
	if (elem[i] == i) return i;
	return find(elem[i]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	if (rank_[a] > rank_[b]) {
		elem[b] = a;
	}
	
	else elem[a] = b;

	if (rank_[a] == rank_[b]) rank_[b]++;
}
int main()

{
	int n, m;
	for (int i = 0; i < 1000001; i++) elem[i] = i;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k, a, b;
		scanf("%d%d%d", &k, &a, &b);
		if (k == 0) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}