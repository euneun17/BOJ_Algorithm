#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

vector<int> v;
void uni (int b, int c); //b,c가 각각 속한 집합의 대표노드끼리 연결
int find(int k); //k가 속한 집합의 대표노드 반환

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i <= n; i++) v[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 0) {
			uni(b, c);
		}
		else if (a == 1) {
			if (find(b) == find(c)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}

void uni(int b, int c) {
	if (find(b) != find(c)) v[find(c)] = find(b); //대표노드끼리 연결
}

int find(int k) {
	if (v[k] == k) {
		return k;
	}
	else {
		return v[k] = find(v[k]);
	}
}