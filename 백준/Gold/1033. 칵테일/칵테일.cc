#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <tuple>

using namespace std;

long lcm;
bool visited[10];
long result[10];
vector<tuple<int, int, int>> v[10];
long gcd(long a, long b);
void DFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	lcm = 1;
	for (int i = 0; i < n - 1; i++) {
		int a, b, p, q; cin >> a >> b >> p >> q;
		v[a].push_back(make_tuple(b, p, q)); //교재 설명 1번
		v[b].push_back(make_tuple(a, q, p));
		lcm = lcm * (p * q / gcd(p, q)); //설명 2번
	}

	result[0] = lcm; //설명 3번
	DFS(0); //설명 4번
	long result_gcd = result[0];
	
	for (int i = 1; i < n; i++) {
		result_gcd = gcd(result_gcd, result[i]); //설명 5번 모든 노드의 최대공약수(result_gcd) 구하기
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] / result_gcd << ' '; //설명 5번 재료 총합이 최소가 되도록 각 값을 result_gcd로 나누기
	}
}

long gcd(long a, long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void DFS(int node) {
	visited[node] = true;

	for (tuple<int, int, int> i : v[node]) {
		int next = get<0>(i);
		if (!visited[next]) {
			result[next] = result[node] * get<2>(i) / get<1>(i);
			DFS(next);
		}
	}
}