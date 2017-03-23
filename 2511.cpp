#include <iostream>

using namespace std;

int main()
{
	int arr[10];
	bool ck = true;
	for (int i = 0; i < 10; i++) cin >> arr[i];
	int tot1 = 0;
	int tot2 = 0;
	int ck1 = 1;
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		if (arr[i] > a) {
			tot1 += 3;
			ck1 = 0;
			ck = true;
		}
		if (arr[i] == a) {
			tot1++;
			tot2++;
		}
		if (arr[i] < a) {
			tot2+=3;
			ck = false;
			ck1 = 0;
		}
	}
	cout << tot1 << " " << tot2 << endl;
	if (tot1 > tot2) cout << "A" << endl;
	if (tot1 == tot2) {
		if (ck1) cout << "D" << endl;
		else {
			if (ck) cout << "A" << endl;
			else cout << "B" << endl;
		}
	}
	if (tot1 < tot2) cout << "B" << endl;
}