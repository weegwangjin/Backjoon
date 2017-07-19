#include <stdio.h>
#include <iostream>
#include <string>

#define TRUE 1
#define FALSE 0
int index = 0;
int result = 0;

int decision_o(char *p) {
	if (p[index] != '1' || p[index + 1] != '0') return 0;
	index += 2;


	for (; p[index] == '0'; index++) {
		if (p[index] == NULL) return 0;
	}
	for (; p[index] == '1'; index++) {
		if (p[index] == NULL) return 3;
	}
	index++;
	if (p[index] == '1') {
		index--; return 2;
	}
	else {
		index -= 2; return 1;
	}
}

int decision_t(char *p) {
	if (p[index] != '0' || p[index + 1] != '1') return 0;
	index += 2;
	if (p[index] == NULL) {
		result = 1;
		return 3;
	}


	if (p[index] == '0') {
		return 2;
	}
	else {
		return 1;
	}
}
int main()
{

	int test_case =1;
	int i;
	int flag;
	//scanf_s("%d", &test_case);
	//for (i = 0; i < test_case; i++) {
		
		char *inte = (char*)malloc(sizeof(char) * 201);
		scanf_s("%s", inte);
		printf("%s", inte);
		
		if (inte[0] == '1') flag = 1;
		else flag = 2;
		while (1) {

			if (flag == 1) {
				if (decision_o(inte) == 0) { result = 0; break; }
				else if (decision_o(inte) == 1)
				{
					flag = 1; continue;
				}
				else if (decision_o(inte) == 3) {
					result = 1; break;
				}
				else {
					flag = 2; continue;
				}
			}
			else if (flag == 2) {
				if (decision_t(inte) == 0) { result = 0; break; }
				else if (decision_t(inte) == 1)
				{
					flag = 1; continue;
				}
				else if (decision_t(inte) == 3) {
					result = 1; break;
				}
				else {
					flag = 2; continue;
				}
			}
		}
	if (result == 0) printf("NO\n");
	else printf("YES\n");
	//}
	return 0;
}