#include <iostream>

using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	int A, B;
	cin >> A >> B;

	int G = GCD(A, B);
	int L = (A*B) / G;

	cout << G << endl << L << endl;

	return 0;
}