#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 2 * N - 1; i++) {
		if (i == 0 || i == 2 * N - 2) {
			for (int j = 0; j < N; j++)
				cout << "*";

			for (int j = 0; j < 2 * N - 3; j++)
				cout << " ";

			for (int j = 0; j < N; j++)
				cout << "*";

			cout << "\n";

			continue;
		}

		if (i == N - 1) {
			for (int j = 0; j < N - 1; j++)
				cout << " ";

			cout << "*";

			for (int j = 0; j < N - 2; j++)
				cout << " ";

			cout << "*";

			for (int j = 0; j < N - 2; j++)
				cout << " ";

			cout << "*\n";

			continue;
		}

		for (int j = 0; j < (N - 1) - abs(N - 1 - i); j++)
			cout << " ";
		
		cout << "*";

		for (int j = 0; j < N - 2; j++)
			cout << " ";
		
		cout << "*";

		for (int j = 0; j < 2 * abs((N - 1) - i) - 1; j++)
			cout << " ";
		
		cout << "*";

		for (int j = 0; j < N - 2; j++)
			cout << " ";
		
		cout << "*\n";
	}

	return 0;
}