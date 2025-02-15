#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *A = new int[N + 1];
	int *DP = new int[N + 1];

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		A[i] = n;
	}

	for (int i = 1; i <= N; i++)
		DP[i] = A[i];

	if (N == 1) {
		cout << DP[1] << endl;
		return 0;
	}

	for (int i = 2; i <= N; i++)
		for (int j = 1; j < i; j++)
			if (A[j] + DP[i - j] > DP[i])
				DP[i] = A[j] + DP[i - j];

	cout << DP[N] << endl;

	return 0;
}