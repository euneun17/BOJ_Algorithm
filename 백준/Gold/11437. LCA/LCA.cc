#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int n, m;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

int LCA(int index1, int index2);
void BFS(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> n;
	tree.resize(n+1);
	depth.resize(n+1);
	parent.resize(n+1);
	visited.resize(n+1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	BFS(1); //depth 구하는 목적

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	//a가 더 트리 아래쪽에 있는 경우로 표준화
	while (depth[a] != depth[b]) a = parent[a];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

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
				parent[i] = queue.front();
				depth[i] = depth[queue.front()] + 1;
			}
		}
		queue.pop();
	}
}