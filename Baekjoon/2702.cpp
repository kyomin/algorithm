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
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int a, b;
		cin >> a >> b;

		int G = gcd(a, b);
		int L = (a*b) / G;

		cout << L << ' ' << G << '\n';
	}

	return 0;
}