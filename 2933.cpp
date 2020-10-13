#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char a[100][100];
bool c[100][100];
int n, m;

// 미네랄 그룹의 좌표를 담는다.
vector<pair<int, int>> group;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	// 빈칸이므로 탐색을 더 진행하면 안 된다.
	if (a[x][y] == '.')
		return;
	if (c[x][y])	// 작업이 이뤄진 곳은 더 방문 x
		return;

	// 방문했다고 체크!
	c[x][y] = true;

	// 현재 미네랄 그룹의 좌표를 차곡차곡 쌓는다.
	group.push_back(make_pair(x, y));

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < n && 0 <= ny && ny < m)
			dfs(nx, ny);
	}
}

void simulate() {
	memset(c, false, sizeof(c));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 탐색 대상이 아니다
			if (a[i][j] == '.')
				continue;
			if (c[i][j])
				continue;

			group.clear();
			// 탐색을 시작
			dfs(i, j);

			/*
				탐색을 다 돌고 나면
				그룹이 형성됐을 것이다.
			*/
			vector<int> low(m, -1);

			for (auto &p : group) {
				// 각 열에 대해 가장 낮은 부분의 행 추출
				low[p.second] = max(low[p.second], p.first);

				// 미네랄 집단을 이동시킬 것이므로 빈칸 만들기
				a[p.first][p.second] = '.';
			}

			/*
				해당 클러스터가 떨어지면 가장 가깝게 맞닿는 거리
				클러스터의 한 부분이라도 정착하면 종료된다.
			*/
			int lowest = n;

			for (int i, j = 0; j < m; j++) {
				// 클러스터에 포함된 열이 아니면 작업 x
				if (low[j] == -1)
					continue;

				// 무언가에 닿을 때까지 계속 증가시킨다.
				for (i = low[j]; i < n&&a[i][j] == '.'; i++);

				// for문을 빠져 나오면 끝에 도달했거나, 무언가에 닿았단 소리이므로
				// lowest 갱신
				lowest = min(lowest, i - 1 - low[j]);
			}

			// 미네랄 클러스터를 순회한다.
			for (auto &p : group) {
				// 이동을 시킨다.
				p.first += lowest;

				a[p.first][p.second] = 'x';
				c[p.first][p.second] = true;
			}

		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
		
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int height;
		cin >> height;

		height = n - height;

		// 오른쪽으로 쏘았을 때
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				if (a[height][j] == 'x') {
					// 미네랄 깨 부수기
					a[height][j] = '.';
					break;
				}
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				if (a[height][j] == 'x') {
					a[height][j] = '.';
					break;
				}
			}
		}

		simulate();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j];

		cout << '\n';
	}

	cout << '\n';

	return 0;
}