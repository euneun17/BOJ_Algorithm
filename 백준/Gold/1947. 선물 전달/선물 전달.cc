#include <iostream>

using namespace std;

static int n;
static int mod = 1000000000;
static long D[1000001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; D[1] = 0; D[2] = 1;

	for (int i = 3; i <= n; i++) {
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % mod;
	}

	cout << D[n];
}