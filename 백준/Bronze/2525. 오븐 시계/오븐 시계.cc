#include <iostream>
using namespace std;

int main(){
	int a, b, c, h, m;
	cin >> a >> b >> c;
	
	h = (b + c) / 60;
	m = (b + c) % 60;

	int finH = a + h;
	if (finH > 23) {
		finH = a + h - 24;
	}

	cout << finH << " " << m;
}