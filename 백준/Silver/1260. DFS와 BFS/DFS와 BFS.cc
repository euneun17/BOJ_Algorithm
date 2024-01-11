#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

static bool result;
static vector<vector<int>> v;
static vector<bool> visited;
void DFS(int node);
void BFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, s;
	cin >> n >> m >> s;
	v.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) { //인접 배열을 오름차순 정렬
		sort(v[i].begin(), v[i].end());
	}

	DFS(s);
	fill(visited.begin(), visited.end(), false); //방문배열 값 다시 false로 초기화
	cout << "\n";
	BFS(s);
}

void DFS(int node) {
	
	if (!visited[node]) {
		cout << node << " ";
		visited[node] = true;
	}

	for (int i : v[node]) {
		if (!visited[i]) DFS(i);
	}

}

void BFS(int node){

	queue<int> queue;

	queue.push(node);
	visited[node] = true;
	while (!queue.empty()) {
		cout << queue.front() << " ";

		for (int i : v[queue.front()]) {
			if (!visited[i]) queue.push(i);
			visited[i] = true;
		}

		queue.pop();
	}
}