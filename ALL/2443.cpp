#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int size_ = 2 * n - 1;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 1; j <= size_; j++) {
			if (j <= (size_ + 1) / 2 + i && j >= (size_ + 1) / 2 - i) {
				cout << "*";
			}
			else if (j< (size_ + 1) / 2 - i) cout << " ";
		}
		cout << endl;
	}
}