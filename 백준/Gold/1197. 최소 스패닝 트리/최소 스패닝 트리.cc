#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<int> parent;
void uni(int a, int b);
int find(int a);

typedef struct Edge { //priorty_queue에 Edge 자료구조의 정렬 기준을 설정
	int s, e, w;
	bool operator> (const Edge& tmp) const {
		return w > tmp.w;
	}
} Edge;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int s, e, w; cin >> s >> e >> w;
		pq.push(Edge{ s, e, w }); //struct Edge 생성
	}

	int useEdge = 0;
	int result = 0;
	while (useEdge < n - 1) {
		Edge now = pq.top();
		pq.pop();
		if (find(now.s) != find(now.e)) {
			uni(now.s, now.e);
			useEdge++;
			result += now.w;
		}
	}
	cout << result;
}

void uni(int a, int b) {
	if (find(a) != find(b)) parent[find(b)] = find(a);
}

int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}