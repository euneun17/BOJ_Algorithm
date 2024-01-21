#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> edge;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l; cin >> n >> l;
	deque<edge> dq;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		while (!dq.empty() && dq.back().second > tmp) dq.pop_back();
		dq.push_back(edge(i, tmp));
		if (i - dq.front().first >= l) {
			dq.pop_front();
		}
		cout << dq.front().second << " ";
	}
	
}