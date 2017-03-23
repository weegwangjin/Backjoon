#include <iostream>
using namespace std;

int main()
{
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		char map[9];
		cin >> map;
		for (int j = 0; j < 8; j++) {
			if (map[j] == 'F') {
				if (((i+2) % 2 == 0 && (j+2) % 2 == 0) || ((i+2) % 2 == 1 && (j+2) % 2 == 1)) ans++;
			}
		}
	}
	cout << ans;
}