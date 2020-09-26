#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int P;
		cin >> P;

		string ans;
		int cost;

		for (int p = 0; p < P; p++) {
			int C;
			string player;

			cin >> C >> player;

			if (p == 0) {
				ans = player;
				cost = C;
				continue;
			}

			if (C > cost) {
				cost = C;
				ans = player;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}