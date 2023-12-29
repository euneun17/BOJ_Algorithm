#include <iostream>
using namespace std;

int main(){
	int a, b, c, d, x, y;
	cin >> a >> b >> c >> d;

	x = min(a, c - a);
	y = min(b, d - b);

	cout << min(x, y);
}