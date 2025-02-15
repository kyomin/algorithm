#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		for (int i = 2; i*i <= N; i++) {
			int count = 0;

			while (N%i == 0) {
				count++;
				N /= i;
			}

			if (count != 0)
				cout << i << ' ' << count << '\n';
		}

		if (N > 1)
			cout << N << ' ' << 1 << '\n';
	}

	return 0;
}