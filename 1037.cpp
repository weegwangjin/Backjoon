#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num[50];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	if (n % 2 == 0) {
		cout << num[0] * num[n - 1];
	}
	else {
		cout << num[(n-1) / 2]* num[(n-1)/2];
	}
}