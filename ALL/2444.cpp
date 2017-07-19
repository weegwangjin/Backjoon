#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int size_ = 2 * n - 1;
	int k = 0;
	for (int i = 1; i <= size_; i++) {
		for (int j = 1; j <= size_; j++) {
			if (j <= (size_ + 1) / 2 + k && j >= (size_ + 1) / 2 - k) {
				cout << "*";
			}
			else if (j < (size_ + 1) / 2 - k) {
				cout << " ";
			}
		}
		if (i < (size_ + 1) / 2) k++;
		else k--;
		cout << endl;
	}
}