#include <iostream>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int S[100000] = {};
	for (int i = 1; i < n + 1; i++) {
		int temp;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << S[j] - S[i - 1] << "\n";
	}
}