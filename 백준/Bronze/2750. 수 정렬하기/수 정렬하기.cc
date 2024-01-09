#include <iostream>
#include <vector>
#include <queue>
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

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = n; i > 0; i--) {
		for (int j = 1; j < i; j++) {
			if (v[j - 1] > v[j]) {
				swap(v[j - 1], v[j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
}