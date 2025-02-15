#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[301][301];
int copy_map[301][301];
int N, M, R;

// map -> copy_map으로 복사
void mapToCopy() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			copy_map[i][j] = map[i][j];
}

// copy_map -> map으로 복사
void copyToMap() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			map[i][j] = copy_map[i][j];
}

// 윗쪽 라인 이동
void moveTop(int top, int left, int right) {
	for (int start = left; start < right; start++)
		copy_map[top][start] = map[top][start + 1];
}

// 오른쪽 라인 이동
void moveRight(int top, int bottom, int right) {
	for (int start = top; start < bottom; start++)
		copy_map[start][right] = map[start + 1][right];
}

// 아래쪽 라인 이동
void moveBottom(int bottom, int left, int right) {
	for (int start = right; start > left; start--)
		copy_map[bottom][start] = map[bottom][start - 1];
}

// 왼쪽 라인 이동
void moveLeft(int top, int bottom, int left) {
	for (int start = bottom; start > top; start--)
		copy_map[start][left] = map[start - 1][left];
}

void rotate(int top, int bottom, int left, int right) {
	mapToCopy();

	while (top < bottom && left < right) {
		moveTop(top, left, right);
		moveRight(top, bottom, right);
		moveBottom(bottom, left, right);
		moveLeft(top, bottom, left);

		top += 1;
		bottom -= 1;
		left += 1;
		right -= 1;
	}

	copyToMap();
}

int main() {
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	for (int r = 0; r < R; r++) {
		int top = 1;
		int bottom = N;
		int left = 1;
		int right = M;

		rotate(top, bottom, left, right);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cout << map[i][j]<< ' ';

		cout << '\n';
	}

	return 0;
}