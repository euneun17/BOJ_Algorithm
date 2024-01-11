#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

void DFS(int num, int jasisu);
bool isPrime(int num);
static int n;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int first_prime[4] = { 2,3,5,7 };
	for (int i : first_prime) {
		DFS(i, 1);
	}
}

void DFS(int num, int jarisu) {
	if (jarisu == n){
		if (isPrime(num)) {
			cout << num << "\n";
		}
		return;
	}

	for (int i = 1; i <= 9; i += 2) {
		if (isPrime(num * 10 + i)) DFS(num * 10 + i, jarisu + 1);
	}
}

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}