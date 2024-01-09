#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		int abs_a = abs(a);
		int abs_b = abs(b);
		
		if (abs_a == abs_b) return a > b;
		else return abs_a > abs_b;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	vector<int> v(str.size());
	for (int i = 0; i < str.size(); i++) {
		v[i] = stoi(str.substr(i, 1));
	}

	for (int i = 0; i < str.size(); i++) {
		int max = i;
		for (int j = i; j < str.size(); j++) {
			if (v[j] > v[max]) max = j;
		}
		swap(v[i], v[max]);
	}

	for (int i = 0; i < str.size(); i++) {
		cout << v[i];
	}
}