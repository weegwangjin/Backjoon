#include <cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int j = n; j >= 1; j--) {
		for (int i = 1; i <= j; i++)
			printf("*");
		printf("\n");
	}
}