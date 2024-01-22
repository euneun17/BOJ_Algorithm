#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> degree(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}

	queue<int> queue;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			queue.push(i);
		}
	}
	while (!queue.empty()) {
		cout << queue.front() << " ";
		for (int i : v[queue.front()]) {
			degree[i]--;
			if (degree[i] == 0) queue.push(i);
		}
		queue.pop();
	}
}