#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x; cin >> x;
	int num = 64;
	int sum = 0;
	int cnt = 0;
	
	while (sum != x) {
		if (num + sum > x) {
			num /= 2;
			continue;
		}
		sum += num;
		cnt++;
		num /= 2;
	}

	cout << cnt;
}