#include <iostream>

using namespace std;

int main() {

	
	int t;
	string s;
	int score;
	int oCnt;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> s;
		
		score = 0;
		oCnt = 1;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') score += oCnt++;
			else if (s[i] == 'X') oCnt = 1;
		}

		cout << score << '\n';
	}


	return 0;
}