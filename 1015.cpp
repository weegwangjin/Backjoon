#include <stdio.h>

int main()
{
	int arr[1001];
	int n,j,i;
	int tmp[1001];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	int count = 0;
	for (i = 0; i < n; i++) {
		int min = arr[0];
		int tmp1;
		int check = 0;
		for (j = 0; j < n; j++) {
			if (min > arr[j]) {
				min = arr[j];
				tmp[j] = count;
				tmp1 = j;
				check = 1;
			}
		}
		if (check == 0) {
			arr[0] = 1000;
			tmp[0] = count;
			count++;
			continue;
		}
		arr[tmp1] = 1000;
		count++;
	}
	for (i = 0; i < n; i++) {
		printf("%d ",tmp[i]);
	}
}