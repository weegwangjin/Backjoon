#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string str[500000];
string str_[500000];
string result[500000];
int idx;
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> str[i];
	for (int i = 0; i < m; i++) cin >> str_[i];
	sort(str, str + n);
	sort(str_, str_ + m);
	int ans = 0;
	for (int i = 0, j = 0;i<n&&j<m;) {
		if (str[i] == str_[j]) {
			ans++;
			result[idx++] = str[i];
			i++;
			j++;
		}
		else if (str[i] > str_[j]) j++;
		else i++;
	}
	cout << ans << endl;
	for (int i = 0; i < idx; i++) cout << result[i] << endl;
}