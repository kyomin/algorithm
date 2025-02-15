#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *DP = new int[N + 1];

	// ���� ���� ������ �ڸ��� �ظ� ���� ��´�.
	DP[0] = 1;
	DP[1] = 0;
	DP[2] = 3;
	DP[3] = 0;

	if (N == 1 || N == 2) {
		cout << DP[N] << endl;
		return 0;
	}

	for (int i = 4; i <= N; i++) {
		DP[i] = (3 * DP[i - 2]);

		for (int j = 4; j <= i; j += 2)
			DP[i] += 2 * DP[i - j];
	}

	cout << DP[N] << endl;

	return 0;
}