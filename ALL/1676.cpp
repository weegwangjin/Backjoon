#include <iostream>
#include <algorithm>
using namespace std;

int two;
int five;

void compute(int n)
{
	while (true) {
		if (n % 2 != 0 && n % 5 != 0) break;
		if (n % 2 == 0) {
			n /= 2;
			two++;
		}
		if (n % 5 == 0) {
			n /= 5;
			five++;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		compute(i);
	}
	cout << min(two, five);
}