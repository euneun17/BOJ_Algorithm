#include <iostream>
#include <vector>
#include <queue>
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

	priority_queue<int, vector<int>, compare> pq;
	for (int i = 0; i < n; i++) {
		int Q;
		cin >> Q;

		if (Q == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(Q);
	}
}