#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

char map[65][65];
queue<char> qu;
void recur(int n,int st, int fi)
{
	int i,j;
	int d_x[4] = { 0,0,n / 2 ,n / 2 };
	int d_y[4] = { 0,n / 2,0,n / 2 };
	int f_y[4] = { n / 2-1,n - 1,n / 2-1,n-1};
	int f_x[4] = { n / 2-1 ,n / 2-1,n - 1,n-1};
	int ck = 0;
	int tmp;
	qu.push('(');
	for (int p = 0; p < 4; p++) {
		ck = 0;
		tmp = map[st+d_x[p]][fi+d_y[p]];
		for (i = st + d_x[p]; !ck&&i <= st+f_x[p];i++)
		{
			for (j = fi + d_y[p]; j <= fi+f_y[p]; j++) {
				if (tmp != map[i][j]) {
					ck = 1;
					break;
				}
			}
		}
		if (ck) {
			recur(n / 2, st + d_x[p], fi + d_y[p]);

		}
		else {
			qu.push(tmp);
		}
	}
	qu.push(')');
}

int main()
{

	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	int tmp = map[0][0];
	int ck = 0;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp != map[i][j]) {
				ck = 1;
			}
		}
	}
	if (!ck) {
		printf("%c", tmp);
		return 0;
	}
		
	recur(n,0,0);
	while (!qu.empty()) {
		printf("%c", qu.front());
		qu.pop();
	}
}