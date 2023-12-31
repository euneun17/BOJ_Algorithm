#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
	int arr[42] = { 0, };
	int temp;
	int count = 0;
	
	for (int i = 0; i < 10; i++) {
		scanf("%d", &temp);
		if (!arr[temp % 42]++) count++;
	}

	cout << count;
}