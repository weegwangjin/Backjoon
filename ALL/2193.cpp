#include <iostream>

using namespace std;
long long int num[91];
long long int zero[91];
long long int one[91];
int main()
{
	int n;
	cin >> n;
	num[1] = 1;
	num[2] = 1;
	zero[2] = 1;
	one[2] = 0;
	for (int i = 3; i <= 90; i++) {
		zero[i] = num[i - 1];
		one[i] = zero[i - 1];
		num[i] = one[i - 1] + 2 * zero[i - 1];
	}
	cout << num[n] << endl;
}