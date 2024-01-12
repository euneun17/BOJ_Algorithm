#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

static int n, m;
static int dx[4] = { 1, 0, -1, 0 };
static int dy[4] = {0, -1, 0 , 1};
static int v[101][101];
static bool visited[101][101] = {false};
void BFS(int i, int j);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			v[i][j] = s[j] - 48;
		}
	}

	BFS(0,0);
	cout << v[n - 1][m - 1];
}

void BFS(int i, int j){
	queue<pair<int, int>> queue;
	queue.push(make_pair(i, j));
	visited[i][j] = true;

	while (!queue.empty()) {
		int now[2];
		now[0] = queue.front().first;
		now[1] = queue.front().second;
		queue.pop();

		for (int k = 0; k < 4; k++) {
			int x = now[0] + dx[k];
			int y = now[1] + dy[k];

			if (x < 0 || y < 0 || x > n - 1 || y > m - 1) continue;
			else if (!visited[x][y] && v[x][y] == 1) {
				queue.push(make_pair(x, y));
				visited[x][y] = true;
				v[x][y] = v[now[0]][now[1]] + 1;
			}
		}

	}
}