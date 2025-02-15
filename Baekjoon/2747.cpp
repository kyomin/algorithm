#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	int *DP = new int[N + 1];

	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= N; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	cout << DP[N] << endl;

	return 0;
}