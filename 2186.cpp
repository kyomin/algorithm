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
	DP[a][b][c] : (a, b)�� �����ϴ� ���ĺ���
	ã���� �ϴ� ���ڿ��� 'c'�� �ε����� �������� ��,
	���� �� �ִ� ������ ������ ��Ÿ����.
*/
int dp[MAX][MAX][80];	


// ���� ���� �������� �Ǵ��ϴ� �Լ�
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

	// dp[][][] == -1�̸� ���� �湮���� ���� ���̹Ƿ� Ž�� ����̴�.
	memset(dp, -1, sizeof(dp));
}

// idx : ���� ���ڿ� �ε��� ���
int dfs(int row, int col, int idx) {
	// �̹� �湮�� ���̶��
	if (dp[row][col][idx] != -1)
		return dp[row][col][idx];

	/*
		���ݱ��� �����߰�, ���ڿ� ���̸� �Ѿ �ε������
		target ���ڿ��� �� �� ���� ��Ȳ�̴�.
	*/
	if (idx >= targetLen)
		return 1;

	// �� �� �湮�� ���̹Ƿ� -1 => 0���� üũ!
	dp[row][col][idx] = 0;

	// �� �� �� �� Ž��
	for (int i = 0; i < 4; i++) {
		// �ִ� K���� ĭ���� �̵���Ű��
		for (int k = 1; k <= K; k++) {
			int nr = row + (dr[i] * k);
			int nc = col + (dc[i] * k);

			// ������ ����� ���
			if (!isInside(nr, nc)) continue;

			// ���� ĭ�� ���ڰ� idx�� ��ġ�Ǵ� target�� ���ڰ� �ƴ϶��
			if (map[nr][nc] != target[idx]) continue;

			// ���� ���� ������ �� ���������
			dp[row][col][idx] += dfs(nr, nc, idx + 1);
		}
	}

	// ���� �ڽ��� �޸� �����ؾ� ���������� ��ϵȴ�.
	return dp[row][col][idx];
}

void solution() {
	// ù ���ڰ� Ž�� ���� ����̴�.
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