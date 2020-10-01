#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int star_pos = N - n;
		int end_pos = N + n;

		for (int i = 1; i <= N; i++) {
			if (i == star_pos)
				cout << '*';
			else
				cout << ' ';
		}

		for (int i = N + 1; i <= end_pos; i++) {
			if (i == end_pos)
				cout << '*';
			else
				cout << ' ';
		}

		cout << '\n';
	}

	return 0;
}