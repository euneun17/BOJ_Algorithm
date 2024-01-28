#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> result;
void DFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	tree.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	visited.resize(n + 1);
	result.resize(n + 1);

	DFS(1);

	for (int i = 2; i <= n; i++) {
		cout << result[i] << "\n";
	}
}

void DFS(int node) {
	visited[node] = true;

	for (int i : tree[node]) {
		if (!visited[i]) {
			result[i] = node;
			DFS(i);
		}
	}
}