#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[10];
int max_ = -1;
void recur(int begin) {
	int i;
	int range = n - begin;
	if (range==1) {
		int sum = 0;
		for (int j = 0; j < n-1; j++) {
			sum += abs(arr[j] - arr[j + 1]);
		}
		if (max_ < sum) {
			max_ = sum;
		}
		return;
	}
	for (i = 0; i < range; i++) {
		swap(arr[begin], arr[begin+i]);
		recur(begin+1);
		swap(arr[begin], arr[begin+i]);
	}
}
int main()
{

	cin >> n;	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr +n);
	recur(0);
	cout << max_ << endl;
}