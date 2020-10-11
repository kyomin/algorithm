#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 집의 갯수
	int N;
	cin >> N;

	// 색칠 비용을 담을 행렬
	int **W = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		W[i] = new int[3];

	// 색칠 비용 입력!
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> W[i][j];

	// 최적 해를 담을 행렬
	int **DP = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		DP[i] = new int[3];

	// 가장 작은 문제의 자명한 해를 먼저 넣는다.
	DP[1][0] = W[1][0];
	DP[1][1] = W[1][1];
	DP[1][2] = W[1][2];

	// 집의 갯수가 1개라면 예외 처리!
	if (N == 1) {
		cout << min(min(DP[1][0], DP[1][1]), DP[1][2]) << endl;
		return 0;
	}

	// DP의 배열을 최소의 해부터 채워나간다.
	for (int i = 2; i <= N; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + W[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + W[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + W[i][2];
	}

	cout << min(min(DP[N][0], DP[N][1]), DP[N][2]) << endl;

	return 0;
}