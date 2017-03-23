#include <iostream>
#include <algorithm>
using namespace std;

int ck[10001];
int main()
{
	int n;
	cin >> n;
	int arr[1000];
	int max_ = -1;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
		ck[arr[i]]++;
		if (max_ < arr[i]) max_ = arr[i];
	}
	int sum = 0;
	for (int i = max_; i >=0; i--) {
		sum += ck[i];
		if (i <= sum && i >= sum - ck[i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}