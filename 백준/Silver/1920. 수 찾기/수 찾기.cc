#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

static int n;
static vector<int> v;
void BS(int target);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		BS(temp);
	}
}

void BS(int target){
	int s = 0, mid = 0, e = n - 1;
	
	while ( s <= e) {
		mid = (s + e) / 2;
		if (target < v[mid]) e = mid - 1;
		else if (target > v[mid]) s = mid + 1;
		else {
			cout << 1 << "\n"; 
			return;
		}
	}
	cout << 0 << "\n";
}