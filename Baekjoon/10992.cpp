#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int count = 2 * i - 1;

		if (i == 0 || i == N) {
			for (int j = 0; j < (N - i); j++)
				cout << ' ';

			for (int j = 0; j < count; j++)
				cout << '*';

			cout << endl;

			continue;
		}

		for (int j = 0; j < (N - i); j++)
			cout << ' ';

		for (int j = 0; j < count; j++) {
			if (j == 0 || j == count - 1)
				cout << '*';
			else
				cout << ' ';
		}

		cout << endl;
	}

	return 0;
}