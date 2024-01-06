#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int count = 0;
	for (int k = 0; k < n; k++) {
		int start = 0, end = n - 1;

		while (start < end) {
			if (v[start] + v[end] > v[k]) {
				end--;
			}
			else if (v[start] + v[end] < v[k]) {
				start++;
			}
			else if (v[start] + v[end] == v[k]) {
				if (start != k && end != k) {
					count++;
					break; //start와 end가 만나기 직전까지 가기 전에 while문을 빠져나올 수 있음.
				}
				else if (start == k) start++;
				else if (end == k) end--;
			}
		}
	}

	cout << count << "\n";
}