#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		int ans = 0;

		for (int num = 1; num <= N; num++) {
			if (num % 2 == 0)
				ans -= num;
			else
				ans += num;
		}

		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}