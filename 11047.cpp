#include <iostream>

using namespace std;

int main() {
	int n, k,i;
	int arr[11];
	int ret = 0;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (i = n; i >= 0; i--) {
		if (k < arr[i]) continue;
		if (k == 0)break;
		ret += k / arr[i];
		k -= (k / arr[i])*arr[i];
	}
	cout << ret << endl;
}