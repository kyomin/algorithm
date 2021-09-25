#include <iostream>

using namespace std;

int board[3][3];

int main() {
	bool win = false;
	int turn;
	cin >> turn;

	for (int i = 0; i < 9; i++) {
		int row, col;
		cin >> row >> col;

		row -= 1;
		col -= 1;

		board[row][col] = turn;

		if (board[row][0] == turn && board[row][1] == turn && board[row][2] == turn) {
			win = true;
		}
		if (board[0][col] == turn && board[1][col] == turn && board[2][col] == turn) {
			win = true;
		}
		if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
			win = true;
		}
		if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
			win = true;
		}

		if (win)
			break;

		turn = turn == 1 ? 2 : 1;
	}

	if (win)
		cout << turn << endl;
	else
		cout << 0 << endl;

	return 0;
}