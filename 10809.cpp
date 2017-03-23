#pragma warning(disable:4996)
#include <cstdio>
#include <string>
char arr[101];
int ck[26];
int main() {
	char arr[101];
	scanf("%s", arr);
	int i;
	for (i = 0; i < 26; i++) ck[i] = -1;
	for (i = 0; i < strlen(arr); i++) {
		if (ck[arr[i] - 'a'] == -1) ck[arr[i] - 'a'] = i;
	}
	for (i = 0; i < 26; i++) printf("%d ", ck[i]);
}
