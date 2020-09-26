#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int INF = 987654321;

string map[100];
int dp[100][100];
int N;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(int y, int x) {
	// 끝에 도달한 경우
	if (y == N - 1 && x == N - 1) {		
		return 0;
	}

	// 메모제이션을 통한 중복 방지
	int &result = dp[y][x];
		
	// 이미 방문된 곳이어서 해답이 메모되었다면
	if (result != -1)
		return result;

	// 방문한 곳이 아니라면
	result = INF;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			result = min(result, (int)(map[ny][nx]-'0') + solution(ny, nx));
		}
	}

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		// 지도 입력
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}

		memset(dp, -1, sizeof(dp));

		cout << '#' << t << ' ' << solution(0, 0) << endl;
	}

	return 0;
}