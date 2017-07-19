#include <cstdio>

int st[100001];
int top = 0;
int idx = 0;
int idx1 = 1;
char ret[200001];
int main() {
	int n, i;
	int cnt = 0;
	int now = 1;
	int arr[100001];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	st[0] = 1;
	ret[0] = '+';
	while (cnt != n) {
		if (now>n) {
			printf("NO\n");
			return 1;
		}
		if (top == -1) {
			st[++top] = ++now;
			ret[idx1++] = '+';
			continue;
		}
		if (st[top] == arr[idx]) {
			top--;
			ret[idx1++] = '-';
			cnt++;
			idx++;
			continue;
		}
		st[++top] = ++now;
		ret[idx1++] = '+';
	}

	for (i = 0; i < idx1; i++) {
		printf("%c\n", ret[i]);
	}

}