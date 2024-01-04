#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	int S[100000] = {}; //합 배열 S, 반드시 NULL(0) 값으로 초기화해주어야 함!! -> S[0] == 0 이기 위함
	for (int i = 1; i < n + 1; i++) {
		int temp;
		scanf("%d", &temp);
		S[i] = S[i - 1] + temp;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		scanf("%d %d", &i, &j);
		cout << S[j] - S[i - 1] << "\n";
	}
}