#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	double arr[1000];
	double max = 0, avg = 0, sum = 0;

	//과목 점수들 vector에 넣고 max값 찾기
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
	}
	//과목의 합 구하기
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	//평균 구하기
	avg = sum / max * 100 / n;
	cout << avg;
}