#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;  cin >> t;

	int arr[15][15];
	for (int i = 0; i <= 14; i++) {
		arr[i][1] = 1;
		arr[0][i] = i;
	}
	
	for (int i = 1; i <= 14; i++) {
		for (int j = 2; j <= 14; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	for (int i = 0; i < t; i++) {
		int a, b; cin >> a >> b;
		cout << arr[a][b] << "\n";
	}
}