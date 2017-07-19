#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.get();
	while (T--) {
		char ch[1001];
		int i, j;
		cin.getline(ch, 1001);
		i = 0;
		while (true) {
			stack<char> st;
			while (ch[i] != ' ' && ch[i] !=NULL) {
				st.push(ch[i]);
				i++;
			}
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
			if (ch[i] == NULL)
				break;
			i++;
		}
		cout << endl;
	}
}