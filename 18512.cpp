#include <iostream>

using namespace std;

int main() {
	int x, y, p1, p2;
	cin >> x >> y >> p1 >> p2;

	while (true) {
		if (p1 > p2)
			p2 += y;

		else if (p1 < p2)
			p1 += x;

		else {
			cout << p1 << '\n';
			break;
		}

		if (p1 > 10000 || p2 > 10000) {
			cout << -1 << '\n';
			break;
		}
	}

	return 0;
}