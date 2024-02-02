#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<long> tree;
long getSum(int s, int e);
void changeVal(int index, long val);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	
	int treeHeight = 0;
	int length = n;
	while (length != 0) { //2^k >= n인 최소값 k(=treeheight)을 구하는 과정
		length = length / 2;
		treeHeight++;
	}

	int treeSize = pow(2, treeHeight + 1); //트리 배열의 크기
	int leafNodeStart = pow(2, treeHeight); //리프 노드 시작 인덱스
	tree.resize(treeSize);
	for (int i = leafNodeStart; i < leafNodeStart + n; i++) { //주어진 데이터 n개를 리프노드에 넣기
		cin >> tree[i];
	}

	//리프 노드를 제외한 나머지 부분 채우기
	int i = treeSize - 1; //리프 노드의 맨 끝부터
	while (i > 1) { //루트 노드 전까지
		tree[i / 2] = tree[i] + tree[i / 2]; //i 노드의 부모 노드
		i--;
	}

	for (int i = 0; i < m + k; i++) {
		int a, b; long c; cin >> a >> b >> c;
		
		if (a == 1) { //값 바꾸기
			//주어진 데이터 속 인덱스와 트리 속 인덱스가 다르기 때문에 변형해서 넣어야 함
			changeVal(leafNodeStart - 1 + b, c); //leafNode - 1은 리프노드 윗단계 노드의 수
		}
		else if (a == 2) { //구간 합 구하기
			long result = getSum(leafNodeStart - 1 + b, leafNodeStart - 1 + c);
			cout << result << "\n";
		}
	}
}

long getSum(int s, int e) {
	long sum = 0;

	while (s <= e) {
		if (s % 2 == 1) {
			sum += tree[s];
			s++;
		}
		if (e % 2 == 0) {
			sum += tree[e];
			e--;
		}
		
		s = s / 2;
		e = e / 2;
	}

	return sum;
}

void changeVal(int index, long val) {
	long diff = val - tree[index];

	while (index > 0) {
		tree[index] += diff;
		index = index / 2;
	}
}