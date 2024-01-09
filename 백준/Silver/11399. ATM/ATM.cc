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

	for (int i = 1; i < n; i++) {
		int point = i;
		int point_value = v[i];
		for (int j = i - 1; j >= 0; j--) {
			if (v[point] > v[j]) {
				point = j + 1;
				break;
			}
			else if (j == 0) {
				point = j;
			}
		}
		for (int j = i; j > point; j--) { //삽입 point가 0일 수 있으므로 j >= point 면 안됨. v[-1] 값이 존재하지 않으므로
			v[j] = v[j - 1];
		}
		v[point] = point_value;
	}

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