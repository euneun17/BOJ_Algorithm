#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
	int arr[9];
	int temp, max, cursor;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &temp);
		arr[i] = temp;

		if (i == 0) {
			max = arr[i];
			cursor = i + 1;
		}
		else {
			if (arr[i] > max) {
				max = arr[i];
				cursor = i + 1;
			}
		}
	}

	cout << max << " " << cursor;
}