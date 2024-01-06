#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	int count = 0;
	cin >> n >> m;
	vector<int> v(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = n - 1;
	while (start < end) {
		if (v[start] + v[end] < m) {
			start++;
		}
		else if (v[start] + v[end] > m) {
			end--;
		}
		else if (v[start] + v[end] == m) {
			count++;
			start++; end--;
		}
	}

	cout << count << "\n";
}