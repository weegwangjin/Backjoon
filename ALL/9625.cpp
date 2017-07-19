#include <iostream>

using namespace std;

int a[46];
int b[46];

int main()
{
	int n;
	cin >> n;
	a[1] = 1;
	b[1] = 0;
	a[2] = 0;
	b[2] = 1;
	for (int i = 3; i <= n+1; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	cout << a[n+1] << " " << b[n+1] << endl;
}