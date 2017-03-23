#include <iostream>
#include <string>

using namespace std;

string map[25];
int cnt[625];
int visit = 1;
int n;
void recur(int x, int y) {
	map[x][y] = visit + '0';
	cnt[visit]++;
	if (x - 1 >= 0 && map[x - 1][y] == '1') {
		recur(x - 1, y);
	}
	if (x + 1 < n && map[x + 1][y] == '1') {
		recur(x + 1, y);
	}
	if (y - 1 >= 0 && map[x][y-1] =='1') {
		recur(x , y-1);
	}
	if (y +1 < n && map[x][y+1] == '1') {
		recur(x , y+1);
	}
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == 1 + '0') {
				visit++;
				recur(i, j);
				
			}
		}
	}
	cout << visit - 1 << endl;
	for (i = 2; i <= visit-1; i++) {
		for (j = 2; j <= visit-1; j++) {
			if (cnt[j] > cnt[j + 1]) {
				int tmp = cnt[j];
				cnt[j] = cnt[j + 1];
				cnt[j + 1] = tmp;
			}
		}
	}
	for (i = 2; i <= visit; i++) {
		cout << cnt[i] << endl;
	}
}