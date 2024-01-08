#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	queue<int> queue;
	for (int i = 1; i < n + 1; i++) {
		queue.push(i);
	}

	while (queue.size() > 1) {
		queue.pop();
		queue.push(queue.front());
		queue.pop(); //해당 코드 추가하지 않으면 계속 queue.size()가 2로 유지 되어 무한루프 발생
	}

	cout << queue.front();
}