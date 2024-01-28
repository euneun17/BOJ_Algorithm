#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int result = 0;
int delete_node;
void DFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	tree.resize(n);
	int root;
	for (int i = 0; i <= n - 1; i++) {
		int a; cin >> a;
		if (a == -1) root = i;
		else {
			tree[i].push_back(a);
			tree[a].push_back(i);
		}
	}
	visited.resize(n);

	cin >> delete_node;

 	DFS(root);

	if (delete_node == root) cout << 0;
	else cout << result;
}

void DFS(int node) {
	visited[node] = true;

	int cNode = 0;
	for (int i : tree[node]) {
		if (!visited[i] && i != delete_node) {
			cNode++;
			DFS(i);
		}
	}
	if (cNode == 0) {
		result++;
	}
}