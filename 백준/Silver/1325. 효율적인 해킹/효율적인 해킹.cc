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
void BFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m; cin >> n >> m;
	v.resize(n + 1); 
	visited = vector<bool>(n + 1, false); 
	result = vector<int>(n + 1, 0); 
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		BFS(i);
		fill(visited.begin(), visited.end(), false);
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (result[i] > max) max = result[i];
	}

	for (int i = 1; i <= n; i++) {
		if (result[i] == max) cout << i << " ";
	}
}

void BFS(int node) {
	queue<int> queue;
	queue.push(node); visited[node] = true;

	while (!queue.empty()) {
		for (int i : v[queue.front()]) {
			if (!visited[i]) {
				queue.push(i);
				visited[i] = true;
				result[i]++;
			}
		}
		queue.pop();
	}
}