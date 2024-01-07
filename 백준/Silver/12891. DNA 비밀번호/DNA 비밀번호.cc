#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkArr[4] = { 0 };
int checkSecret = 0;
int checkNum[4];
void Add(char c);
void Remove(char c);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, p;
	cin >> s >> p;

	//길이 S인 문자열 입력, 띄어쓰기 없이 string 형태로 들어오므로 vector로 받으면 첫 번째 문자만 들어감(나머지는 NULL)
	vector<char> v(s, 0);
	for (int i = 0; i < s; i++) {
		cin >> v[i];
	}
	int count = 0;

	// 비밀번호의 기준이 되는 A,C,G,T 개수 입력
	for (int i = 0; i < 4; i++) {
		cin >> checkNum[i];
		if (checkNum[i] == 0) checkSecret++;
	}

	//가장 초기의 슬라이딩도어
	for (int i = 0; i < p; i++) {
		Add(v[i]);
	}
	if (checkSecret == 4) count++;

	//슬라이딩도어 움직이기
	for (int end = p; end < s; end++) {
		int start = end - p;
		Add(v[end]);
		Remove(v[start]);
		
		if (checkSecret == 4) count++;
	}

	cout << count;
}

void Add(char c) {
	switch (c) {
	case 'A':
		checkArr[0]++;
		if (checkArr[0] == checkNum[0]) checkSecret++;
		break;
	case 'C':
		checkArr[1]++;
		if (checkArr[1] == checkNum[1]) checkSecret++;
		break;
	case 'G':
		checkArr[2]++;
		if (checkArr[2] == checkNum[2]) checkSecret++;
		break;
	case 'T':
		checkArr[3]++;
		if (checkArr[3] == checkNum[3]) checkSecret++;
		break;
	}
}

//ADD()와 달리 먼저 if문 확인 후 감소 연산
void Remove(char c) {
	switch (c) {
	case 'A':
		if (checkArr[0] == checkNum[0]) checkSecret--;
		checkArr[0]--;
		break;
	case 'C':
		if (checkArr[1] == checkNum[1]) checkSecret--;
		checkArr[1]--;
		break;
	case 'G':
		if (checkArr[2] == checkNum[2]) checkSecret--;
		checkArr[2]--;
		break;
	case 'T':
		if (checkArr[3] == checkNum[3]) checkSecret--;
		checkArr[3]--;
		break;
	}
}