#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
unsigned long long arr[100001];
unsigned long long tree_min[262145];
unsigned long long tree_max[262145];
int sum = 1;
unsigned long long make_min(int pos) {
	if (pos >= sum) {
		if (pos - sum >= n) {
			arr[pos - sum] = 999999999;
		}
		return tree_min[pos] = arr[pos-sum];
	}
	return tree_min[pos] = min(make_min(pos * 2), make_min(pos * 2 + 1));
}
unsigned long long make_max(int pos) {
	if (pos >= sum) {
		if (pos - sum >= n) {
			arr[pos - sum] = -1;
		}
		return tree_max[pos] = arr[pos - sum];
	}
	return tree_max[pos] = max(make_max(pos * 2), make_max(pos * 2 + 1));
}
int main()
{
	cin >> n >> m;
	int i, j;
	while (sum < n) {
		sum *= 2;
	}
	for (i = 0; i < 262145; i++) {
		tree_min[i] = 999999999;
	}
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	make_min(1);
	make_max(1);
	for (i = 0; i < m; i++) {
		int left, right;
		unsigned long long min_ = 999999999;
		unsigned long long max_ = -1;
		cin >> left >> right;
		left += sum - 1;
		right += sum - 1;
		while (left <= right) {
			min_ = min(min_, min(tree_min[left], tree_min[right]));
			max_ = max(max_, max(tree_max[left], tree_max[right]));
			left = (left + 1) / 2;
			right = (right - 1) / 2;
		}
		cout << min_ << " " << max_ << endl;
	}


}