#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int start = 1, end = 1, sum = 1, count = 1; //start와 end는 진짜 숫자를 의미, count는 자기 자신을 미리 고려해 1부터 시작
	int n;
	cin >> n;
	
	while (end != n) {
		if (sum < n) {
			end++;
			sum += end;
		}
		else if (sum > n) {
			sum -= start;
			start++;
		}
		else if (sum == n) {
			count++;
			end++;
			sum += end;
		}
	}

	cout << count << "\n";
}