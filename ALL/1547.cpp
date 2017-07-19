#include <iostream>

using namespace std;

int main()
{
	int m;
	cin >> m;
	int now = 1;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (a == now) now = b;
		else if (b == now) now = a;
	}
	cout << now << endl;
}