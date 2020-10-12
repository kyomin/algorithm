#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = N; i >= 1; i--) {
		int num = 2 * i - 1;

		for (int j = 0; j < N - i; j++)
			cout << ' ';

		for (int j = 0; j < num; j++)
			cout << '*';

		cout << '\n';
	}

	return 0;
}