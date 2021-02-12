#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll pow(ll x, ll y) {
	if (y == 0)
		return 1;

	return x * pow(x, y - 1);
}

int main() {
	for (int t = 1; t <= 10; t++) {
		int T;
		ll x, y;
		cin >> T;
		cin >> x >> y;

		cout << '#' << t << ' ' << pow(x, y) << '\n';
	}

	return 0;
}