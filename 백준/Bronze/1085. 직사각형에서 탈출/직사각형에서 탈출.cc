#include <iostream>
using namespace std;

int main(){
	int a, b, c, d, x, y;
	cin >> a >> b >> c >> d;

	if (a < c - a) {
		x = a;
	}
	else {
		x = c - a;
	}

	if (b < d - b) {
		y = b;
	}
	else {
		y = d - b;
	}

	if (x < y) {
		cout << x;
	}
	else {
		cout << y;
	}
}