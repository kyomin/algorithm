#include <iostream>
#include <queue>
#include <string>

using namespace std;

string a[100];
bool check[100][100];	// 방문 표시용
int N;	// 그리드의 크기

// 상하좌우 탐색 범위
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 행, 열, 탐색 시작 점의 색
void BFS(int x, int y, char color) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	check[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (a[nx][ny] == color && check[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;

	// 일반 사람이 보는 영역의 개수
	int cnt1 = 0;

	// 적록색약이 보는 영역의 개수
	int cnt2 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {
				BFS(i, j, a[i][j]);
				cnt1 += 1;
			}
		}
	}

	/* 일반사람의 영역 계산이 끝났으면 적록색약 계산을 시작한다. */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 녹색 -> 적색
			if (a[i][j] == 'G')
				a[i][j] = 'R';

			// check 배열도 함께 초기화
			check[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {
				BFS(i, j, a[i][j]);
				cnt2 += 1;
			}
		}
	}

	cout << cnt1 << ' ' << cnt2 << endl;

	return 0;
}