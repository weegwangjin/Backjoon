#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int arr[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int now = arr[0];
	int max_ = -1;
	int ck = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i-1] >= arr[i]) {
			ck = 1;
			max_ = max(max_, arr[i - 1] - now);
			now = arr[i];
		}
		else if (i == n - 1) {
			max_ = max(max_, arr[i] - now);
		}
	}
	if (!ck) {
		cout << 0 << endl;
		return 0;
	}
	cout << max_ << endl;
}