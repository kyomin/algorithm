#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char board[30][30];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(board, '.', sizeof(board));

	string A, B;

	cin >> A >> B;

	int i, j;
	bool found = false;

	int lenA = A.size();
	int lenB = B.size();

	for (int col = 0; col < lenA; col++) {
		if (found)
			break;

		for (int row = 0; row < lenB; row++) {
			if (B[row] == A[col]) {
				i = row;
				j = col;
				found = true;
				break;
			}
		}
	}

	for (int col = 0; col < lenA; col++)
		board[i][col] = A[col];

	for (int row = 0; row < lenB; row++)
		board[row][j] = B[row];

	for (int row = 0; row < lenB; row++) {
		for (int col = 0; col < lenA; col++)
			cout << board[row][col];

		cout << '\n';
	}

	return 0;
}