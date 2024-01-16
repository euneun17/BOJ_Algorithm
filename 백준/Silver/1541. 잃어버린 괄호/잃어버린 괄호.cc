#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string input, char delim);
int sum(string input);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;
	string str; cin >> str;

	vector<string> delimByMinus = split(str, '-');
	for (int i = 0; i < delimByMinus.size(); i++) {
		int tmp = sum(delimByMinus[i]);
		if (i == 0) answer = tmp;
		else answer -= tmp;
	}

	cout << answer;
}

vector<string> split(string input, char delim) {
	vector<string> result;
	stringstream ss(input);
	string splitData;

	while (getline(ss, splitData, delim)) {
		result.push_back(splitData);
	}
	return result;
}

int sum(string input) {
	int sum = 0;
	vector<string> plusData = split(input, '+');

	for (int i = 0; i < plusData.size(); i++) {
		sum += stoi(plusData[i]);
	}
	return sum;
}
