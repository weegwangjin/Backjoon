#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


struct node {
	int x, y;

};

struct compare_ {
	bool operator()(const node &a, const node &b) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
};
vector<node> vec;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node p = { a,b };
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end(),compare_());

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", vec[i].x, vec[i].y);
	}
}