#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	vector<vector<int>> A(n + 1, vector<int>(n + 1, 0)); //D[0][n] ~ D[n][0]을 고려해야하기에 열과 행의 크기는 n+1
	vector<vector<int>> D(n + 1, vector<int>(n + 1, 0)); //2차원 합 배열

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> A[i][j];

			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + A[i][j];
		}
	}

	for (int k = 0; k < q; k++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << D[c][d] - D[c][b - 1] - D[a - 1][d] + D[a - 1][b - 1] << "\n";
	}
}