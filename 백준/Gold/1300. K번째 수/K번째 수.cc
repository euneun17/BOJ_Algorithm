#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long n, k;
	cin >> n >> k;

	int result = 0;
	int s = 1;
	int e = k;

	while (s <= e) {
		long mid = (s + e) / 2;
		int count = 0;

		for (int i = 1; i <= n; i++) {
			count += min(mid / i, n);
		}

		if (count < k) s = mid + 1;
		else {
			e = mid - 1;
			result = mid;
		}
	}
	cout << result;
}