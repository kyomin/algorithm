#include <string>
#include <vector>
using namespace std;

vector<vector<int>> Board;
int N;

bool canFill(int row, int col) {
	for (int r = 0; r < row; r++) 
		if (Board[r][col] != 0) return false;
	
	return true;
}

bool find(int row, int col, int h, int w) {
	int emptyCnt = 0;
	int lastValue = -1;

	for (int r = row; r < row + h; r++) {
		for (int c = col; c < col + w; c++) {
			if (Board[r][c] == 0) {
				// ������̶�� ����� ����߸� �� �ִ� �������� Ȯ���ϱ�
				if (!canFill(r, c)) return false;

				// �� ����� 2������ ä���� ���� �� �����Ƿ�
				if (++emptyCnt > 2) return false;
			}
			else {
				if (lastValue != -1 && lastValue != Board[r][c]) return false;

				lastValue = Board[r][c];
			}
		}
	}

	// ���簢������ ���� �� �ִ� ����� ã�� ����̸� �����ִ� �۾��� �����Ѵ�
	for (int r = row; r < row + h; r++)
		for (int c = col; c < col + w; c++)
			Board[r][c] = 0;

	return true;
}

int solution(vector<vector<int>> board) {
	Board = board;
	N = board.size();

	int answer = 0;
	int cnt;
	do {
		cnt = 0;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				// ���� ���簢�� �Ǵ��ϱ�
				if (r <= N - 2 && c <= N - 3 && find(r, c, 2, 3)) {
					cnt++;
				}
				// ���� ���簢�� �Ǵ��ϱ�
				else if (r <= N - 3 && c <= N - 2 && find(r, c, 3, 2)) {
					cnt++;
				}
			}
		}

		answer += cnt;
	} while (cnt);

	return answer;
}