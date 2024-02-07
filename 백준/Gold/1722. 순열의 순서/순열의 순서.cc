#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	long fac[21]; fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	bool visited[21] = {false};
	int ans[21];

	int q; cin >> q;
	if (q == 1) {
		long k; cin >> k;

		for (int i = 1; i <= n; i++) {
			for (int j = 1, cnt = 1; j <= n; j++) {
				if (visited[j]) continue;

				if (k <= cnt * fac[n - i]) {
					k -= ((cnt - 1) * fac[n - i]);
					ans[i] = j;
					visited[j] = true;
					break;
				}
				cnt++;
			}
		}

		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
	}
	else if (q == 2) {
		long k = 1;

		for (int i = 1; i <= n; i++) {
			cin >> ans[i];
			long cnt = 0;

			for (int j = 1; j < ans[i]; j++) {
				if (!visited[j]) cnt++;
			}
			k += cnt * fac[n - i];
			visited[ans[i]] = true;
		}

		cout << k << "\n";
	}
}