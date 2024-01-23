#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> //INT_MAX 이용 목적

using namespace std;
typedef pair<int, int> edge; //모든 edge 구조는 (거리 값, 노드)로 통일

static vector<vector<edge>> list;
static vector<int> result;
static vector<bool> visited;
int dijkstra(int start, int end);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	list.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		list[a].push_back(edge(c, b));
	}

	int s, e; cin >> s >> e;
	result = vector<int>(n + 1, INT_MAX);
	result[s] = 0;
	visited.resize(n + 1);

	int answer = dijkstra(s, e);
	cout << answer;
}

int dijkstra(int start, int end) {
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(edge(0, start));

	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		if (visited[current.second]) continue;
		visited[current.second] = true;

		for (edge i : list[current.second]) {
			if (result[current.second] + i.first < result[i.second]) {
				result[i.second] = result[current.second] + i.first;
				pq.push(edge(result[i.second], i.second));
			}
		}
	}

	return result[end];
}