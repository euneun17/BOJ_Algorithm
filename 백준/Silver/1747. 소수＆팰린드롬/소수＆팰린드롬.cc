#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>

using namespace std;

bool isPalindrome(int target);
vector<long> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	const int MAX = 10000000;
	long n; cin >> n;
	v.resize(MAX + 1);
	v[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		v[i] = i;
	}

	for (int i = 2; i <= sqrt(MAX); i++) { //에라토스테네스의 체
		if (v[i] == 0) continue;
		for (int j = 2 * i; j <= MAX; j = j + i) {
			v[j] = 0;
		}
	}

	int i = n;
	while (true) {
		if (v[i] != 0) {
			if (isPalindrome(i)) {
				cout << v[i];
				break;
			}
		}
		i++;
	}
	
	return 0;
}

bool isPalindrome(int target) {
	string tmpStr = to_string(target);
	const char* tmpChar = tmpStr.c_str();
	int s = 0, e = tmpStr.size() - 1;
	while (s < e) {
		if (tmpChar[s] != tmpChar[e]) return false;
		s++; e--;
	}
	return true;
}
