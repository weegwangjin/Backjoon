#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a >= b) {
		if (a >= c) {
			if (b >= c) {
				cout << b << endl;
				return 0;
			}
			else {
				cout << c << endl;
				return 0;
			}
		}
		else {
			cout << a << endl;
			return 0;
		}
	}
	else {
		if (b >= c) {
			if (a >= c) {
				cout << a << endl;
				return 0;
			}
			else {
				cout << c << endl;
				return 0;
			}
		}
		else {
			cout << b << endl;
			return 0;
		}
	}
}