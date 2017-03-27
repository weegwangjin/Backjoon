#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int plug_[500001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> plug_[i];
	}
	sort(plug_, plug_ + n, greater<int>());
	long long sum = 1;
	for (int i = 0; i < n; i++) {
		sum--;
		sum += plug_[i];
	}
	cout << sum << endl;
}