#include <iostream>
using namespace std;

int arrB[610][610];
int map[610][610];
int H, W, X, Y;

int main() {
	cin >> H >> W >> X >> Y;
	int rowB = H + X;
	int colB = W + Y;

	for (int i = 0; i < rowB; i++) {
		for (int j = 0; j < colB; j++) {
			cin >> arrB[i][j];
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			map[i][j] = arrB[i][j];
		}
	}

	for (int row = X; row <= rowB; row++) {
		bool chk = false;
		for (int col = Y; col <= colB; col++) {
			if (map[row][col] != 0) {
				map[row][col] -= map[row - X][col - Y];
				chk = true;
			}
		}

		if (!chk) break;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}