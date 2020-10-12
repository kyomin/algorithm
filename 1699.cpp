#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int *DP = new int[N + 1];

	// 가장 작은 문제의 자명한 해를 담는다.
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;

	for (int i = 4; i <= N; i++) {
		int min = DP[i - 1];

		for (int j = 2; j < i; j++) {
			if (i == j * j) {
				min = 0;
				break;
			}

			if (j*j > i)
				break;

			if (i - j * j >= 1)
				if (DP[i - j * j] < min)
					min = DP[i - j * j];
		}

		DP[i] = min + 1;
	}

	cout << DP[N] << '\n';

	delete[] DP;

	return 0;
}