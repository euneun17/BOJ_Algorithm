#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

static vector<bool> visited;
static vector<vector<int>> v;
static vector<int> result;
static bool isEven;
void DFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, e; cin >> n >> e;
		v.resize(n + 1);
		visited.resize(n + 1);
		result.resize(n + 1);
		isEven = true;
		for (int i = 0; i < e; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
            v[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (isEven) DFS(i);
			else break;
		}

		if (isEven) cout << "YES" << "\n";
		else cout << "NO" << "\n";

		for (int j = 0; j <= n; j++) {
			v[j].clear();
			visited[j] = false;
			result[j] = 0;
		}
	}
}

void DFS(int node) {
	visited[node] = true;

	for (int i : v[node]) {
		if (!visited[i]) {
			result[i] = (result[node] + 1) % 2;
			DFS(i);
		}
		else if (result[i] == result[node])
			isEven = false;
	}
}