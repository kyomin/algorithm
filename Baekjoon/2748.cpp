#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	unsigned long *DP = new unsigned long[N + 1];

	DP[0] = 0;
	DP[1] = 1;

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 2; i <= N; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	cout << DP[N] << endl;

	return 0;
}