#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int size_ = 2 * n - 1;
	int k = 1;
	for (int i = 1; i <= size_; i++) {
		for (int j = 1; j <= size_+1; j++) {
			if (j <= k || j >= size_+2 - k) {
				cout << "*";
			}
			else cout << " ";
		}
		cout << endl;
		k = (i < (size_+1)/2) ? k + 1 : k - 1;
	}
}