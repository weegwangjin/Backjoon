#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		int i = 0;
		cin >> n;
		while (n > 0) {
			if (n & 1) {
				cout << i << " ";
			}
			i++;
			n /= 2;
		}
		cout << endl;
	}
}