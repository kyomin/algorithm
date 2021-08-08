#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int K;
		cin >> K;

		for (int k = 0; k < K; k++)
			cout << '=';

		cout << '\n';
	}

	return 0;
}