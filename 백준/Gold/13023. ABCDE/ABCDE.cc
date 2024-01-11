#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

static bool result;
static vector<vector<int>> v;
static vector<bool> visited;
void DFS(int node,int depth);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	v.resize(n);
	visited = vector<bool>(n, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	result = false;
	for (int i = 0; i < n; i++) {
		DFS(i, 1);

		if (result) {
			cout << 1;
			break;
		}
	}
	if (!result) cout << 0;
}

void DFS(int node, int depth) {
	if (result || depth == 5) {
		result = true;
		return;
	}

	visited[node] = true; //visited[node]; 되나??
	for (int i : v[node]) {
		if (!visited[i]) DFS(i, depth + 1);
	}
	visited[node] = false;
}