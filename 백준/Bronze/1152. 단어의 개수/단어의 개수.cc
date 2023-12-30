#include <iostream>
#include <string>
using namespace std;

int main(){
	int result = 0;
	string str;
	getline(cin, str);

	result = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			result++;
		}
	}
	if (str[0] == ' ') {
		result--;
	}
	if (str[str.length() - 1] == ' ') {
		result--;
	}

	cout << result << "\n";
	return 0;
}