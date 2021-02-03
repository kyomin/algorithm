#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		char ans;
		int a, b;
		cin >> a >> b;

		if (a > b)
			ans = '>';
		else if (a == b)
			ans = '=';
		else
			ans = '<';

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}