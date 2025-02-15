#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N >= 3 && N <= 5) {
		if (N == 3)
			cout << 1 << endl;
		else if (N == 4)
			cout << -1 << endl;
		else
			cout << 1 << endl;

		return 0;
	}

	// memo용 배열 동적할당!
	int *DP = new int[N + 1];

	// 가장 작은 해의 자명한 해를 넣는다.
	DP[1] = -1;
	DP[2] = -1;
	DP[3] = 1;
	DP[4] = -1;
	DP[5] = 1;

	for (int i = 6; i <= N; i++)
		if (DP[i - 3] != -1 && DP[i - 5] != -1)
			DP[i] = min(DP[i - 3] + 1, DP[i - 5] + 1);
		else if (DP[i - 3] != -1 && DP[i - 5] == -1)
			DP[i] = DP[i - 3] + 1;
		else if (DP[i - 3] == -1 && DP[i - 5] != -1)
			DP[i] = DP[i - 5] + 1;
		else
			DP[i] = -1;

	cout << DP[N] << endl;

	return 0;
}