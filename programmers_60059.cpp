#include <string>
#include <vector>

using namespace std;

int keySize, lockSize, boardSize;

// key를 시계 방향으로 90도 회전
// 실제 외부의 key를 회전 시켜야 하므로 참조자로 받는다.
void rotateKey(vector<vector<int>> &key) {
	// 2차원 임시 벡터 생성
	vector<vector<int>> tmp(keySize, vector<int>(keySize));

	// 시계 방향 90도 회전!
	for (int col = keySize - 1; col >= 0; col--)
		for (int row = 0; row < keySize; row++)
			tmp[row][col] = key[keySize - col - 1][row];

	key = tmp;
}

bool putKey(int startRow, int startCol, vector<vector<int>> key, vector<vector<int>> board) {
	int lockStart = keySize - 1;
	int lockEnd = boardSize - keySize;

	// (startRow, startCol)을 시작점으로 열쇠를 자물쇠에 맞춰본다.
	int endRow = startRow + keySize;
	int endCol = startCol + keySize;

	// board에 key를 더한다.
	for (int row = startRow; row < endRow; row++)
		for (int col = startCol; col < endCol; col++)
			board[row][col] += key[row - startRow][col - startCol];

	// 자물쇠 부분 확인
	for (int row = lockStart; row <= lockEnd; row++) {
		for (int col = lockStart; col <= lockEnd; col++) {
			if (board[row][col] == 1)
				continue;

			// 1이 아니라면 열쇠와 매칭되지 않는다는 소리이므로
			return false;
		}
	}

	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	keySize = key.size();
	lockSize = lock.size();
	boardSize = lockSize + (keySize - 1) * 2;
	vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

	/*
		lock은 고정되어 있고, key를 움직일 것이므로
		board에 lock을 미리 더해 놓는다.
	*/
	for (int row = keySize - 1; row <= boardSize - keySize; row++)
		for (int col = keySize - 1; col <= boardSize - keySize; col++)
			board[row][col] = lock[row - keySize + 1][col - keySize + 1];

	// 회전 방향 4번
	for (int r = 0; r < 4; r++) {
		for (int row = 0; row <= boardSize - keySize; row++) {
			for (int col = 0; col <= boardSize - keySize; col++) {
				// (row, col)을 key의 시작 칸으로 자물쇠 홈에 맞춰본다.
				if (putKey(row, col, key, board)) {
					answer = true;
					return answer;
				}
			}
		}

		// 시계 방향으로 key를 90도 회전
		rotateKey(key);
	}

	return answer;
}