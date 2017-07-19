#include <iostream>

using namespace std;

int cost[1000][3];
int min_cost = 999999999;
int n;

void recur(int sum, int level, int color) {
	if (level == n) {
		if (min_cost > sum) {
			min_cost = sum;
		}
		return;
	}
	if (color == 0) {
		recur(sum + cost[level][color], level + 1, 1);
		recur(sum + cost[level][color], level + 1, 2);

	}
	else if (color == 1) {
		recur(sum + cost[level][color], level + 1, 0);
		recur(sum + cost[level][color], level + 1, 2);
	}
	else {
		recur(sum + cost[level][color], level + 1, 0);
		recur(sum + cost[level][color], level + 1, 1);
	}
}
int main()
{
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	recur(0, 0, 0);
	recur(0, 0, 1);
	recur(0, 0, 2);

	cout << min_cost << endl;
}