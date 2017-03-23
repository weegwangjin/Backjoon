#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> isVisit[10];
int num[26];
int sum[10];
bool ck[26];
int cnt;
int p[10];
char str[10][9];
int count_ = 0;
int n;
int max_ = -1;
void setting(int begin, int end) {
	int i, j;
	int range = end - begin;
	if (range == 1) {
		for (int q = 0; q<10; q++) {
			sum[q] = 0;
		}
		int sum_ = 0;
		for (i = 0; i<n; i++) {
			for (j = 0; j<strlen(str[i]); j++) {
				sum[i] += pow(10, strlen(str[i]) - j - 1)* num[(int)str[i][j] - 'A'];
			}
			sum_ += sum[i];
		}
		if (max_< sum_) {
			max_ = sum_;
		}
		//cout<<max_<<count_++<<endl;
		return;
	}

	i = cnt-1;
	while (i != -1) {
		
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	int idx = 0;
	for (i = 0; i<n; i++) {
		scanf("%s", str[i]);
		for (j = 0; j<strlen(str[i]); j++) {
			if (!ck[(int)str[i][j] - 'A']) {
				ck[(int)str[i][j] - 'A'] = true;
				cnt++;
				p[idx++] = str[i][j];
			}
		}
	}
	int k = 9;
	for (i = 0; i<cnt; i++) {

		num[p[i]] = k--;
		isVisit[i].push_back(k + 1);
	}
	setting(0, cnt);
	printf("%d", max_);

	return 0;
}
