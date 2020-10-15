#include <iostream>

using namespace std;

typedef long long ll;

void swap(int &a, int &b) {
	int temp = a;

	a = b;
	b = temp;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		ll x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		ll dx = x1 - x2;
		ll dy = y1 - y2;

		// r2 > r1을 맞춰주기 위함
		if (r1 > r2) swap(r1, r2);

		ll add = r1 + r2;
		add = add * add;

		ll sub = r2 - r1;
		sub = sub * sub;

		ll d = dx * dx + dy * dy;

		if (d < add && d > sub)
			cout << 2 << '\n';
		else if (d == add || (d == sub && d != 0))
			cout << 1 << '\n';
		else if (d<sub || d>add)
			cout << 0 << '\n';
		else if (d == 0) {
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
	}

	return 0;
}