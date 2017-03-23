#include <iostream>

using namespace std;
int cnt[10];
int main()
{

	int a, b, c;
	cin >> a >> b >> c;
	int sum = a*b*c;
	cnt[sum % 10]++;
	sum -= sum % 10;
	int p = 10;
	int q = 100;
	while (sum != 0) {
		int tmp = sum;
		tmp %= q;
		cnt[tmp / p]++;
		p *= 10;
		q *= 10;
		sum -= tmp;
	}
	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << endl;
	}
}