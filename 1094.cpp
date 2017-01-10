#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int ans = 0;
	if (num & 1) ans++;
	for (int i = 0; i < 7; i++) {
		num = num >> 1;
		if (num & 1) ans++;
	}
	cout << ans;
}