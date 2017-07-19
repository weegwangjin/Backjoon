#include <cstdio>


int arr[10001];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		arr[k]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (arr[i] != 0) {
			printf("%d\n", i);
			arr[i]--;
		}
	}
}