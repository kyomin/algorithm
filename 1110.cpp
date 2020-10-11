#include <iostream>

using namespace std;

int main() {
	int cycle = 0;
	int n;
	cin >> n;

	int first = n;

	while (true) {
		int a, b, A;

		a = n / 10;
		b = n % 10;

		A = (a + b) % 10;

		n = (b * 10) + A;

		cycle++;

		if (first == n)
			break;
	}

	cout << cycle << '\n';

	return 0;
}