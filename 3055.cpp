#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
int dist[50][50];

int dc[4] = { 1, 0, -1, 0 };
int dr[4] = { 0, 1, 0, -1 };

int R, C;

int main() {
	int targetR, targetC;
	cin >> R >> C;

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> map[r][c];

	queue<pair<int, int>> q;

	// 먼저 물이 있는 곳부터 넣는다. => 그래야 다음에 고슴도치가 이동할 수 있는지 없는지 판단 가능
	for (int r = 0; r < R; r++) 
		for (int c = 0; c < C; c++) 
			if (map[r][c] == '*')
				q.push(make_pair(r, c));

	// 고슴도치의 위치를 넣는다.
	for (int r = 0; r < R; r++) 
		for (int c = 0; c < C; c++)
			if (map[r][c] == 'S')
				q.push(make_pair(r, c));

	// 굴의 위치를 찾는다.
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			if (map[r][c] == 'D')
				targetR = r, targetC = c;

	// BFS
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 범위 내에 있고
			if (0 <= nr && nr < R && 0 <= nc && nc < C) {
				if (map[r][c] == '*') {	// 현재 내가 물이고
					if (map[nr][nc] == '.') {	// 다음 위치가 빈 칸이라면
						map[nr][nc] = '*';	// 물로 채우기
						q.push(make_pair(nr, nc));
					}
				}
				else {	// 현재 고슴도치이고
					if (map[nr][nc] == '.') {	// 다음 위치가 빈 칸이라면
						map[nr][nc] = 'S';	// 물로 채우기
						dist[nr][nc] = dist[r][c] + 1;
						q.push(make_pair(nr, nc));
					}
					else if (map[nr][nc] == 'D') {
						dist[nr][nc] = dist[r][c] + 1;
					}
				}
			}
		}
	}

	if (dist[targetR][targetC] == 0)
		cout << "KAKTUS" << endl;
	else
		cout << dist[targetR][targetC] << endl;

	return 0;
}