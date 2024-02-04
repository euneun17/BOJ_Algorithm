#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

static int n, m;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<bool> visited;

static int kmax; 
static int parent[21][100001];;

int LCA(int a, int b);
void BFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	tree.resize(n+1);
	depth.resize(n + 1);
	visited.resize(n+1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int temp = 1; kmax = 0;
	while (temp < n) {
		temp *= 2;
		kmax++;
	}

	BFS(1);

	//부모 배열 채우기(2^0, 2^1, 2^2 ... 단계 부모 노드)
	for (int k = 1; k <= kmax; k++) {
		for (int i = 1; i <= n; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);

	//깊이 맞추기
	//a가 b보다 위에 있다고 가정
	for (int k = kmax; k >= 0; k--) {
		if (pow(2, k) <= depth[b] - depth[a]) b = parent[k][b];
	}

	//최소 공통 부모 찾기
	for (int k = kmax; k >= 0 && a != b; k--) {
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}
	if (a != b) a = parent[0][a];

	return a;
}

void BFS(int node) {
	queue<int> queue;
	queue.push(node);
	visited[node] = true;
	
	while (!queue.empty()) {
		for (int i : tree[queue.front()]) {
			if (!visited[i]) {
				queue.push(i);
				visited[i] = true;
				parent[0][i] = queue.front();
				depth[i] = depth[queue.front()] + 1;
			}
		}
		queue.pop();
	}
}