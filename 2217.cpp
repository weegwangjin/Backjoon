#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[100000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int max_ = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if ((n-i)*arr[i] >= max_) {
			max_ = (n - i)*arr[i];
		}
	}
	cout << max_ << endl;
}