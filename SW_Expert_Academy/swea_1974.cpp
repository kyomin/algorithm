#include <iostream>
#include <cstring>

using namespace std;

int map[9][9];
bool check[10];

bool solution() {
	// 가로 줄 검사
	for (int r = 0; r < 9; r++) {
		memset(check, false, sizeof(check));

		for (int c = 0; c < 9; c++) {
			int n = map[r][c];

			// 중복으로 숫자가 등장한 순간
			if (check[n])
				return false;

			check[n] = true;
		}
	}

	// 세로 줄 검사
	for (int c = 0; c < 9; c++) {
		memset(check, false, sizeof(check));

		for (int r = 0; r < 9; r++) {
			int n = map[r][c];

			// 중복으로 숫자가 등장한 순간
			if (check[n])
				return false;

			check[n] = true;
		}
	}
	
	// 9개의 3x3 검사
	for (int row_boundary = 3; row_boundary <= 9; row_boundary += 3) {
		for (int col_boundary = 3; col_boundary <= 9; col_boundary += 3) {
			memset(check, false, sizeof(check));

			for (int r = row_boundary - 3; r < row_boundary; r++) {
				for (int c = col_boundary - 3; c < col_boundary; c++) {
					int n = map[r][c];

					// 중복으로 숫자가 등장한 순간
					if (check[n])
						return false;

					check[n] = true;
				}
			}
		}
	}

	return true;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		for (int r = 0; r < 9; r++)
			for (int c = 0; c < 9; c++)
				cin >> map[r][c];

		if (solution())
			cout << '#' << t << ' ' << 1 << '\n';
		else
			cout << '#' << t << ' ' << 0 << '\n';
	}

	return 0;
}