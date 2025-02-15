#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef struct {
	int number;
	int strike;
	int ball;
} Game;

int N;
bool canNumber[1000];	// 123 ~ 999
vector<Game> games;

int main() {
	memset(canNumber, true, sizeof(canNumber));
	for (int i = 123; i <= 999; i++) {
		// �ߺ��� ���ڰ� �ִ� �͵��� �Ÿ���.
		string num = to_string(i);
		if (num[0] == num[1] || num[1] == num[2] || num[0] == num[2])
			canNumber[i] = false;

		// 0�� �� ���ڵ� �Ÿ���.
		if (num[0] == '0' || num[1] == '0' || num[2] == '0')
			canNumber[i] = false;
	}

	// �Է�
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number, strike, ball;
		cin >> number >> strike >> ball;
		Game game;
		game.number = number;
		game.strike = strike;
		game.ball = ball;

		games.push_back(game);
	}

	// �ַ��
	for (int i = 0; i < N; i++) {
		int number = games[i].number;
		int strike = games[i].strike;
		int ball = games[i].ball;
		string numStr = to_string(number);

		for (int j = 123; j <= 999; j++) {
			int tempStrike = 0;
			int tempBall = 0;

			if (canNumber[j]) {
				string temp = to_string(j);
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						// ��Ʈ����ũ ���� ����
						if (a == b && numStr[a] == temp[b])
							tempStrike++;

						// �� ���� ����
						if (a != b && numStr[a] == temp[b])
							tempBall++;
					}
				}

				// �־��� ������ ������ �������� �ʴ� ���� ����
				if (strike != tempStrike || ball != tempBall)
					canNumber[j] = false;
			}
		}
	}

	int ans = 0;
	for (int i = 123; i <= 999; i++)
		if (canNumber[i])
			ans++;

	cout << ans << endl;

	return 0;
}