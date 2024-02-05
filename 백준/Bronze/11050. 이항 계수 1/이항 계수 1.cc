#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;
	int arr[11][11];
	for (int i = 1; i <= n; i++) {
		arr[i][1] = i;
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	cout << arr[n][k];
}