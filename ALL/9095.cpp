#include <iostream>

using namespace std;
int n;
int cnt;
int count_[11] = { 1,1,2,4 };
/*void recur(int num, int sum_) {
	num = num + sum_;
	if (num == n) {
		cnt++;
		return;
	}
	if(num+1 <=n)
		recur(num, 1);
	if(num+2<=n)
		recur(num, 2);
	if(num+3<=n)
		recur(num, 3);
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		recur(0, 1);
		recur(0, 2);
		recur(0, 3);
		cout << cnt<<endl;
		cnt = 0;
	}
} method 1 */
int main()
{
	int t;
	cin >> t;
	for (int i = 4; i < 11; i++) {
		count_[i] = count_[i - 1] + count_[i - 2] + count_[i - 3];
	}
	while (t--) {
		cin >> n;
		cout << count_[n] << endl;
	}
}