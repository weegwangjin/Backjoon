#include <iostream>

using namespace std;

int dir = 1;
int main() {
	int m, n;
	cin >> m >> n;
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		char str[5];
		int k;
		cin >> str >> k;
		if (str[0] == 'T') {
			dir += (k == 0) ? -1 : 1;
			if (dir == 0) dir += 4;
			if (dir == 5) dir -= 4;
			continue;
		}
		switch (dir) {
		case 1:
			x += k;
			break;
		case 2:
			y -= k;
			break;
		case 3:
			x -= k;

			break;
		case 4:
			y += k;
			break;
		}
		if (x < 0 || y<0 || x >m | y>m) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << x<<" " << y << endl;
}