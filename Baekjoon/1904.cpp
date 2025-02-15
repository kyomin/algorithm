#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *DP = new int[N + 1];

	DP[1] = 1;
	DP[2] = 2;

	if (N == 1 || N == 2) {
		cout << DP[N] << endl;
		return 0;
	}

	for (int i = 3; i <= N; i++)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;

	cout << DP[N] % 15746 << endl;

	return 0;
}