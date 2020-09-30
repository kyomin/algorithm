#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 100;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };
int R, C, K, answer = 0;
char map[MAX][MAX];
string target;
int targetLen;

/*
	DP[a][b][c] : (a, b)에 존재하는 알파벳을
	찾고자 하는 문자열의 'c'번 인덱스로 설정했을 때,
	나올 수 있는 정답의 개수를 나타낸다.
*/
int dp[MAX][MAX][80];	


// 지도 범위 내인지를 판단하는 함수
bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;

	return false;
}

void input() {
	cin >> R >> C >> K;

	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			cin >> map[row][col];

	cin >> target;
	targetLen = target.size();

	// dp[][][] == -1이면 아직 방문하지 않은 것이므로 탐색 대상이다.
	memset(dp, -1, sizeof(dp));
}

// idx : 다음 문자열 인덱스 대상
int dfs(int row, int col, int idx) {
	// 이미 방문된 곳이라면
	if (dp[row][col][idx] != -1)
		return dp[row][col][idx];

	/*
		지금까지 진행했고, 문자열 길이를 넘어선 인덱스라면
		target 문자열을 한 번 만든 상황이다.
	*/
	if (idx >= targetLen)
		return 1;

	// 한 번 방문한 것이므로 -1 => 0으로 체크!
	dp[row][col][idx] = 0;

	// 상 하 좌 우 탐색
	for (int i = 0; i < 4; i++) {
		// 최대 K개의 칸까지 이동시키기
		for (int k = 1; k <= K; k++) {
			int nr = row + (dr[i] * k);
			int nc = col + (dc[i] * k);

			// 범위를 벗어나는 경우
			if (!isInside(nr, nc)) continue;

			// 다음 칸의 문자가 idx와 매치되는 target의 문자가 아니라면
			if (map[nr][nc] != target[idx]) continue;

			// 위의 검증 과정을 다 통과했으면
			dp[row][col][idx] += dfs(nr, nc, idx + 1);
		}
	}

	// 현재 자신의 메모를 리턴해야 연쇄적으로 기록된다.
	return dp[row][col][idx];
}

void solution() {
	// 첫 문자가 탐색 시작 대상이다.
	char start = target[0];

	for (int row = 0; row < R; row++) 
		for (int col = 0; col < C; col++) 
			if (map[row][col] == start)
				answer += dfs(row, col, 1);
		
	cout << answer << endl;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solution();

	return 0;
}