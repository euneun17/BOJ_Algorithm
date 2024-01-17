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
	
	const int MAX = 10000000;
	long m, n; cin >> m >> n;
	vector<long> v(MAX + 1);
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

	long result = 0;
	for (int i = 2; i <= MAX; i++) {
		if (v[i] == 0) continue;

		long tmp = v[i];
		while ((double)v[i] <= (double)n / (double)tmp) {
			if ((double)v[i] >= (double)m / (double)tmp) result++;
			tmp = tmp * v[i];
		}
	}

	cout << result;
}
