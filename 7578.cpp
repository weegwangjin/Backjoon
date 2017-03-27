#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int idx[1000001];
vector<pair<int,int> > vec(500001);
vector<int> tree(500001,0);
int n;

long long sum(int i) {
	long long ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i& -i);
	}
	return ret;
}

void update(int i, int val)
{
	while (i <= n) {
		tree[i] += val;
		i += (i&-i);
	}
}
int main()
{

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> vec[i].first;
	}
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		idx[p] = i;
	}
	for (int i = 1; i <= n; i++) {
		vec[i].second = idx[vec[i].first];
		vec[i].first = i;
	}
	long long ans = 0;
	for (int i = n; i >=1; i--) {
		update(vec[i].second, 1);
		ans += sum(vec[i].second - 1);
	}
	cout << ans << endl;


}