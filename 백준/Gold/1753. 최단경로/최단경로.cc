#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> //INT_MAX 이용 목적

using namespace std;
typedef pair<int, int> edge; //모든 edge 구조는 (거리 값, 노드)로 통일

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	int k; cin >> k;

	vector<vector<edge>> list(n + 1); //인접 리스트 생성
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		list[a].push_back(edge(c, b));
	}

	vector<int> result(n + 1, INT_MAX); //결과배열 초기화(시작 노드는 0, 나머지는 INT_MAX)
	result[k] = 0;

	vector<bool> visited(n + 1);
	priority_queue<edge, vector<edge>, greater<edge>> pq; //작은 수부터 우선 정렬
	pq.push(edge(0, k)); //시작노드 pq에 삽입

	while (!pq.empty()) {
		edge current = pq.top(); //현재 인접하여 push된 값 중 가장 작은 값 선택
		pq.pop();
		visited[current.second] = true; //push 기준이 아닌 pop 시점에 visited 체크(result 확정이라는 의미)

		for (edge i : list[current.second]) {
			if (!visited[i.second]) {
				if (result[current.second] + i.first < result[i.second]) {
					result[i.second] = result[current.second] + i.first;
					pq.push(edge(result[i.second], i.second));
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (result[i] == INT_MAX) cout << "INF" << "\n";
		else cout << result[i] << "\n";
	}
}