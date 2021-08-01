#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;

		int cnt = 0;
		while (true) {
			if (a == b && b == c && c == d)
				break;

			int a_tmp = abs(a - b);
			int b_tmp = abs(b - c);
			int c_tmp = abs(c - d);
			int d_tmp = abs(d - a);

			a = a_tmp;
			b = b_tmp;
			c = c_tmp;
			d = d_tmp;

			cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}