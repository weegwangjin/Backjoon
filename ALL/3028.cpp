#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;
	int now = 1;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'A') {
			if (now == 1) now = 2;
			else if (now == 2) now = 1;
		}
		else if (a[i] == 'B') {
			if (now == 2) now = 3;
			else if (now == 3) now = 2;
		}
		else {
			if (now == 1) now = 3;
			else if (now == 3) now = 1;
		}
	}
	cout << now << endl;
}