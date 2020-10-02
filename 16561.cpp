#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n / 3; i++) {
		for (int j = 1; j <= n / 3; j++) {
			int sum = i * 3 + j * 3;

			if ((n - sum) % 3 == 0 && sum < n)
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}