#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	int min = 1000000;
	int max = -1000000;
	int input;

	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		if (input < min) min = input;
		if (input > max) max = input;
	}
	cout << min << " " << max << "\n";

	return 0;
}