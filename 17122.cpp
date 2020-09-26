#include <iostream>
#include <string>

using namespace std;

char board[8][8];
char colors[65];	// 칸의 번호와 대응되는 색깔
int cnt;

int T;

int main() {
	cnt = 1;

	for (int y = 7; y >= 0; y--) {
		// 각 행의 첫 칸 초기화
		if (y == 7) {
			board[y][0] = 'B';
			colors[cnt] = 'B';
			cnt++;
		} else {
			if (board[y + 1][0] == 'B') {
				board[y][0] = 'W';
				colors[cnt] = 'W';
				cnt++;
			} else {
				board[y][0] = 'B';
				colors[cnt] = 'B';
				cnt++;
			}
		}

		for (int x = 1; x < 8; x++) {
			if (board[y][x - 1] == 'B') {
				board[y][x] = 'W';
				colors[cnt] = 'W';
				cnt++;
			} else {
				board[y][x] = 'B';
				colors[cnt] = 'B';
				cnt++;
			}
		}
	}

	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		int num;

		cin >> str >> num;

		int x = (int)(str[0] - 'A');
		int y = 8 - (int)(str[1] - '0');

		char c1 = board[y][x];

		char c2 = colors[num];

		if (c1 == c2) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}