#include <iostream>

using namespace std;

int pos[100];
int idx;
int main()
{
	int x, y;
	cin >> x >> y;
	int t;
	cin >> t;
	for (int i = 0; i < t+1;i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) pos[idx++] = -5 - b;
		if (a == 2) pos[idx++] = b;
		if (a == 3) pos[idx++] = -(y - b);
		if (a == 4) pos[idx++] = x + (y - b);
	}
	int ans = 0;
	for (int i = 0; i < idx - 1; i++) {
		ans += abs(pos[i] - pos[idx-1]);
	}
	cout << ans << endl;
}