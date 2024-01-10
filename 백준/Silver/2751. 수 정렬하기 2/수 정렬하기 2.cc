#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


static vector<int> v;
static vector<int> tmpV;

void merge_sort (int s, int e) {
	int m = (s + e) / 2;

	if (s >= e) { //s=e라는 건 크기 1로 분할이 되었다는 뜻
		return;
	}
	
	merge_sort(s, m); //분할
	merge_sort(m + 1, e);

	for (int i = s; i <= e; i++) { //분할된 그룹 내 정렬을 위해 tmpV에 분할된 범위만큼 값 넣기
		tmpV[i] = v[i];
	}

	int k = s; //tmp에 순서대로 넣기 위한 index 변수
	int index1 = s;
	int index2 = m + 1;
	while (index1 <= m && index2 <= e) {
		if (tmpV[index1] < tmpV[index2]) {
			v[k] = tmpV[index1];
			k++;
			index1++;
		}
		else {
			v[k] = tmpV[index2];
			k++;
			index2++;
		}
	}
	while (index1 <= m) { //한 쪽 그룹의 정렬이 끝나고 남은 그룹의 잔여 원소들 처리
		v[k] = tmpV[index1];
		k++;
		index1++;
	}
	while (index2 <= e) {
		v[k] = tmpV[index2];
		k++;
		index2++;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	v = vector<int> (n);
	tmpV = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
}