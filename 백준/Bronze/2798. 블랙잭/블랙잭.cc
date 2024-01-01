#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n, m, temp, twoSum, sum;
	scanf("%d %d", &n, &m);
	int arr[100];
	int max = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		arr[i] = temp;
	}

	for (int i = 0; i < n -1; i++) {
		for (int j = i; j < n; j++) {
			if (i != j) {
				twoSum = arr[i] + arr[j];

				for (int k = 0; k < n; k++) {
					if (k != i && k != j) {
						sum = twoSum + arr[k];
						if (sum <= m && sum > max) {
							max = sum;
						}
					}
				}
			}
		}
	}

	cout << max;
}