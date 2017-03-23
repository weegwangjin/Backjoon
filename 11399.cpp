#include <iostream>

using namespace std;
int arr[1000];

int main()
{
	int n, i,j;
	cin >> n;
	for (i = 0; i < n;i++) {
		cin >> arr[i];
	}
	int sum = 0;
	int sum1 = 0;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		sum1 += arr[i];
		sum += sum1;
	}
	cout << sum << endl;
}