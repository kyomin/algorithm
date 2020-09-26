#include <iostream>
#include <set>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int board[5][5];
set<string> results;

void dfs(int y, int x, string str) {
	if (str.size() == 6) {
		results.insert(str);
		return;
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
			string nextStr = str + to_string(board[ny][nx]);
			dfs(ny, nx, nextStr);
		}
	}
}

int main() {
	// 숫자판 입력
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			cin >> board[y][x];

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			dfs(y, x, to_string(board[y][x]));
		}
	}

	cout << results.size() << '\n';

	return 0;
}