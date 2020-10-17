#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int N, M;
int map[MAX][MAX];
int visit[MAX][MAX];

vector<pair<int, int>> air;
queue<pair<int, int>> nq;

void input() {
	cin >> N >> M;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];

			if (map[r][c] == 1)
				visit[r][c] = -1;	// 치즈 위치는 -1로 표시
		}
	}
}

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < M)
		return true;

	return false;
}

/*
	외부 공기와 내부 공기를 분리하는 작업

	0 : 내부 공기
	1 : 외부 공기
*/
void makeFirstAirState() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visit[0][0] = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc)) continue;

			if (map[nr][nc] == 0 && visit[nr][nc] == 0) {
				visit[nr][nc] = 1;
				q.push(make_pair(nr, nc));
			}
		}
	}
}

/*
	외부 공기 중에서도,
	치즈와 인접한 공기와 그렇지 않은 공기를 분리하는 작업.
	
	치즈와 인접한 공기는 'nq'에 저장이 된다.
*/
void divideAir() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (visit[r][c] == 1) {
				for (int k = 0; k < 4; k++) {
					int nr = r + dr[k];
					int nc = c + dc[k];

					if (!isInside(nr, nc)) continue;

					if (map[nr][nc] == 1) {
						nq.push(make_pair(r, c));
						break;
					}
				}
			}
		}
	}
}

/*
	치즈를 녹이는 과정.

	1. nq에 값들을 복사하고 nq를 비워준다.
	2. 치즈가 있는 좌표는 치즈를 녹여주고, 해당 치즈의 좌표를 nq에 넣어준다.
*/
void meltCheese() {
	queue<pair<int, int>> q = nq;
	while (!nq.empty()) nq.pop();

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc)) continue;

			if (map[nr][nc] == 1) {
				map[nr][nc] = 0;
				nq.push(make_pair(nr, nc));
			}
		}
	}
}

/*
	내부 공기와 외부 공기를 합치는 과정.
	현재 치즈와 인접한 외부공기는 nq에 저장이 되어 있으므로
	이 공기들의 좌표들로부터 BFS 탐색 실시.

	만약, 내부 공기를 만나게 되면 
	그 내부 공기 또한 외부 공기와 같은 역할을 할 수 있으므로
	그 공기들 또한 nq에 저장
*/
void mergeAir() {
	queue<pair<int, int>> q = nq;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc)) continue;

			if (visit[nr][nc] == 0) {
				visit[nr][nc] = 1;
				q.push(make_pair(nr, nc));
				nq.push(make_pair(nr, nc));
			}
		}
	}
}

// 치즈가 다 녹았는지 체크!
bool check() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			if (map[r][c] == 1)
				return false;

	return true;
}

void solution() {
	makeFirstAirState();
	divideAir();

	int time = 0;
	int final_size = 0;

	while (true) {
		if (check()) break;

		meltCheese();
		final_size = nq.size();
		mergeAir();
		time++;
	}

	cout << time << '\n' << final_size << '\n';
}

void solve() {
	input();
	solution();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	solve();

	return 0;
}