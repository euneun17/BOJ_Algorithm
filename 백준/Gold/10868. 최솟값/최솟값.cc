#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

static vector<long> tree;
long getMin(int s, int e);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, Q; cin >> n >> Q;
	
	int treeHeight = 0;
	int length = n;
	while (length > 0) {
		length = length / 2;
		treeHeight++;
	}

	int treeSize = pow(2, treeHeight + 1);
	int leafNodeStart = pow(2, treeHeight);
	tree = vector<long>(treeSize, LONG_MAX);
	for (int i = leafNodeStart; i < leafNodeStart + n; i++) {
		cin >> tree[i];
	}

	for (int i = leafNodeStart - 1; i > 0; i--) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}

	for (int i = 0; i < Q; i++) {
		int start, end; cin >> start >> end;

		cout << getMin(start + leafNodeStart - 1, end + leafNodeStart - 1) << "\n";
	}
}

long getMin(int s, int e) {
	long Min = LONG_MAX;

	while (s <= e) {
		if (s % 2 == 1) {
			Min = min(tree[s], Min);
			s++;
		}
		s = s / 2;

		if (e % 2 == 0) {
			Min = min(tree[e], Min);
			e--;
		}
		e = e / 2;
	}

	return Min;
}