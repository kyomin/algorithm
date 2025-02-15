#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int n = N; n >= 1; n--) {
		for (int i = 0; i < n - 1; i++)
			cout << ' ';

		for (int i = n - 1; i < N; i++)
			cout << '*';

		cout << '\n';
	}

	for (int n = 0; n < N - 1; n++) {
		for (int i = 0; i <= n; i++)
			cout << ' ';

		for (int i = n; i < N - 1; i++)
			cout << '*';

		cout << '\n';
	}

	return 0;
}