#include <iostream>
#include <string>

using namespace std;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a[a.length() / 2 - 1] == a[a.length() / 2]) {
			cout << "Do-it" << endl;
		}
		else cout << "Do-it-Not" << endl;
	}

}