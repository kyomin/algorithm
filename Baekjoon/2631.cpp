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
		DP[i] = 1;
	}

	int max = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++)
			if (A[i] > A[j] && DP[j] + 1 > DP[i])
				DP[i] = DP[j] + 1;

		if (DP[i] > max)
			max = DP[i];
	}

	cout << N - max << endl;

	return 0;
}