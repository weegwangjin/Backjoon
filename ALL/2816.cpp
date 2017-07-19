#include <iostream>
#include <string>
using namespace std;

int main()
{
	string channel[101];
	int n,i,j,idx_1,idx_2;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> channel[i];
		if (channel[i][0] == 'K'&&channel[i][1] == 'B'&&channel[i][2] == 'S'&&channel[i][3] == '1')
			idx_1 = i;
		if (channel[i][0] == 'K'&&channel[i][1] == 'B'&&channel[i][2] == 'S'&&channel[i][3] == '2')
			idx_2 = i;
	}
	if (idx_1 > idx_2) idx_2++;
	for (i = 1; i <= idx_1 - 1; i++) {
		cout << "1";
	}
	for (i = 1; i <= idx_1 - 1; i++) {
		cout << "4";
	}
	for (i = 1; i <= idx_2 - 1; i++) {
		cout << "1";
	}
	for (i = 1; i <= idx_2 - 2; i++) {
		cout << "4";
	}
}