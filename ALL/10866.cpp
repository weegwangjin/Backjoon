#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> dq;


int main()
{
	int n;
	cin >> n;
	while (n--) {
		string a;
		cin >> a;
		if (a == "push_front") {
			int b;
			cin >> b;
			dq.push_front(b);
		}
		if (a == "push_back") {
			int b;
			cin >> b;
			dq.push_back(b);
		}
		if (a == "pop_front") {
			if (dq.empty()) cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		if (a == "pop_back") {
			if (dq.empty()) cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		if (a == "size") cout << dq.size() << endl;;
		if (a == "empty") {
			cout << (int)dq.empty() << endl;
		}
		if (a == "front") {
			if (dq.empty()) cout << -1 << endl;

			else cout << dq.front() << endl;
		}
		if (a == "back") {
			if (dq.empty()) cout << -1 << endl;
			else cout << dq.back() << endl;
		}
	}
}