#include <cstdio>
using namespace std;
int main() {
	int n, i, j;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) {
			if (j > i) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

}