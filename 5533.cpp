#include <iostream>

using namespace std;

int scoreBoard[200][3];

int main() {
	int N;
	cin >> N;

	// 각 플레이어의 각 게임 점수 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> scoreBoard[i][j];

	for (int player = 0; player < N; player++) {
		int score = 0;

		// 각 게임마다 해당 플레이어의 점수를 계산한다.
		for (int game = 0; game < 3; game++) {
			int cnt = 0;

			for (int otherPlayer = 0; otherPlayer < N; otherPlayer++) {
				if (player == otherPlayer)
					continue;

				// 점수가 같은 것이 발견되면
				if (scoreBoard[otherPlayer][game] == scoreBoard[player][game])
					cnt++;
			}

			// 유니크한 경우에만 점수에 더해준다.
			if (cnt == 0)
				score += scoreBoard[player][game];
		}

		cout << score << '\n';
	}

	return 0;
}