#include <iostream>
#include <string>
using namespace std;

bool ishansu(int n) {
	int bak = n / 100;
	n -= bak * 100;
	int sip = n / 10;
	n -= sip * 10;
	int one = n;
	if (bak + one == 2 * sip) return true;
	return false;
}
int main()
{
	int num;
	cin >> num;
	if (num <= 99) {
		cout << num << endl;
		return 0;
	}
	int ans = 99;
	for (int i = 100; i <= num; i++) {
		if (i == 1000) continue;
		if (ishansu(i)) ans++;;
	}
	cout << ans << endl;
}