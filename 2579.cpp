#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *A = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int **DP = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		DP[i] = new int[3];

	// 가장 작은 문제의 자명한 해를 먼저 넣는다.
	DP[1][1] = A[1];

	if (N == 1) {
		cout << DP[1][1] << endl;
		return 0;
	}

	DP[2][1] = A[2];
	DP[2][2] = A[1] + A[2];

	if (N == 2) {
		cout << max(DP[2][1], DP[2][2]) << endl;
		return 0;
	}

	DP[3][1] = A[1] + A[3];
	DP[3][2] = DP[2][1] + A[3];

	if (N == 3) {
		cout << max(DP[3][1], DP[3][2]) << endl;
		return 0;
	}

	for (int i = 4; i <= N; i++) {
		DP[i][1] = max(DP[i - 2][1], DP[i - 2][2]) + A[i];
		DP[i][2] = DP[i - 1][1] + A[i];
	}

	cout << max(DP[N][1], DP[N][2]) << endl;

	return 0;
}