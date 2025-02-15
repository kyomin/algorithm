#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int sum = 0;
		int N;
		cin >> N;

		for (int n = 1; n <= N; n++)
			if (n % 2 == 1)
				sum += n;

		cout << sum << '\n';
	}

	return 0;
}