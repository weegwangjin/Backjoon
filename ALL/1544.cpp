#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string str[51];
	string t_str[51];
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		t_str[i] = str[i] + str[i].substr(0, str[i].length() - 1);
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == " ") continue;
		ans++;
		for (int j = i+1; j < n; j++) {
			int size_ = str[j].length();
			int size_1 = str[i].length();
			if (size_ != size_1) continue;
			for (int k = 0; k < size_ * 2; k++) {
				int idx = k%size_;
				if (str[i][0] == str[j][idx]) {
					int cnt = 0;
					for (int p = 0; p < size_1; p++) {
						if (str[i][p] == str[j][(idx + p)%size_]) cnt++;
					}
					if (cnt == size_1) {
						str[j] = " ";
						break;
					}
				}
			}
		}
	}
	cout << ans << endl;
}