#include <iostream>

using namespace std;

static int n;
static char tree[27][2];
void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
;
	for (int i = 0; i < n; i++) {
		char p, l, r; cin >> p >> l >> r;
		int parent = p - 'A' + 1;

		if (l == '.') tree[parent][0] = -1;
		else tree[parent][0] = l - 'A' + 1;

		if (r == '.') tree[parent][1] = -1;
		else tree[parent][1] = r - 'A' + 1;
	}

	preOrder(1);
	cout << "\n";
	inOrder(1);
	cout << "\n";
	postOrder(1);
}

void preOrder(int now) {
	if (now == -1) return;

	cout << (char)(now + 'A' - 1); //부모
	preOrder(tree[now][0]); //왼
	preOrder(tree[now][1]); //오
}

void inOrder(int now) {
	if (now == -1) return;

	inOrder(tree[now][0]); //왼
	cout << (char)(now + 'A' - 1); //부모
	inOrder(tree[now][1]); //오
}

void postOrder(int now) {
	if (now == -1) return;

	postOrder(tree[now][0]); //왼
	postOrder(tree[now][1]); //오
	cout << (char)(now + 'A' - 1); //부모
}