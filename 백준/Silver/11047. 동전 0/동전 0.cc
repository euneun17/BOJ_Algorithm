#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);

	int result = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] <= k) {
			result += k / v[i];
			k = k % v[i];
		}
		if (k == 0) break;
	}

	cout << result;
}