#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	bool found = false;
	int ans = MAX;
	int n;
	cin >> n;

	for (int i = 0; i * 2 <= n; i++) {
		int coin2 = (i * 2);

		for (int j = 0; j * 5 <= n; j++) {
			int coin5 = (j * 5);

			// 만들 수 있는 경우를 찾았다.
			if (coin2 + coin5 == n) {
				found = true;

				ans = min(ans, (i + j));
			}
		}
	}

	if (found)
		cout << ans << '\n';
	else
		cout << -1 << '\n';

	return 0;
}