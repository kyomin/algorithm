#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a == 60 && b == 60 && c == 60) {
		cout << "Equilateral" << '\n';
	}
	else if ((a + b + c) == 180 && a == b || b == c || a == c) {
		cout << "Isosceles" << '\n';
	}
	else if ((a + b + c) == 180 && a != b && b != c && a != c) {
		cout << "Scalene" << '\n';
	}
	else if ((a + b + c) != 180) {
		cout << "Error" << '\n';
	}

	return 0;
}