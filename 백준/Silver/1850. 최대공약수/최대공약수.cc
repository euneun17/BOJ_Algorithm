#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>

using namespace std;

long gcd(long a, long b);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long a, b;
	cin >> a >> b;
	long result = gcd(a, b);

	while (result > 0) {
		cout << 1;
		result--;
	}
	cout << '\n';
}

long gcd(long a, long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}