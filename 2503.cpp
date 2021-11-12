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
		// 중복된 숫자가 있는 것들은 거른다.
		string num = to_string(i);
		if (num[0] == num[1] || num[1] == num[2] || num[0] == num[2])
			canNumber[i] = false;

		// 0이 들어간 숫자도 거른다.
		if (num[0] == '0' || num[1] == '0' || num[2] == '0')
			canNumber[i] = false;
	}

	// 입력
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

	// 솔루션
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
						// 스트라이크 조건 만족
						if (a == b && numStr[a] == temp[b])
							tempStrike++;

						// 볼 조건 만족
						if (a != b && numStr[a] == temp[b])
							tempBall++;
					}
				}

				// 주어진 게임의 조건을 만족하지 않는 수는 제외
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