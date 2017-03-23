#include <iostream>

using namespace std;

int main()
{
	int n, L;
	cin >> n >> L;
	int now = 0;
	int time_ = 0;
	for (int i = 0; i < n; i++) {
		int D, R, G;
		cin >> D >> R >> G;
		time_ += (D-now);
		now = D;
		int diff = time_ % (R + G);
		if (diff >= R) continue;
		else {
			time_ += R - diff;
		}
		
	}
	cout << time_ + (L-now) << endl;
}