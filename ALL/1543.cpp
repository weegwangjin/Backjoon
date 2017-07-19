#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	char str[3000];
	fgets(str, sizeof(str), stdin);
	char comp[100];
	fgets(comp, sizeof(comp), stdin);
	int str_size = strlen(str)-1;
	int comp_size = strlen(comp)-1;
	int ans = 0;
	for (int i = 0; i < str_size; i++) {
		if (str[i] == comp[0]) {
			int ck = 0;
			for (int j = 0; j < comp_size; j++) {
				if (str[i + j] != comp[j]) {
					ck = 1;
					break;
				}
			}
			if (!ck) {
				ans++;
				i += comp_size-1;
			}
		}
	}
	cout << ans << endl;
}