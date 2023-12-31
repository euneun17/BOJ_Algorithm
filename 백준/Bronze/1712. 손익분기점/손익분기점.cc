#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int ret = -1;
	if (c > b) {
		ret = a / (c - b) + 1;
	}

	printf("%d\n", ret);
	return 0;
}