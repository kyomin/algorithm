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
				visit[r][c] = -1;	// ġ�� ��ġ�� -1�� ǥ��
		}
	}
}

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < M)
		return true;

	return false;
}

/*
	�ܺ� ����� ���� ���⸦ �и��ϴ� �۾�

	0 : ���� ����
	1 : �ܺ� ����
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
	�ܺ� ���� �߿�����,
	ġ��� ������ ����� �׷��� ���� ���⸦ �и��ϴ� �۾�.
	
	ġ��� ������ ����� 'nq'�� ������ �ȴ�.
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
	ġ� ���̴� ����.

	1. nq�� ������ �����ϰ� nq�� ����ش�.
	2. ġ� �ִ� ��ǥ�� ġ� �쿩�ְ�, �ش� ġ���� ��ǥ�� nq�� �־��ش�.
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
	���� ����� �ܺ� ���⸦ ��ġ�� ����.
	���� ġ��� ������ �ܺΰ���� nq�� ������ �Ǿ� �����Ƿ�
	�� ������� ��ǥ��κ��� BFS Ž�� �ǽ�.

	����, ���� ���⸦ ������ �Ǹ� 
	�� ���� ���� ���� �ܺ� ����� ���� ������ �� �� �����Ƿ�
	�� ����� ���� nq�� ����
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

// ġ� �� ��Ҵ��� üũ!
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