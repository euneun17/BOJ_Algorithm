#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

static int radisNode;
static vector<vector<pair<int, int>>> v;
static vector<int> dist;
static vector<bool> visited;
void BFS(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	v.resize(n + 1);
	dist = vector<int>(n + 1, 0);
	visited = vector<bool>(n + 1, false);

	int tempN, temp1, temp2;
	for (int i = 0; i < n; i++) {
		cin >> tempN;
		while (true) {
			cin >> temp1;
			if (temp1 == -1) break;
			cin >> temp2;
			v[tempN].push_back(make_pair(temp1, temp2));
		}
	}

	BFS(tempN);
	int max = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[max] < dist[i]) max = i;
	}
	fill(dist.begin(), dist.end(), 0);
	fill(visited.begin(), visited.end(), false);
	
	BFS(max);
	cout << *max_element(dist.begin(), dist.end());
}

void BFS(int node){
	queue<int> queue;
	queue.push(node);
	visited[node] = true;

	while (!queue.empty()) {
		for ( pair<int, int> i : v[queue.front()]) {
			if (!visited[i.first]) {
				queue.push(i.first);
				dist[i.first] = dist[queue.front()] + i.second;
				visited[i.first] = true;
			}
		}
		queue.pop();
	}
}