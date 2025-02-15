#include <string>
#include <vector>

using namespace std;

int keySize, lockSize, boardSize;

// key�� �ð� �������� 90�� ȸ��
// ���� �ܺ��� key�� ȸ�� ���Ѿ� �ϹǷ� �����ڷ� �޴´�.
void rotateKey(vector<vector<int>> &key) {
	// 2���� �ӽ� ���� ����
	vector<vector<int>> tmp(keySize, vector<int>(keySize));

	// �ð� ���� 90�� ȸ��!
	for (int col = keySize - 1; col >= 0; col--)
		for (int row = 0; row < keySize; row++)
			tmp[row][col] = key[keySize - col - 1][row];

	key = tmp;
}

bool putKey(int startRow, int startCol, vector<vector<int>> key, vector<vector<int>> board) {
	int lockStart = keySize - 1;
	int lockEnd = boardSize - keySize;

	// (startRow, startCol)�� ���������� ���踦 �ڹ��迡 ���纻��.
	int endRow = startRow + keySize;
	int endCol = startCol + keySize;

	// board�� key�� ���Ѵ�.
	for (int row = startRow; row < endRow; row++)
		for (int col = startCol; col < endCol; col++)
			board[row][col] += key[row - startRow][col - startCol];

	// �ڹ��� �κ� Ȯ��
	for (int row = lockStart; row <= lockEnd; row++) {
		for (int col = lockStart; col <= lockEnd; col++) {
			if (board[row][col] == 1)
				continue;

			// 1�� �ƴ϶�� ����� ��Ī���� �ʴ´ٴ� �Ҹ��̹Ƿ�
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
		lock�� �����Ǿ� �ְ�, key�� ������ ���̹Ƿ�
		board�� lock�� �̸� ���� ���´�.
	*/
	for (int row = keySize - 1; row <= boardSize - keySize; row++)
		for (int col = keySize - 1; col <= boardSize - keySize; col++)
			board[row][col] = lock[row - keySize + 1][col - keySize + 1];

	// ȸ�� ���� 4��
	for (int r = 0; r < 4; r++) {
		for (int row = 0; row <= boardSize - keySize; row++) {
			for (int col = 0; col <= boardSize - keySize; col++) {
				// (row, col)�� key�� ���� ĭ���� �ڹ��� Ȩ�� ���纻��.
				if (putKey(row, col, key, board)) {
					answer = true;
					return answer;
				}
			}
		}

		// �ð� �������� key�� 90�� ȸ��
		rotateKey(key);
	}

	return answer;
}