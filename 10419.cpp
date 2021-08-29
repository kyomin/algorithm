#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int d;
		cin >> d;

		for (int i = d; i >= 0; i--) {
			if (i*(i + 1) <= d) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}