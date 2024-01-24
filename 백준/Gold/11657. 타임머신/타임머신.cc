#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits.h> //INT_MAX 이용 목적

using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> edges;
static vector<long> result;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}

	result = vector<long>(n + 1, LONG_MAX);
	result[1] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int s = get<0>(edges[j]);
			int e = get<1>(edges[j]);
			int w = get<2>(edges[j]);

			if (result[s] != LONG_MAX && result[e] > result[s] + w) result[e] = result[s] + w;
		}
	}

	bool minus_cycle = false;
	for (int j = 0; j < m; j++) {
		int s = get<0>(edges[j]);
		int e = get<1>(edges[j]);
		int w = get<2>(edges[j]);

		if (result[s] != LONG_MAX && result[e] > result[s] + w) minus_cycle = true;
	}

	if (!minus_cycle) {
		for (int i = 2; i <= n; i++) {
			if (result[i] == LONG_MAX) cout << -1 << "\n";
			else cout << result[i] << "\n";
		}
	}
	else cout << -1;
}