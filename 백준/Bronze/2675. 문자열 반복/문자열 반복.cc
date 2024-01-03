#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	int r = 0;
	string str;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &r);
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			for (int k = 0; k < r; k++) {
				cout << str[j];
			}
		}
		cout << "\n";
	}
}