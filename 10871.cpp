#include <iostream>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (x > k) cout << k << endl;
	}
}