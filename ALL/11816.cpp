#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;
	if (a[0] != 0) cout << a;
	else if( a[1]!='x')cout << stoi(a, 0, 8);
	else cout << stoi(a, 0, 16);
	
}