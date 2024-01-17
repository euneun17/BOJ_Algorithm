#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n; cin >> m >> n;
	vector<int> v(n + 1);
	for (int i = 2; i <= n; i++) {
		v[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (v[i] == 0) continue;
		for (int j = i + i; j <= n; j = j + i) {
			v[j] = 0;
		}
	}

	for (int i = m; i <= n; i++) { 
		if (v[i] != 0) cout << v[i] << "\n";
	}
}
