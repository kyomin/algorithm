#include <iostream>

using namespace std;

int students[2][7];
int N, K;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int S, Y;
		cin >> S >> Y;

		students[S][Y] += 1;
	}

	int ans = 0;

	for (int s = 0; s < 2; s++) {
		for (int y = 1; y <= 6; y++) {
			int q = students[s][y] / K;
			int r = students[s][y] % K;

			if (r != 0)
				q += 1;

			ans += q;
		}
	}

	cout << ans << '\n';

	return 0;
}