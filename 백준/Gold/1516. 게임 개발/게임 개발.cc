#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> v(n + 1);
	vector<int> selfBuild(n + 1);
	vector<int> inDegree(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> selfBuild[i];
		while (true) {
			int tmp; cin >> tmp;
			if (tmp == -1) break;
			v[tmp].push_back(i);
			inDegree[i]++;
		}
	}

	queue<int> queue;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) queue.push(i);
	}

	vector<int> result(n + 1);
	copy(selfBuild.begin(), selfBuild.end(), result.begin());
	while (!queue.empty()) {
		int maxTime = 0;
		for (int i : v[queue.front()]) {
			inDegree[i]--;
			if (inDegree[i] == 0) queue.push(i);

			if (result[queue.front()] > result[i] - selfBuild[i]) {
				result[i] += (result[queue.front()] - result[i] + selfBuild[i]);
			}
		}
		queue.pop();
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}
}