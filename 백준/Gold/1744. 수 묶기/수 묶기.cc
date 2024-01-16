#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue<int> plusPq;
	priority_queue<int, vector<int>, greater<int>> minusPq;
	bool zero = false;
	int one = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp > 1) plusPq.push(temp);
		else if (temp < 0) minusPq.push(temp);
		else if (temp == 0) zero = true;
		else if (temp == 1) one++;
	}

	int sum = 0;
	while (!plusPq.empty()) { //양수 처리
		if (plusPq.size() == 1) {
			sum += plusPq.top();
			plusPq.pop();
			break;
		}
		int a, b;
		a = plusPq.top();
		plusPq.pop();
		b = plusPq.top();
		plusPq.pop();
		sum += a * b;
	}
	while (!minusPq.empty()) { //음수 처리
		if (minusPq.size() == 1) {
			if (zero) {
				minusPq.pop();
				break;
			}
			else {
				sum += minusPq.top();
				minusPq.pop();
				break;
			}
		}
		int a, b;
		a = minusPq.top();
		minusPq.pop();
		b = minusPq.top();
		minusPq.pop();
		sum += a * b;
	}

	cout << sum + one;	
}