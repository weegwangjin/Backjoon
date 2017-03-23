#include <iostream>

using namespace std;
long long sum[100001];

int main()
{
	int n;
	cin >> n;
	int arr[100001];
	cin >> arr[0];
	sum[0] = arr[0];
	for (int i = 1; i<n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	long long answer = 0;
	for (int i = 0; i<n - 1; i++) {
		answer += arr[i] * (sum[n-1] - sum[i]);
	}
	cout << answer << endl;
}