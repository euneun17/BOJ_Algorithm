#include <iostream>

using namespace std;

static int n, m;
int solved(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << solved(n, m) << "\n";
	}
}

int solved(int a, int b) {
	int arr[30][30];

	for (int i = 1; i <= b; i++) {
		arr[i][i] = 1;
		arr[i][1] = i;
		arr[i][0] = 1;
	}

	for (int i = 2; i <= b; i++) {
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	return arr[b][a];
}