#include <iostream>

using namespace std;

void printStars(int N) {
	for (int n = 1; n <= N; n++) {
		for (int i = 0; i < n; i++)
			cout << '*';

		cout << '\n';
	}

	for (int n = N - 1; n >= 1; n--) {
		for (int i = 0; i < n; i++)
			cout << '*';

		cout << '\n';
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	printStars(N);

	return 0;
}