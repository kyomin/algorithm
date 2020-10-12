#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int **A = new int*[n + 1];

	for (int i = 1; i <= n; i++)
		A[i] = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int num;
			cin >> num;

			A[i][j] = num;
		}
	}

	int **DP = new int*[n + 1];

	for (int i = 1; i <= n; i++)
		DP[i] = new int[n + 1];

	DP[1][1] = A[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				DP[i][j] = DP[i - 1][j] + A[i][j];
				continue;
			}

			if (j == i) {
				DP[i][j] = DP[i - 1][j - 1] + A[i][j];
				continue;
			}

			DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + A[i][j];
		}
	}

	int maximum = DP[n][1];

	for (int i = 2; i <= n; i++)
		if (DP[n][i] > maximum)
			maximum = DP[n][i];

	cout << maximum << endl;

	return 0;
}