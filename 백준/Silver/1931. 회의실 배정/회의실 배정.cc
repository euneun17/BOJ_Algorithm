#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> edge;

bool compare (edge a, edge b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<edge> v(n);
	for (int i = 0; i < n; i++) {
		edge tmp; cin >> tmp.first >> tmp.second;
		v[i] = tmp;
	}
	sort(v.begin(), v.end(), compare);


	int result = 0;
	int end = -1;
	for (int i = 0; i < n; i++) {
		if (v[i].first >= end) {
			end = v[i].second;
			result++;
		}
	}
	
	cout << result;
}