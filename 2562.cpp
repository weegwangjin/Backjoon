#include <iostream>

using namespace std;

int main()
{
	int ans= -1, ans2;
	
	for (int i = 1; i <= 9; i++) {
		int t;
		cin >> t;
		if (ans < t) {
			ans2 = i;
			ans = t;
		}
	}
	cout << ans << endl << ans2 << endl;
}