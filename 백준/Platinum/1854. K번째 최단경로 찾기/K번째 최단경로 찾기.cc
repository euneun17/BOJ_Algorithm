#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> //INT_MAX 이용 목적

using namespace std;
typedef pair<int, int> edge; //모든 edge 구조는 (거리 값, 노드)로 통일

static vector<vector<edge>> list;
static vector<priority_queue<int>> result;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	list.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		list[a].push_back(edge(c, b));
	}
	result = vector<priority_queue<int>>(n + 1);

	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(edge(0, 1));
	result[1].push(0);

	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();

		for (edge i : list[current.second]) {
			if (result[i.second].size() < k) {
				result[i.second].push(current.first + i.first);
				pq.push(edge(current.first + i.first, i.second));
			}
			else if (result[i.second].top() > current.first + i.first) {
				result[i.second].pop();
				result[i.second].push(current.first + i.first);
				pq.push(edge(current.first + i.first, i.second));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (result[i].size() == k) {
			cout << result[i].top() << "\n";
		}
		else cout << -1 << "\n";
	}
}