#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits.h> //INT_MAX 이용 목적

using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> edges;
static vector<long> result;
static vector<int> money;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, e, m; cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}

	money.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	result = vector<long>(n, LONG_MIN);
	result[s] = money[s];

	for (int i = 0; i <= n + 50; i++) {
		for (int j = 0; j < m; j++) {
			int s = get<0>(edges[j]);
			int e = get<1>(edges[j]);
			int w = get<2>(edges[j]);
			if (result[s] == LONG_MIN) continue;
			else if (result[s] == LONG_MAX) {
				result[e] = LONG_MAX;
			}
			else if (result[e] < result[s] - w + money[e]) {
				result[e] = result[s] - w + money[e];
				if (i >= n - 1) result[e] = LONG_MAX;
			}
		}
	}

	if (result[e] == LONG_MAX) cout << "Gee";
	else if (result[e] == LONG_MIN) cout << "gg";
	else cout << result[e];
}