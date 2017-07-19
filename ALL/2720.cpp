#include <iostream>
#include <algorithm>

using namespace std;


int each[4] = { 25,10,5,1 };
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		for (int i = 0; i < 4; i++) {
			cout << (c / each[i]) << " ";
			c -= (c / each[i]) * each[i];
		}
		cout << endl;
	}
}