#include <iostream>
#include <vector>
#include <stack>
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

	vector<int> resultV(n, -1);
	stack<int> stack;
	stack.push(0);

	for (int i = 1; i < n; i++) {
		while (!stack.empty() && v[stack.top()] < v[i]) {
			resultV[stack.top()] = v[i];
			stack.pop();
		}
		stack.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << resultV[i] << "\n";
	}
}