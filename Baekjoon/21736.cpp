#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int R, C;
bool visited[600][600];

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };

bool isInside(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C)
		return false;

	return true;
}

int main() {
	cin >> R >> C;

	int count = 0;
	vector<string> map(R);

	for (int r = 0; r < R; r++)
		cin >> map[r];

	queue<pair<int, int>> q;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] == 'I') {
				q.push(make_pair(r, c));
				visited[r][c] = true;
				break;
			}
		}
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (map[r][c] == 'P')
			count++;

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc))
				continue;

			if (visited[nr][nc])
				continue;

			if (map[nr][nc] == 'X')
				continue;

			visited[nr][nc] = true;

			q.push(make_pair(nr, nc));
		}
	}

	if (count > 0)
		cout << count << endl;
	else
		cout << "TT" << endl;

	return 0;
}