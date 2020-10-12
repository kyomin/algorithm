#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int **DP = new int*[K + 1];

	for (int i = 1; i <= K; i++) {
		DP[i] = new int[N + 1];

		// ��� �迭�� ���� �ϴ� 0���� �ʱ�ȭ
		for (int j = 0; j <= N; j++)
			DP[i][j] = 0;
	}

	// ���� ���� ������ �ڸ��� �ظ� ���Ѵ�.
	for (int i = 0; i <= N; i++)
		DP[1][i] = 1;

	// ���� �Է¹��� ���̰� 1�̶��
	if (K == 1) {
		cout << DP[1][N] % 1000000000 << endl;

		// �Լ� ����!
		return 0;
	}

	// ���� ���� �����κ��� ū ������ �ظ� ���� ���س�����.
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