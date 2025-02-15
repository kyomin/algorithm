#include <iostream>
#include <string>
using namespace std;

bool visited[50][50];
string map[50];
int N, M;

void bfs(int r, int c) {
	char shape = map[r][c];

	if (shape == '|') {
		for (int i = r; i < N; i++) {
			if (visited[i][c])
				break;

			if (map[i][c] == '|') {
				visited[i][c] = true;
			}
			else {
				break;
			}
		}
	}
	else {
		for (int i = c; i < M; i++) {
			if (visited[r][i])
				break;

			if (map[r][i] == '-') {
				visited[r][i] = true;
			}
			else {
				break;
			}
		}
	}
}

int main() {
	int ans = 0;
	cin >> N >> M;

	for (int row = 0; row < N; row++)
		cin >> map[row];

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (visited[row][col])
				continue;

			ans++;

			bfs(row, col);
		}
	}

	cout << ans << endl;

	return 0;
}