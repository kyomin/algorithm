#include <iostream>

using namespace std;

int main() {
	int round;
	cin >> round;

	int A = 100, B = 100;

	for (int i = 0; i < round; i++) {
		int a, b;
		cin >> a >> b;

		if (a < b)
			A -= b;

		if (a > b)
			B -= a;
	}

	cout << A << '\n' << B << '\n';

	return 0;
}