#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int a, b;
		cin >> a >> b;

		int q = a / b;
		int r = a % b;

		cout << '#' << t << ' ' << q << ' ' << r << endl;
	}

	return 0;
}