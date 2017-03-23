#include <iostream> 
#include <queue>
using namespace std;

int main() {
	queue<int> qu;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) qu.push(i);
	while (!qu.empty()) {
		cout << qu.front() << " ";
		qu.pop();
		if (qu.empty()) break;
		qu.push(qu.front());
		qu.pop();
	}
}