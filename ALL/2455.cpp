#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int now = 0;
	int max_ = -1;
	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		max_ = max(max_, now);
		now -= a;
		now += b;
		max_ = max(max_, now);
	}
	cout << max_ << endl;
}