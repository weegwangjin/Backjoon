#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int main()
{
	char str[101];
	while (fgets(str, sizeof(str), stdin) != NULL) {
		printf("%d\n", str[0]-'0' + str[2]-'0');
	}
}