#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[100000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int sArr[100000]; //합 배열 S
	sArr[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		sArr[i] = sArr[i - 1] + arr[i - 1];
	}

	for (int i = 0; i < m; i++) {
		int j, k;
		scanf("%d %d", &j, &k);
		cout << sArr[k] - sArr[j - 1] << "\n";
	}
}