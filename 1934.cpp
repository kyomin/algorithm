#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;

		cout << ((A*B) / gcd(A, B)) << endl;
	}

	return 0;
}