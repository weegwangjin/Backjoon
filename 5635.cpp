#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct person {
	int d, m, y;
	char name_[20];

};

struct compare_ {
	bool operator()(const person& b,const person& a) {
		if (b.y < a.y) {
			return true;
		}
		else if (b.y == a.y) {
			if (b.m < a.m) {
				return true;
			}
			else if (b.m == a.m) {
				if (b.d < a.d) {
					return true;
				}
				else return false;
			}
			else {
				return false;
			}
		}
		else return false;
	}
};
person ps[101];
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d", &ps[i].name_, &ps[i].d, &ps[i].m, &ps[i].y);

	}
	sort(ps, ps + n, compare_());
	cout << ps[n - 1].name_ << endl << ps[0].name_ << endl;
}