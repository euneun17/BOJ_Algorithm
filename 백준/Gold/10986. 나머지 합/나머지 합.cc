#include <iostream>
#include <vector>
using namespace std;

int N, M, x;
long long cnt[1001];
long long sum, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		sum += x;
		cnt[sum % M]++;
	}

	for (int i = 0; i <= 1000; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}

	cout << cnt[0] + ans;

	/* 아래처럼 하면 답은 맞는데 문제에서 n < 10^6 이므로 시간 초과
		int n, m;
		cin >> n >> m;
		int S[107] = {};
		int count = 0;

		for (int i = 1; i < n + 1; i++) {
			int temp;
			cin >> temp;
			S[i] = S[i - 1] + temp;
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = i; j < n + 1; j++) {
				if ((S[j] - S[i - 1]) % m == 0) {
					count++;
				}
			}
		}

		cout << count;
		*/

}