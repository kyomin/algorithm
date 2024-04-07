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
				// 빈공간이라면 블록을 떨어뜨릴 수 있는 공간인지 확인하기
				if (!canFill(r, c)) return false;

				// 각 블록은 2개까지 채워서 없앨 수 있으므로
				if (++emptyCnt > 2) return false;
			}
			else {
				if (lastValue != -1 && lastValue != Board[r][c]) return false;

				lastValue = Board[r][c];
			}
		}
	}

	// 직사각형으로 만들 수 있는 블록을 찾은 경우이며 지워주는 작업을 진행한다
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
				// 가로 직사각형 판단하기
				if (r <= N - 2 && c <= N - 3 && find(r, c, 2, 3)) {
					cnt++;
				}
				// 세로 직사각형 판단하기
				else if (r <= N - 3 && c <= N - 2 && find(r, c, 3, 2)) {
					cnt++;
				}
			}
		}

		answer += cnt;
	} while (cnt);

	return answer;
}