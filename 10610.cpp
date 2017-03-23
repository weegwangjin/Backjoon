#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string word;
	int sum = 0; 
	int ck = 0;
	int arr[100001];
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == '0') ck = i+1;
		sum += word[i] - '0';
	}
	if (!ck || sum % 3 != 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < word.length(); i++) arr[i] = word[i]-'0';
	sort(arr, arr + word.length());
	for (int i = 0; i < word.length(); i++) cout << arr[word.length() - 1 - i];

}