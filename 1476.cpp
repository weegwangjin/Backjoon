#include <iostream>
#include <string>
using namespace std;


int main()
{
	int e, s, m;
	cin >> e >> s >> m;
	int t_e = 0;
	int t_s = 0;
	int t_m = 0;
	int ans = 0;
	while (!(t_e==e && t_s == s && t_m == m)) {
		t_e = (t_e % 15) + 1;
		t_s = (t_s % 28) + 1;
		t_m = (t_m % 19) + 1;
		ans++;
	}
	cout << ans << endl;
}