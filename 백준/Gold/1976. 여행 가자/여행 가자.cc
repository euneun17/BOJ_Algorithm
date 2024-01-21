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

	int city[201][201];
	vector<int> route;

	int n, m; cin >> n >> m;

	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				uni(i, j);
			}
		}
	}

	route.resize(m);
	bool connected = true;
	cin >> route[0];
	int tmp = find(route[0]);
	for (int i = 1; i < m; i++) {
		cin >> route[i];
		if (tmp != find(route[i])) {
			cout << "NO";
			connected = false;
			break;
		}
	}
	if (connected) cout << "YES";

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