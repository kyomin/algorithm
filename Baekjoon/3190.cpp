#include <iostream>

using namespace std;

int D[100][100];
bool apple[100][100];

// 0 : 북, 1 : 동, 2 : 남, 3 : 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, K, L;

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			D[i][j] = -1;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;

		apple[x - 1][y - 1] = true;
	}

	int x = 0, y = 0;	// 처음 좌표
	int dir = 1;	// 처음엔 동쪽으로
	int len = 1;	// 첫 몸 길이는 1
	D[x][y] = 0;
	int now = 0;

	cin >> L;

	for (int k = 0; k <= L; k++) {
		// 머리가 방문할 수 있는 최대 칸의 개수이다.
		// 명령을 다 기입하고서도 게임이 안 끝났으면 이 상황에서 진행시키면
		// 항상 게임이 끝날 것이다.
		int t = N * N + 1;
		char ch;

		// 아직 명령을 기입할 수 있다면
		if (k < L)
			cin >> t >> ch;

		while (now < t) {
			now += 1;
			// 현재 향하는 방향으로 간다.
			x += dx[dir];
			y += dy[dir];

			// 범위 밖이라면!
			if (x < 0 || x >= N || y < 0 || y >= N) {
				cout << now << '\n';
				return 0;
			}

			// 머리를 옮긴 곳에 사과가 있다면
			if (apple[x][y]) {
				apple[x][y] = false;
				len += 1;
			}

			// 자기 몸과 충돌이 일어난다면
			if (D[x][y] != -1 && now - D[x][y] <= len) {
				cout << now << '\n';
				return 0;
			}

			D[x][y] = now;
		}

		if (ch == 'L')
			if (dir == 0)
				dir = 3;
			else
				dir -= 1;
		else
			if (dir == 3)
				dir = 0;
			else
				dir += 1;
	}

	return 0;
}