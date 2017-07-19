#include <iostream>
#include <string>

using namespace std;


int r, c;
string map[21];
int visit[26];
int max_;

void recur(int x, int y, int step)
{

	if (visit[map[x][y] - 'A'] == 1) {
		if (max_ < step-1) {
			max_ = step-1;
		}
		return;
	}

	visit[map[x][y] - 'A'] = 1;
	if (x + 1 <= r) {
		recur(x + 1, y, step + 1);
	}
	if (x - 1 >= 1) {
		recur(x - 1, y, step + 1);
	}
	if (y - 1 >= 0) {
		recur(x, y - 1, step + 1);

	}
	if (y + 1 < c) {
		recur(x, y + 1, step + 1);
	}
	visit[map[x][y] - 'A'] = 0;
}
int main()
{
	cin >> r >> c;
	int i, j;

	for (i = 1; i <= r; i++) {
		cin >> map[i];
	}
	recur(1, 0, 1);
	cout << max_ << endl;
}