#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max_ = -1;
	int arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max_ < arr[i]) max_ = arr[i];
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (double)arr[i] / (double)(max_) * 100;
	}
	printf("%0.2f", sum/n);
}