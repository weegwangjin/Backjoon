#include <iostream>
#include <cmath>

using namespace std;


bool isprime(int p) {
	bool ret = true;
	if (p == 1) return false;
	for (int i = 2; i*i <= p; i++) {
		if (p% i == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (isprime(k)) cnt++;
	}
	cout << cnt << endl;
}