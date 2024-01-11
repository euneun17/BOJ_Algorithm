#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	A = vector<vector<int>>(n + 1); //인접 리스트 크기 정의 
	visited = vector<bool>(n + 1, false); //탐색 배열 크기 정의

	for (int i = 0; i < m; i++) { //인접 리스트로 그래프 표현
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i <= n; i++) { //DFS 과정이 새로 시작되는 경우
		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}

	cout << count;
}

void DFS(int node) {
	if (visited[node]) return;

	// 방문하지 않은 노드라면
	visited[node] = true;
	for (int i : A[node]) { //범위 기반 루프(A[node]의 모든 인접 배열 순회, 여기서 i는 index가 아니라 데이터 값 자체를 의미
		if (!visited[i]) {
			DFS(i);
		}
	}
}