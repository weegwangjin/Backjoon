#include <iostream>
#include <string>

using namespace std;

int ck[4];
int main()
{
	char str[200][200];
	int cnt = 0;
	while (fgets(str[cnt], sizeof(str[cnt]), stdin) != NULL) {
		for (int i = 0; i < strlen(str[cnt]) - 1; i++) {
			if (str[cnt][i] >= 'a' && str[cnt][i] <= 'z') ck[0]++;
			else if (str[cnt][i] >= 'A' && str[cnt][i] <= 'Z') ck[1]++;
			else if (str[cnt][i] >= '0' && str[cnt][i] <= '9') ck[2]++;
			else ck[3]++;
		}
		cout << ck[0] << " " << ck[1] << " " << ck[2] << " " << ck[3] << endl;
		ck[0] = ck[1] = ck[2] = ck[3] = 0;
		cnt++;
	}
}