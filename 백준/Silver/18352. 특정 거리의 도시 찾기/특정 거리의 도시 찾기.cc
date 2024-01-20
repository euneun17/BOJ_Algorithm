#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

static int x;
static vector<int> visited;
static vector<vector<int>> v;
void BFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k >> x;
	v.resize(n+1);
	visited = vector<int>(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	BFS(x);
	bool find = false;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == k) {
			find = true;
			cout << i << "\n";
		}
	}
	if (!find) cout << -1;
}

void BFS(int node) {
	queue<int> queue;
	queue.push(node);
	while (!queue.empty()) {
		for (int i : v[queue.front()]) {
			if (visited[i] == 0 && i != x) {
				queue.push(i);
				visited[i] = visited[queue.front()] + 1;
			}
		}
		queue.pop();
	}
}