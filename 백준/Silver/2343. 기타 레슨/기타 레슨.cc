#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//블루레이 하나의 크기 기준 최소 9, 최대 45필요
	int s = *max_element(v.begin(), v.end());
	int e = 0;
	for (int i = 0; i < n; i++) {
		e += v[i];
	}

	while (s <= e) {
		int mid = (s + e) / 2;
		int count = 0;
		int sum = 0;
		
		for (int i = 0; i < n; i++) {
			if (sum + v[i] > mid) {
				count++;
				sum = 0;
			}
			sum += v[i];
		}
		if (sum != 0) count++;

		if (count <= m) e = mid - 1;
		else if (count > m) s = mid + 1;
	}

	cout << s;
}