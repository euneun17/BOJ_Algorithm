#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

static vector<int> parent;
void uni (int b, int c); //b,c가 각각 속한 집합의 대표노드끼리 연결
int find(int k); //k가 속한 집합의 대표노드 반환

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	
	int k; cin >> k;
	vector<int> know(k);
	for (int i = 0; i < k; i++) {
		cin >> know[i];
	}

	vector<vector<int>> party(m);
	for (int i = 0; i < m; i++) {
		int pnum; cin >> pnum;
		party[i].resize(pnum);
		for (int j = 0; j < pnum; j++) {
			cin >> party[i][j];
		}
		for (int j = 0; j < pnum; j++) {
			uni(party[i][0], party[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < m; i++) {
		bool isOk = true;
		for (int j = 0; j < k; j++) {
			if (find(party[i][0]) == find(know[j])) {
				isOk = false;
				break;
			}
		}
		if (isOk) result++;
	}

	cout << result;
}

void uni(int b, int c) {
	if (find(b) != find(c)) parent[find(c)] = find(b); //대표노드끼리 연결
}

int find(int k) {
	if (parent[k] == k) {
		return k;
	}
	else {
		return parent[k] = find(parent[k]);
	}
}