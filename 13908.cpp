#include <iostream>

using namespace std;

long long factorial(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
	}
	long long answer = factorial(10-m) / (factorial(n-m)*factorial(10-n));
	cout << answer << endl;
}