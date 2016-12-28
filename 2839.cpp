#include <iostream>

using namespace std;

int main()
{
	int k;
	cin >> k;
	int now = (k / 5);
	for (int i = now; i >= 0; i--) {
		cout << k << " " << now << " " << k - (now * 5) << endl;
		if ((k - (i * 5)) % 3 == 0) {
			cout << i + (k - (i * 5)) / 3 << endl;
			return 0;
		}	
	}
	cout << -1 << endl;
}