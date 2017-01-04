#include <iostream>

using namespace std;

int main()
{
	int arr[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	int ck = 1;
	int ck1 = 1;
	for (int i = 0; i < 8; i++) {
		if (arr[i] != i + 1) {
			ck = 0;
		}
		if (arr[i] != 8 - i ) {
			ck1 = 0;
		}
	}
	if (!ck&&!ck1) cout << "mixed" << endl;
	else if (ck) cout << "ascending" << endl;
	else cout << "descending" << endl;
}