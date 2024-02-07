#include <iostream>
#include <vector>

using namespace std;

static int n, m, k;
static long D[202][202];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				D[i][j] = 1;
			}
			else {
				D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
				if (D[i][j] > 1000000000) D[i][j] = 1000000001;
			}
		}
	}

	if (D[n + m][m] < k) cout << "-1";
	else {
		while (!(n == 0 && m == 0)) {
			if (D[n + m - 1][m] >= k) { //a를 선택할 경우 경우의 수 내에 k가 존재하면
				cout << "a";
				n--;
			}
			else if (D[n + m - 1][m] < k) {
				cout << "z";
				k = k - D[n + m - 1][m];
				m--;
			}
		}
	}
}