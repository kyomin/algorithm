#include <iostream>
#include <cstring>
using namespace std;

const int R = 19;
const int C = 19;
char map[R][C];

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
	memset(map, '.', sizeof(map));
	int ans = -1;
	int N; 
	cin >> N;

	for (int i = 1; i < N; i++) {
		char turn;
		if (i % 2 == 1)
			turn = 'B';
		else
			turn = 'W';

		int r, c;
		cin >> r >> c;

		r -= 1;
		c -= 1;
		map[r][c] = turn;
		
		int vertical = findUpVertical(turn, r, c) + findDownVertical(turn, r, c) - 1;
		int width = findLeftWidth(turn, r, c) + findRightWidth(turn, r, c) - 1;
		int leftVertical = findLeftUpDiagonal(turn, r, c) + findRightDownDiagonal(turn, r, c) - 1;
		int rightVertical = findRightUpDiagonal(turn, r, c) + findLeftDownDiagonal(turn, r, c) - 1;
	
		if (vertical == 5 || width == 5 || leftVertical == 5 || rightVertical == 5) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}