#include <iostream>

using namespace std;

int min_level = 99999999;
void recur1(int n, int level) {
	if (n == 1) {
		if (min_level > level) {
			min_level = level;
		}
		return;
	}
	if (min_level < level) {
		return;
	}
	if(n%3==0)
		recur1(n / 3, level + 1);
	if(n%2==0)
		recur1(n / 2, level + 1);
	recur1(n - 1, level + 1);
}
int main()
{
	int n;
	cin >> n;
	recur1(n, 0);

	cout << min_level;
	


}