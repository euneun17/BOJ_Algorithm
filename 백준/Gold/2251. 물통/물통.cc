#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> edge;
static int Send[] = { 0, 1, 0, 2, 1, 2 };
static int Recieve[] = { 2, 2, 1, 1, 0, 0 };
static bool visited[201][201];
static bool result[201];
static int vol[3];
void BFS();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> vol[0] >> vol[1] >> vol[2];
	BFS();
	for (int i = 0; i <= 200; i++) {
		if (result[i]) cout << i << " ";
	}
}

void BFS() {
	queue<edge> queue;
	queue.push(make_pair(0, 0));
	visited[0][0] = true;
	result[vol[2]] = true;

	while (!queue.empty()) {
		int a = queue.front().first;
		int b = queue.front().second;
		int c = vol[2] - a - b;
		queue.pop();

		for (int i = 0; i < 6; i++) {
			int next[] = { a, b, c };
			next[Recieve[i]] += next[Send[i]];
			next[Send[i]] = 0;

			if (next[Recieve[i]] > vol[Recieve[i]]) {
				next[Send[i]] = next[Recieve[i]] - vol[Recieve[i]];
				next[Recieve[i]] = vol[Recieve[i]];
			}

			if (!visited[next[0]][next[1]]) {
				visited[next[0]][next[1]] = true;
				queue.push(make_pair(next[0], next[1]));

				if (next[0] == 0) result[next[2]] = true;
			}
		}
	}
}