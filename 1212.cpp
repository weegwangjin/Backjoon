#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string.h>
int arr[8][3] = { {0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1} };

int main() {
	char str[333446];
	scanf("%s", str);
	int k = strlen(str);
	for (int i = 0; i < k; i++) {
		int t = (int)(str[i]-'0');
		if (i == 0 && arr[t][0]==0) {
			if (arr[t][1] == 0) {
				printf("%d", arr[t][2]);
				continue;
			}
			if (arr[t][1] == 0 && arr[t][2] == 0) {
				printf("0");
				continue;
			}
			printf("%d%d", arr[t][1], arr[t][2]);
		}
		else {
			printf("%d%d%d", arr[t][0],arr[t][1], arr[t][2]);
		}
	}
}