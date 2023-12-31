#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
	int cnt[26] = { 0, };

	string str;
	cin >> str;

	for (char i = 'a'; i <= 'z'; i++) {
		cout << (int)str.find(i) << ' ';
	}

	return 0;
}