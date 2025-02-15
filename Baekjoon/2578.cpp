#include <iostream>

using namespace std;

int board[6][6];
bool check[6][6];

int bingo(int y, int x, int dirY, int dirX) {
	// 범위를 넘어간 경우
	if ((x + dirX) < 0 || (x + dirX) > 5 || (y + dirY) < 0 || (y + dirY) > 5)
		return 0;
	
	if (!check[y + dirY][x + dirX])
		return 0 + bingo(y + dirY, x + dirX, dirY, dirX);

	return 1 + bingo(y + dirY, x + dirX, dirY, dirX);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int y = 1; y <= 5; y++)
		for (int x = 1; x <= 5; x++)
			cin >> board[y][x];

	int cnt = 0;

	for (int k = 1; k <= 25; k++) {
		int n; 
		cin >> n;

		bool found = false;

		for (int y = 1; y <= 5; y++) {
			if (found)
				break;

			for (int x = 1; x <= 5; x++) {
				if (found)
					break;

				if (board[y][x] == n) {
					check[y][x] = true;
					found = true;

					int width = 1 + bingo(y, x, 0, -1) + bingo(y, x, 0, 1);
					int heigh = 1 + bingo(y, x, -1, 0) + bingo(y, x, 1, 0);
					int diagonal = 1 + bingo(y, x, 1, -1) + bingo(y, x, -1, 1);
					
					if (width == 5)
						cnt++;
						
					if (heigh == 5) 
						cnt++;

					if (diagonal == 5) 
						cnt++;
					
					if (cnt >= 3) {
						cout << k << '\n';
						return 0;
					}
				}
			}
		}
	}

	return 0;
}