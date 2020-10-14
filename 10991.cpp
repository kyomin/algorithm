#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int num = 2 * N - 1;

	for (int i = N; i <= num; i++) {

		for (int j = 0; j < num - i; j++)
			cout << ' ';

		for (int j = 0; j < 2 * i - num; j++) {
			if (j % 2 == 1)
				cout << ' ';
			else
				cout << '*';
		}

		cout << '\n';
	}

	return 0;
}