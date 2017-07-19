#include <iostream>

using namespace std;


int triangle_n[41];
bool check[1001];

int main() {
	int i, j, p;
	for (i = 1; i <= 40; i++) {
		triangle_n[i] = (i*(i + 1)) / 2;
	}
	for (i = 1; i <= 40; i++) {
		for (j = i;  j <= 40; j++) {
			for (p = j;  p <= 40; p++) {
				if (triangle_n[i] + triangle_n[j] + triangle_n[p] > 1000) {
					break;
				}
				check[triangle_n[i] + triangle_n[j] + triangle_n[p]] = 1;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		cout << check[k] << endl;
	}
}