#include <vector>
#include <queue>

using namespace std;

int a[100][100];	// 영역 표기용
int d[100][100];	// 방문 체크용

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int X, Y;

int bfs(int x, int y, int cnt, int color) {
	int area = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	d[x][y] = cnt;
	area += 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			// 영역 범위 내에 있는가?
			if (0 <= nx && nx < X && ny >= 0 && ny < Y) {
				// 조건을 만족하는가?
				if (a[nx][ny] == color && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
					area += 1;
				}
			}
		}
	}

	return area;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	X = m;	// 행
	Y = n;	// 열

	// 배열 a, d 초기화
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 0;
			a[i][j] = picture[i][j];
		}
	}

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			// 색이 칠해져있고, 아직 방문하지 않았으면
			if (a[i][j] != 0 && d[i][j] == 0) {
				// 탐색 시작!
				int temp_area = bfs(i, j, ++number_of_area, a[i][j]);

				// 최대 넓이 갱신
				if (temp_area > max_size_of_one_area)
					max_size_of_one_area = temp_area;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}