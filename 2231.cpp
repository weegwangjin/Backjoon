#include <iostream>

using namespace std;

int bunhe(int k) {
	int ret = k;
	int p = 1000000;
	while (k != 0) {
		
		int tmp = k;
		tmp /= p;
		if (tmp != 0) {
			k -= tmp*p;
			ret += tmp;
		}
		p /= 10;
		
	}
	return ret;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <=n-1; i++) {
		int now = bunhe(i);
		if (now == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}