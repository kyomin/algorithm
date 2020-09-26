#include <iostream>

using namespace std;

int scoreBoard[200][3];

int main() {
	int N;
	cin >> N;

	// �� �÷��̾��� �� ���� ���� �Է�
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> scoreBoard[i][j];

	for (int player = 0; player < N; player++) {
		int score = 0;

		// �� ���Ӹ��� �ش� �÷��̾��� ������ ����Ѵ�.
		for (int game = 0; game < 3; game++) {
			int cnt = 0;

			for (int otherPlayer = 0; otherPlayer < N; otherPlayer++) {
				if (player == otherPlayer)
					continue;

				// ������ ���� ���� �߰ߵǸ�
				if (scoreBoard[otherPlayer][game] == scoreBoard[player][game])
					cnt++;
			}

			// ����ũ�� ��쿡�� ������ �����ش�.
			if (cnt == 0)
				score += scoreBoard[player][game];
		}

		cout << score << '\n';
	}

	return 0;
}