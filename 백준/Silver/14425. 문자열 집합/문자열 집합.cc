#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
	Node* next[26]; //Node 타입을 가리키는 26개의 포인터 원소를 가지는 포인터 배열
	bool isEnd;
	Node() : isEnd(false) { //생성자 초기화
		fill(next, next + 26, nullptr);
	}

	~Node() {
		for (auto& child : next) delete child;
	}

	void insert(const char* key) {
		if (*key == NULL) isEnd = true; //NULL 대신 0도 가능
		else {
			int next_index = *key - 'a';
			if (next[next_index] == nullptr) {
				next[next_index] = new Node();
			}
			next[next_index]->insert(key + 1);
		}
	}

	Node* find(const char* key) {
		if (*key == NULL) return this; //문자열이 존재하는 경우, 문자배열의 마지막 노드(\0 직전)를 반환
		
		int next_index = *key - 'a';
		if (next[next_index] == nullptr) return nullptr; //문자열이 존재하지 않는 경우(문자 배열의 끝을 의미하는 NULL(\0)을 만나지 못한 경우

		return next[next_index]->find(key + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	Node* root = new Node();

	while (n > 0) {
		char text[501];
		cin >> text;
		root->insert(text);
		n--;
	}

	int count = 0;
	while (m > 0) {
		char text[501];
		cin >> text;
		Node* result = root->find(text);

		if (result != nullptr && result->isEnd) { //nullptr은 false를 의미, 따라서 그냥 result로 써도 됨
			count++;
		}
		m--;
	}
	cout << count << "\n";
}