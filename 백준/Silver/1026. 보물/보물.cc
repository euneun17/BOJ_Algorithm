#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int> B(n);
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	vector<int> resultA(n, -1);
	for (int i = 0; i < n; i++) {
		int max = min_element(B.begin(), B.end()) - B.begin();
		for (int j = 0; j < n; j++) {
			if (resultA[j] == -1 && B[j] >= B[max]) max = j;
		}
		resultA[max] = A[i];
	}

	int S = 0;
	for (int i = 0; i < n; i++) {
		S += resultA[i] * B[i];
	}
	cout << S;
}