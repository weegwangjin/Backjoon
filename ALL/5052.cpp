#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	
	int t;
	cin >> t;
	while (t--) {
		string arr[10000];
		int n;
		cin >> n;
		int ckk = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			int size_ = arr[i].length();
			int ck = 0;

			for (int k = i + 1; !ck&&k < n; k++) {
				for (int j = 0; j < size_; j++) {
					if (arr[i][j] != arr[k][j]) {
						ck = 1;
						break;
					}
				}
				if (!ck) {
					cout << "NO" << endl;
					ckk = 1;
					break;
				}
			}
			if (ckk) break;
		}
		if (!ckk) cout << "YES" << endl;

	}
}