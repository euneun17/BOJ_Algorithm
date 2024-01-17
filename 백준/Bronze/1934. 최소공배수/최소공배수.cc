#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>

using namespace std;

int gcd(int a, int b);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;

		cout << a * b / gcd(a, b) << "\n";
	}
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}