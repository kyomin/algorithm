#include <iostream>

using namespace std;

bool map[100][100];

int curDir = 0;
int totalRoom;
int visitedRoom = 0;
int cnt = 0;	// 방향을 바꾼 횟수

int M, N;

// 우, 하, 좌, 상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	// 현재 방문했다 체크
	visitedRoom += 1;
	map[y][x] = true;

	// 끝에 도달했다면
	if (visitedRoom == totalRoom)
		return;

	int nx = x + dx[curDir];
	int ny = y + dy[curDir];

	// 현재 나아가는 방향으로 이동할 수 있는 칸이라면
	if (0 <= nx && nx < N && 0 <= ny && ny < M && !map[ny][nx]) {
		// 앞으로 나아가고
		dfs(ny, nx);	
	} else {	
		// 아니라면 방향 바꾼 후 새로 셋팅
		curDir = (curDir + 1) % 4;
		cnt++;

		nx = x + dx[curDir];
		ny = y + dy[curDir];

		dfs(ny, nx);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	totalRoom = M * N;

	dfs(0, 0);

	cout << cnt << '\n';

	return 0;
}