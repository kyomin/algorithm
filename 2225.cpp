#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int **DP = new int*[K + 1];

	for (int i = 1; i <= K; i++) {
		DP[i] = new int[N + 1];

		// 모든 배열의 값을 일단 0으로 초기화
		for (int j = 0; j <= N; j++)
			DP[i][j] = 0;
	}

	// 가장 작은 문제의 자명한 해를 구한다.
	for (int i = 0; i <= N; i++)
		DP[1][i] = 1;

	// 만일 입력받은 길이가 1이라면
	if (K == 1) {
		cout << DP[1][N] % 1000000000 << endl;

		// 함수 종료!
		return 0;
	}

	// 가장 작은 문제로부터 큰 문제의 해를 점차 구해나간다.
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] += DP[i - 1][j - k];
				DP[i][j] %= 1000000000;
			}
		}
	}

	cout << DP[K][N] % 1000000000 << endl;

	return 0;
}