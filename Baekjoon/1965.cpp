#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

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

	for (int i = 2; i <= N; i++)
		for (int j = 1; j < i; j++)
			if (A[i] > A[j] && DP[j] + 1 > DP[i])
				DP[i] = DP[j] + 1;

	int max = DP[1];

	for (int i = 2; i <= N; i++)
		if (DP[i] > max)
			max = DP[i];

	cout << max << endl;

	return 0;
}