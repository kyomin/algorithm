#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *A = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int *DP = new int[N + 1];

	// 가장 작은 문제의 자명한 해를 미리 담는다.
	DP[1] = A[1];


	for (int i = 2; i <= N; i++)
		DP[i] = max(max(A[i], A[i] + A[i - 1]), A[i] + DP[i - 1]);

	int max = DP[1];

	for (int i = 2; i <= N; i++)
		if (max < DP[i])
			max = DP[i];

	cout << max << endl;

	return 0;
}