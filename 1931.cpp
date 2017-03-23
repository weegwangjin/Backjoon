#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int start;
	int finish;
};
bool compare(const Node &a, const Node &b)
{
	if (a.finish == b.finish)
		return a.start > b.start;
	return a.finish > b.finish;
}

Node time_[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> time_[i].start>>time_[i].finish;
	}
	sort(time_, time_ + n,compare);
	
	int cnt = 1;
	int n_s = time_[0].start;
	int n_f = time_[0].finish;
	for (int i = 1; i < n; i++) {
		if (n_s >= time_[i].finish) {
			cnt++;
			n_s = time_[i].start;
			n_f = time_[i].finish;
		}
		else {
			if (n_s < time_[i].start) {
				n_s = time_[i].start;
				n_f = time_[i].finish;
			}
		}
	}
	cout << cnt << endl;
}