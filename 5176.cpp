#include <iostream>
#include <cstring>

using namespace std;

bool seats[501];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(seats, false, sizeof(seats));
		int P, M;
		int ans = 0;
		cin >> P >> M;

		for (int p = 0; p < P; p++) {
			int seat;
			cin >> seat;

			if (!seats[seat])
				seats[seat] = true;
			else
				ans += 1;
		}

		cout << ans << '\n';
	}

	return 0;
}