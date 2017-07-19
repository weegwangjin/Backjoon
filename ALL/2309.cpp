#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int key[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> key[i];
		sum += key[i];
	}
	sort(key, key + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (key[i] + key[j] == sum - 100) {
				for (int p = 0; p < 9; p++) {
					if (p != i && p != j) {
						cout << key[p] << endl;
						
					}
				}
				return 0;
			}
		}
	}
}
