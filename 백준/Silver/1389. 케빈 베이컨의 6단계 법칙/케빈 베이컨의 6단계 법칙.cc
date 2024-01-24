#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits.h> //INT_MAX 이용 목적

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	long arr[101][101];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else arr[i][j] = 10000001;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[k][j] + arr[i][k] < arr[i][j]) arr[i][j] = arr[k][j] + arr[i][k];
			}
		}
	}

	int min = INT_MAX;
	int answer = -1;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += arr[i][j];
		}
		if (tmp < min) {
			min = tmp;
			answer = i;
		}
	}
	cout << answer;
}