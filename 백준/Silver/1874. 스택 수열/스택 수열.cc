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
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<char> resultV;

	stack<int> stack;
	int num = 1;

	for (int i = 0; i < n; i++) {
		if (A[i] >= num) {
			while (A[i] >= num) {
				stack.push(num);
				resultV.push_back('+');
				num++;
			}
			stack.pop();
			resultV.push_back('-');
		}
		else if (A[i] <= num) {
			if (stack.top() == A[i]) {
				resultV.push_back('-');
				stack.pop();
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	
	for (int i = 0; i < resultV.size(); i++) {
		cout << resultV[i] << "\n";
	}
}