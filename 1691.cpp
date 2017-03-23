#include <iostream>
#include <queue>
using namespace std;

typedef struct nodetype {
	int val;
	int level;
}Node;
queue<Node> qu;
int min_;
int visit[1000000];
int main()
{
	int n, k, i;
	cin >> n >> k;
	if (n == k) {
		cout << 0 << endl;
		return 0;
	}
	if (n > k) {
		cout << n - k << endl;
		return 0;
	}
	Node start = { n,0 };
	qu.push(start);

	while (!qu.empty()) {
		visit[qu.front().val] = 1;
		Node a = { qu.front().val - 1,qu.front().level + 1 };
		Node b = { qu.front().val + 1,qu.front().level + 1 };
		Node c = { qu.front().val * 2,qu.front().level + 1 };
		int a_ck = 0;
		int b_ck = 0;
		int c_ck = 0;
		if (a.val >= 0) {
			if (visit[a.val] == 1)
				a_ck = 1;
		}
		if (visit[b.val] == 1)
			b_ck = 1;
		if (visit[c.val] == 1)
			c_ck = 1;
		if (a.val == k || b.val == k || c.val == k) {
			min_ = a.level;
			break;
		}
		if (a.val >= 0 && !a_ck) {
			visit[a.val] = 1;
			qu.push(a);
		}
		if (b.val >= 0&& !b_ck && (a.val != b.val)&&qu.front().val <k) {
			visit[b.val] = 1;
			qu.push(b);
		}
		if (c.val >= 0&& !c_ck && (c.val != a.val && c.val != b.val) && qu.front().val <k) {
			visit[c.val] = 1;
			qu.push(c);
		}
		qu.pop();

	}
	cout << min_ << endl;
}