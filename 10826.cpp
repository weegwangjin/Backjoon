#include <iostream>

using namespace std;

int num[3][3001];

int main()
{
	int n,i,j;
	cin >> n;
	num[0][3000] = 0;
	num[1][3000] = 1;
	num[2][3000] = 1;
	for (i = 3; i <= n; i++) {
		int ck1 = 0;
		if(i%3==0){
			for (j = 3000; j >= 0; j--) {
				num[0][j] = num[1][j] + num[2][j];
				if (ck1) num[0][j]++;
				ck1 = 0;
				if (num[0][j] > 9) {
					num[0][j] -= 10;
					num[0][j - 1]++;
					ck1 = 1;
				}
			}
		}
		if (i % 3 == 1) {
			for (j = 3000; j >= 0; j--) {
				num[1][j] = num[0][j] + num[2][j];
				if (ck1) num[1][j]++;
				ck1 = 0;
				if (num[1][j] > 9) {
					num[1][j] -= 10;
					ck1 = 1;
				}
			}
		}
		if (i % 3 == 2) {
			for (j = 3000; j >= 0; j--) {
				num[2][j] = num[1][j] + num[0][j];
				if (ck1) num[2][j]++;
				ck1 = 0;
				if (num[2][j] > 9) {
					num[2][j] -= 10;
					ck1 = 1;
				}
			}
		}
	}
	int ck = 0;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	for (j = 0; j <= 3000; j++) {
		if (num[n % 3][j] != 0) ck = 1;
		if(ck)cout << num[((n)%3)][j];
	}
}