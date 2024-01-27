#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

static vector<int> parent;
void uni(int a, int b);
int find(int a);

struct Edge {
	int s, e, w;
	bool operator() (const Edge& tmp1, const Edge& tmp2) {
		return tmp1.w > tmp2.w;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	cin.ignore(); //n 입력 후 \n 무시
	priority_queue<Edge, vector<Edge>, Edge> pq;

	int total = 0; char str[51];

	for (int i = 0; i < n; i++) {
		cin.getline(str, n + 1);
		for (int j = 0; j < n; j++) {
			int temp = 0;
			if (str[j] >= 'a' && str[j] <= 'z') temp = str[j] - 'a' + 1;
			else if (str[j] >= 'A' && str[j] <= 'Z') temp = str[j] - 'A' + 27;

			total += temp;
			if (i != j && temp != 0) pq.push(Edge{ i, j, temp });
		}
	}

	parent.resize(n);
	for (int i = 0; i < n; i++) parent[i] = i;

	int useEdge = 0; int result = 0;
	while (useEdge < n - 1 && !pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		
		if (find(now.s) != find(now.e)) {
			result += now.w;
			uni(now.s, now.e);
			useEdge++;
		}
	}

	if (useEdge < n - 1) cout << -1;
	else cout << total - result;
}

void uni(int a, int b) {
	if (find(a) != find(b)) parent[find(b)] = find(a); //반드시 find(대표노드)끼리 연결
}

int find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}