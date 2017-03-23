#include <iostream>

using namespace std;

int map[101][101];
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				map[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j]) ans++;
		}
	}
	cout << ans << endl;
}