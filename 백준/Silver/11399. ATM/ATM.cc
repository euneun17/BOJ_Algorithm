#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		int abs_a = abs(a);
		int abs_b = abs(b);
		
		if (abs_a == abs_b) return a > b;
		else return abs_a > abs_b;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	vector<int> sumV(n+1, 0);
	for (int i = 1; i <= n; i++) {
		sumV[i] = sumV[i - 1] + v[i - 1];
	}

	//합배열 총합 구하기
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += sumV[i];
	}
	cout << result;
}