#include <iostream>
#include <cmath>

using namespace std;

int n;
int m;
int o_d_1, o_d_2;
int min_ = 999999999;
int run[21];

void recur(int o_d_1_, int o_d_2_, int step, int sum) {
	if (step == m + 1) {
		if (min_ > sum) {
			min_ = sum;
		}
		return;
		
	}
	recur(run[step], o_d_2_, step + 1, sum + abs(o_d_1_ - run[step]));
	recur(o_d_1_, run[step], step + 1, sum + abs(o_d_2_ - run[step]));
}

int main()
{
	cin >> n;
	cin >> o_d_1 >> o_d_2>>m;
	for (int i = 1; i <= m; i++) {
		cin >> run[i];
	}
	recur(o_d_1, o_d_2, 1, 0);
	cout << min_ << endl;
}