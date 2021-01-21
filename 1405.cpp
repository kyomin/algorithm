#include <iostream>

using namespace std;

const int MAX = 29;		// N이 최대 14이므로
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int N;
double percent[4];
bool visit[MAX][MAX];

double dfs(int r, int c, int cnt) {
	// N번 만큼 이동 완료한 경우 1을 return함으로써 확률 곱셈을 종결한다.
	if (cnt == N)
		return 1.0;

	visit[r][c] = true;
	double result = 0.0;

	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		// 방문한 곳을 다시 가게 되면 이동경로가 단순하지 않은 것이다.
		if (visit[nr][nc])
			continue;

		result += percent[k] * dfs(nr, nc, cnt + 1);
	}

	// 깊이 탐색 완료 후, 다른 방향으로 갈 수 있게 다시 방문 체크를 해제해 준다.
	visit[r][c] = false;

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;

		percent[i] = (a / 100.0);
	}

	// N이 최대 14인 것을 고려해 중간부터 로봇을 놓고 시작한다.
	double probability = dfs(14, 14, 0);

	cout.precision(10);
	cout << fixed << probability << '\n';

	return 0;
}