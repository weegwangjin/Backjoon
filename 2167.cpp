#include <iostream>

using namespace std;

int val[301][301];

int main() {
	int n, m,i,j;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++)
			cin >> val[i][j];
	}
	int k,u;
	cin >> k;
	for (i = 0; i < k; i++) {
		int p, q, x, y;
		int sum = 0;
		cin >> p >> q >> x >> y;
		for (u = p; u <= x; u++) {
			for (j = q; j <= y; j++) {
				sum += val[u][j];
			}
		}
		cout << sum << endl;
	}
}