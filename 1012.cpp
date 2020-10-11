#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int d[50][50];	// 배추 방문 여부 기입용 행렬
int a[50][50];	// 배추의 위치 기입용 행렬

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 시작 점(x, y) , 배추흰지렁이 번호 cnt, 가로 width, 세로 height
void bfs(int x, int y, int cnt, int width, int height) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));

	// 우선 해당 시작 좌표에 흰지렁이 번호 붙이기.
	d[y][x] = cnt;

	while (!q.empty()) {
		x = q.front().first;	// 가로 축 좌표
		y = q.front().second;	// 세로 축 좌표
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < width && 0 <= ny && ny < height) {
				// 조건을 만족하는가? => 즉, 연결 조건을 만족하는가?
				if (a[ny][nx] == 1 && d[ny][nx] == 0) {
					q.push(make_pair(nx, ny));
					d[ny][nx] = cnt;
				}
			}
		}
	}
}

int main() {
	// 테스트 케이스 개수 입력받기
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		// 흰지렁이의 카운트를 세기 위한 변수
		int cnt = 0;

		// M : 가로, N : 세로, K : 배추의 갯수
		int M, N, K;

		cin >> M >> N >> K;

		// 배열 d와 a의 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				d[i][j] = 0;
				a[i][j] = 0;
			}
		}

		// 배열 a에 배추 위치 기입!
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}

		// 탐색 시작!
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				// 아직 방문하지 않았다면
				if (a[i][j] == 1 && d[i][j] == 0)
					bfs(j, i, ++cnt, M, N);


		// 마지막 배추흰지렁이 번호(총 지렁이 마리) 출력!
		cout << cnt << '\n';
	}

	return 0;
}