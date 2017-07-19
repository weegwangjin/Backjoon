#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int tmp = a;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 2; i++) {
		int k = 1000000;
		while (k != 0) {
			if (tmp / k == 0) {
				k /= 10;
				continue;
			}
			if (tmp / k == 5) {
				sum1 += k;
			}
			if (tmp / k == 6) {
				sum2 += k;
			}
			tmp -= (tmp / k) *k;
			k /= 10;
			
		}
		tmp = b;
		
	}
	cout << a + b - sum2 << " " << a + b + sum1 << endl;
}