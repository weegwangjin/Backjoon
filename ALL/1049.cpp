#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int pac[50], each[50];
	for (int i = 0; i < m; i++) {
		cin >> pac[i] >> each[i];
	}
	int answer = 0;
	sort(pac, pac + m);
	sort(each, each + m);
	while(n != 0) {
		if (n >= 6) {
			int tmp = min(pac[0], each[0] * 6);
			n -= 6;
			answer += tmp;
		}
		else {
			if (each[0] * n < pac[0]) {
				answer += each[0] * n;
			}
			else {
				answer += pac[0];
			}
			n = 0;
		}
	}
	cout << answer << endl;
}