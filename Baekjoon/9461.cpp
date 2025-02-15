#include <iostream>

using namespace std;

int main() {
	int  T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		if (N <= 10) {
			unsigned long *DP = new unsigned long[11];
			DP[1] = 1, DP[2] = 1, DP[3] = 1, DP[4] = 2, DP[5] = 2, DP[6] = 3, DP[7] = 4, DP[8] = 5, DP[9] = 7, DP[10] = 9;

			cout << DP[N] << endl;
		}
		else {
			unsigned long *DP = new unsigned long[N + 1];
			DP[1] = 1, DP[2] = 1, DP[3] = 1, DP[4] = 2, DP[5] = 2, DP[6] = 3, DP[7] = 4, DP[8] = 5, DP[9] = 7, DP[10] = 9;

			for (int i = 11; i <= N; i++)
				DP[i] = DP[i - 1] + DP[i - 5];

			cout << DP[N] << endl;
		}
	}

	return 0;
}