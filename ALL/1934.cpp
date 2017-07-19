#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		int i, j;
		cin >> a >> b;
		int t_a = a;
		int t_b = b;
		while (t_b%t_a != 0) {
			t_b %=t_a;
			int tmp = t_b;
			t_b = t_a;
			t_a = tmp;
		}
		cout << a*b / t_a << endl;
	}
}