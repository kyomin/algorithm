#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;

		int m = m1 + m2;
		int carry = m / 60;

		m = m % 60;

		int h = h1 + h2 + carry;

		if (h > 12)
			h -= 12;

		cout << '#' << t << ' ' << h << ' ' << m << endl;
	}

	return 0;
}