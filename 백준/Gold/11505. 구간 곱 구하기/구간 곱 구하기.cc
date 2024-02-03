#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<long> tree;
static int MOD = 1000000007;
long getMul(int s, int e);
void changeVal(int index, int val);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k; cin >> n >> m >> k;

	int treeHeight = 0;
	int length = n;
	while (length > 0) {
		length = length / 2;
		treeHeight++;
	}

	int treeSize = pow(2, treeHeight + 1);
	int leafNodeStart = pow(2, treeHeight);
	tree = vector<long>(treeSize, 1);
	for (int i = leafNodeStart; i < leafNodeStart + n; i++) {
		cin >> tree[i];
	}

	for (int i = leafNodeStart - 1; i > 0; i--) {
		tree[i] = tree[i * 2] * tree[i * 2 + 1] % MOD;
	}

	for (int i = 0; i < m + k; i++) {
		int a, b, c; cin >> a >> b >> c;

		if (a == 1) {
			changeVal(b + leafNodeStart - 1, c);
		}
		else if (a == 2) {
			cout << getMul(b + leafNodeStart - 1, c + leafNodeStart - 1) << "\n";
		}
	}
}

long getMul(int s, int e) {
	long Mul = 1;

	while (s <= e) {
		if (s % 2 == 1) {
			Mul = Mul * tree[s] % MOD;
			s++;
		}
		if (e % 2 == 0) {
			Mul = Mul * tree[e] % MOD;
			e--;
		}

		s = s / 2;
		e = e / 2;
	}

	return Mul;
}

void changeVal(int index, int val) {
	tree[index] = val;

	while (index > 1) {
		index = index / 2;
		tree[index] = tree[index * 2] * tree[index * 2 + 1] % MOD;
	}
}