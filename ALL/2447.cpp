#include <iostream>
#include <cmath>
using namespace std;

char map[6500][6500];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 6500; i++) {
		for (int j = 0; j < 6500; j++) {
			map[i][j] = ' ';
		}
	}
	map[0][0] = '*';
	if (n == 1) {
		cout << map[0][0];
		return 0;
	}
	for (int i = 1; pow(3,i) <= n; i++) {
		int size = pow(3, i);
		int x = 0;
		int y = 0;
		for (int j = 0; j < size; j++) {
			for (int p = 0; p < size; p++) {
				if (j < (size / 3) * 2 && j >= size / 3 && p < (size / 3) * 2 && p >= size / 3) continue;
				map[j][p] = map[(x++)%(size/3)][y];
			}
			y = (y + 1) % (size / 3);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

}