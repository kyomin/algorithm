#include <iostream>
#include <cstring>
using namespace std;

const int R = 19;
const int C = 19;
int map[R][C];

bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;

	return false;
}

int findUpVertical(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findUpVertical(turn, r - 1, c);
}

int findDownVertical(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findDownVertical(turn, r + 1, c);
}

int findLeftWidth(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findLeftWidth(turn, r, c - 1);
}

int findRightWidth(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findRightWidth(turn, r, c + 1);
}

int findLeftUpDiagonal(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findLeftUpDiagonal(turn, r - 1, c - 1);
}

int findRightDownDiagonal(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findRightDownDiagonal(turn, r + 1, c + 1);
}

int findRightUpDiagonal(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findRightUpDiagonal(turn, r - 1, c + 1);
}

int findLeftDownDiagonal(char turn, int r, int c) {
	if (!isInside(r, c) || turn != map[r][c])
		return 0;

	return 1 + findLeftDownDiagonal(turn, r + 1, c - 1);
}

int main() {
	int ans = 0;
	int ansR = 0; 
	int ansC = 0;
	
	// 바둑판 상태 입력
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> map[r][c];

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			int turn = map[r][c];

			if (turn == 0)
				continue;
			
			int vertical = findUpVertical(turn, r, c) + findDownVertical(turn, r, c) - 1;
			int width = findLeftWidth(turn, r, c) + findRightWidth(turn, r, c) - 1;
			int leftVertical = findLeftUpDiagonal(turn, r, c) + findRightDownDiagonal(turn, r, c) - 1;
			int rightVertical = findRightUpDiagonal(turn, r, c) + findLeftDownDiagonal(turn, r, c) - 1;

			if (vertical == 5 || width == 5 || leftVertical == 5 || rightVertical == 5) {
				ans = turn;

				if (!ansR && !ansC) {
					ansR = r + 1;
					ansC = c + 1;
					break;
				}

				if (!ansC || (ansC && ansC > c + 1)) {
					ansR = r + 1;
					ansC = c + 1;
				}					
			}
		}
	}

	cout << ans << endl;

	if (ans)
		cout << ansR << ' ' << ansC << endl;

	return 0;
}