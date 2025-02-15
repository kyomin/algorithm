#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (r == 0 || r == N - 1 || c == 0 || c == N - 1)
					cout << '#';
				else
					cout << 'J';
			}

			cout << endl;
		}

		cout << endl;
	}

	return 0;
}