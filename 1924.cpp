#include <iostream>
#include <string>
using namespace std;

string date[7] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT" };
int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	int m, d;
	cin >> m >> d;
	int sum = 0;
	for (int i = 0; i < m-1; i++) {
		sum += day[i];
	}
	sum += d;
	cout << date[sum % 7] << endl;
}